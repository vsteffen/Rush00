/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ncurses.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quroulon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 14:11:55 by quroulon          #+#    #+#             */
/*   Updated: 2018/03/31 14:11:56 by quroulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_retro.hpp"

#include "Entity.hpp"
#include "Character.hpp"
#include "Enemy.hpp"

# include <ncurses.h>
# include <string>
# include <unistd.h>
# include <stdio.h>
# include <signal.h>
# include <stdlib.h>
# include "BoardGame.hpp"

#include <fstream>

#define DELAY 25000
#define MIN_WIN_HEIGHT 30
#define MIN_WIN_WIDTH 90

void resizeHandler(int sig) {
	(void)sig;
	endwin();
	exit(0);
}

int			init_colors(void)
{
	start_color();
	init_color(COLOR_YELLOW, 200, 200, 1000);
	init_pair(1, COLOR_WHITE, COLOR_BLACK);
	init_pair(2, COLOR_BLACK, COLOR_BLACK);
	init_pair(3, COLOR_WHITE, COLOR_RED);
	return (0);
}

WINDOW		*init_ncurses(void)
{
	WINDOW		*win;

	initscr();
	init_colors();
	cbreak();
	refresh();
	curs_set(FALSE);
	timeout(0);
	mouseinterval(FALSE);
	win = newwin(0, 0, 0, 0);
	wbkgd(win, COLOR_PAIR(1));
	// nodelay(stdscr, TRUE);
	keypad(stdscr, TRUE);
	noecho();
	return (win);
}

int			handle_key(BoardGame* board, int key, Entity* perso)
{

	if (key == KEY_UP)
		board->moveUp(perso);
	if (key == KEY_DOWN)
		board->moveDown(perso);
	if (key == KEY_LEFT)
		board->moveLeft(perso);
	if (key == KEY_RIGHT)
		board->moveRight(perso);
	if (key == ' ')
		board->shoot(perso);
	// if (key == KEY_DOWN || key == KEY_RIGHT || key == KEY_LEFT || key == KEY_UP) {
	// 	mvprintw(20, 0, "key = ");
	// 	debug_int(20, 6, key);
	// }
	// mvprintw(getmaxy(win) - 2, 0, "key = %d", key);
	// mvprintw(getmaxy(win) - 1, 0, "key = %d", KEY_DOWN);
	return (0);
}

void		print_top(WINDOW *win, BoardGame * board, Entity * perso) {
	std::string		str("");

	str += getmaxy(win);
	mvprintw(0, 0, "SCORE: %d", board->getScore());

	// debug_int(0, 7, board->getScore());

	mvprintw(0, 14, "HP: %d", perso->getHitPoints());


	mvprintw(1, 0, getHSep(getmaxx(win)));
}


int				main ( void ) {
	WINDOW 		*win;
	int			key = 0;

	signal (SIGWINCH, resizeHandler);

	win = init_ncurses();

	int			playerPosY = getmaxy(win) - 1, playerPosX = getmaxx(win) / 2;

	BoardGame *		board = new BoardGame(getmaxy(win), getmaxx(win));
	Entity *		perso = new Character();

	perso->setXPos(playerPosX);
	perso->setYPos(playerPosY);
	board->addEntity(perso);

	// std::ofstream out("log.txt");
    // std::streambuf *coutbuf = std::cout.rdbuf(); //save old buf
    // std::cout.rdbuf(out.rdbuf()); //redirect std::cout to out.txt!

	while (key != 27) {
		mvprintw(getmaxy(win) / 2, (getmaxx(win) / 2) - 35, "Appuyez sur espace pour commencer ou sur échap pour quitter");
		key = getch();

		if (key == ' ') {
			while(key != 27 && key != 10) {
				print_top(win, board, perso);
				board->printBoard();
				key = getch();
				if (perso->getHitPoints() == 0) {
					while (key != 27) {
						mvprintw(getmaxy(win) / 2, (getmaxx(win) / 2) - 17, "Vous etes mort ! Appuyez sur échap.");
						key = getch();
						wrefresh(win);
						usleep(DELAY);
						clear();
					}
					break ;
				}
				if (handle_key(board, key, perso))
					break ;
				board->resolve();
				wrefresh(win);
				usleep(DELAY);
				clear();
			}
		}
		wrefresh(win);
		usleep(DELAY);
		clear();
	}

	endwin();
	delete board;
	return 0;
}

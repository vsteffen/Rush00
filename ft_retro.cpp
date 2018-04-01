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
#include "BoardGame.hpp"

#define DELAY 25000
#define MIN_WIN_HEIGHT 30
#define MIN_WIN_WIDTH 90

void resizeHandler(int sig) {
	(void)sig;
	endwin();
	exit(0);
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
	return (0);
}

void		print_top(WINDOW *win, BoardGame * board, Entity * perso, time_t begin) {
	std::string			str("");

	time_t				timer = time(NULL);
	timer = timer - begin;

	str += getmaxy(win);
	mvprintw(0, 0, "SCORE: %d", board->getScore());

	mvprintw(0, 15, "HP: %d", perso->getHitPoints());

	mvprintw(0, 30, "Time survive : %dm %ds", timer / 60 , timer % 60);


	mvprintw(1, 0, getHSep(getmaxx(win)));
}

int						main ( void ) {

	int					key = 0;
	WINDOW 				*win;

	time_t				begin = time(NULL);

	signal (SIGWINCH, resizeHandler);

	win = init_ncurses();
	std::srand(time(NULL));
	nodelay(stdscr, TRUE);

	int					playerPosY = getmaxy(win) - 1, playerPosX = getmaxx(win) / 2;
	BoardGame *			board = new BoardGame(getmaxy(win), getmaxx(win));
	Entity *			perso = new Character();

	perso->setXPos(playerPosX);
	perso->setYPos(playerPosY);
	board->addEntity(perso);

	while (key != 27) {
		mvprintw(getmaxy(win) / 2, (getmaxx(win) / 2) - 35, "Appuyez sur espace pour commencer ou sur échap pour quitter");
		key = getch();

		if (key == ' ') {
			while(key != 27) {
				print_top(win, board, perso, begin);
				board->printBoard();
				key = getch();
				if (perso->getHitPoints() == 0) {
					time_t	end = time(NULL);
					end = end - begin;
					while (key != 27) {
						mvprintw(getmaxy(win) / 2 - 2, (getmaxx(win) / 2) - 23, "Vous êtes mort ! Appuyez sur échap.");
						mvprintw((getmaxy(win) / 2), (getmaxx(win) / 2) - 17, "Votre score est de %d", board->getScore());
						mvprintw((getmaxy(win) / 2) + 2, (getmaxx(win) / 2) - 26, "Vous avez survécu %d minutes et %d secondes", end / 60, end % 60);
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

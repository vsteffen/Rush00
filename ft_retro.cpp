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

#define DELAY 8000
#define MIN_WIN_HEIGHT 30
#define MIN_WIN_WIDTH 90

int			score = 0;

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

int			handle_key(WINDOW *win, int *playerPosY, int *playerPosX, int key)
{
	// if (key == 27)
		// return (1);
	if (key == KEY_UP && *playerPosY > 2)
		(*playerPosY)--;
	if (key == KEY_DOWN && *playerPosY < getmaxy(win) - 1)
		(*playerPosY)++;
	if (key == KEY_LEFT && *playerPosX > 0)
		(*playerPosX)--;
	if (key == KEY_RIGHT && *playerPosX < getmaxx(win) - 1)
		(*playerPosX)++;
	if (key == KEY_DOWN || key == KEY_RIGHT || key == KEY_LEFT || key == KEY_UP) {
		mvprintw(20, 0, "key = ");
		debug_int(20, 6, key);
	}
	mvprintw(getmaxy(win) - 2, 0, "key = %d", key);
	mvprintw(getmaxy(win) - 1, 0, "key = %d", KEY_DOWN);
	return (0);
}

int				main ( void ) {
	WINDOW 		*win;
	int			key = 0;

	signal (SIGWINCH, resizeHandler);

	win = init_ncurses();

	int			playerPosY = getmaxy(win) - 1, playerPosX = getmaxx(win) / 2;

	while(key != 27) {
		print_top(win);
		print_player(playerPosY, playerPosX);
		key = getch();
		if (handle_key(win, &playerPosY, &playerPosX, key))
			break ;
		wrefresh(win);
		usleep(DELAY);
		clear();
	}
	endwin();
	return 0;
}

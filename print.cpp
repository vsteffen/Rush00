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

extern int score;

char const		*getHSep(int win_width) {
	std::string		sep;
	for (int i = 0 ; i < win_width ; i++) {
		sep += std::string("-");
	}
	return sep.c_str();
}

void	debug_int(int height, int width, int integer) {
	mvprintw(height, width, "");
	printw("%d", integer);
	return ;
}

void	print_start(WINDOW *win) {
	int		y;
	int		x;

	getmaxyx(win, y, x);
	if ((x = (x / 2) - 17 < 0)) {
		x = 0;
	}
	mvprintw(y / 2, x, "Press a key to start ft_retro !");
	return ;
}

void	print_player(int playerPosY, int playerPosX) {
	mvprintw(playerPosY, playerPosX, "O");
}

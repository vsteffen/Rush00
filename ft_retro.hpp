#ifndef FT_RETRO_H
# define FT_RETRO_H

# include <ncurses.h>
# include <string>
# include <unistd.h>
# include <stdio.h>
# include <signal.h>
# include <stdlib.h>

char const		*getHSep(int win_width);
void			debug_int(int height, int width, int integer);
void			print_start(WINDOW *win);
void			print_player(int playerPosY, int playerPosX);

#endif

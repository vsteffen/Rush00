# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: quroulon <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/26 13:12:08 by quroulon          #+#    #+#              #
#    Updated: 2018/03/26 13:12:11 by quroulon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_retro

CC = clang++
CFLAGS = -Wall -Wextra -Werror -Wno-write-strings
#-std=c++98
LDFLAGS = -lncurses

# INC = $(wildcard *.hpp)
LIBS =

SRC = ft_retro.cpp \
	  print.cpp

OBJ = $(SRC:%.cpp=%.o)

_RED		=	\033[0;31m
_GREEN		=	\033[0;32m
_BLUE		=	\033[0;36m
_RESET		=	\033[0;m
_WHITE		=	\033[0;37m

.PHONY: clean fclean re all

all: $(NAME)

$(NAME): $(OBJ) $(LIBS)
	@$(CC) -o $@ $^ $(LDFLAGS)
	@echo "$(_GREEN)Creation of exe $@$(_RESET)"

%.o: %.cpp $(INC)
	@$(CC) -o $@ -c $< $(CFLAGS)
	@echo "Compilation of $<"

$(LIBS):
	@$(MAKE) -C $(LIBS)

clean:
	@rm -f $(OBJ)
	@echo "$(_BLUE)Deleted Obj files$(_RESET)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(_BLUE)$(NAME) Deleted$(_RESET)"

re: fclean all

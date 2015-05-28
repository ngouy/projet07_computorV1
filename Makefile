# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ngouy <ngouy@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/04/03 13:54:24 by ngouy             #+#    #+#              #
#    Updated: 2015/05/28 17:39:20 by ngouy            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			= gcc
NAME		= computorv1

SRC			=./Sources/computorv1.c\
			 ./Sources/ft_basics.c\
			 ./Sources/ft_display_funcs.c\
			 ./Sources/ft_init.c\
			 ./Sources/parsing.c\
			 ./Sources/parsing_aux.c\

OBJ			= ./computorv1.o\
			  ./ft_basics.o\
			  ./ft_display_funcs.o\
			  ./ft_init.o\
			  ./parsing.o\
			  ./parsing_aux.o\

CFLAGS		= -Wall -Wextra -ansi -pedantic
OFLAGS		= -O3

RM			= rm -rf

all: $(NAME)

$(NAME):
			make -C ./Libs/libft/
			gcc $(CFLAGS) -c $(SRC)
			gcc $(OBJ) -I ./Includes ./Libs/libft/libft.a -o $(NAME)

clean:
			make clean -C ./Libs/libft/
			$(RM) $(OBJ)

fclean:		clean
			make fclean -C ./Libs/libft/
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean re fclean

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adjouber <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/05 12:07:03 by adjouber          #+#    #+#              #
#    Updated: 2019/01/31 14:46:50 by adjouber         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

SRCS = src/main.c \
	   src/burningship.c \
	   src/mandelbrot.c \
	   src/tricorne.c \
	   src/julia_1.c \
	   src/julia_2.c \
	   src/julia_3.c \
	   src/init.c \
	   src/color.c \
	   src/plus.c \
	   src/key.c \
	   src/mouse.c \
	   src/multithread.c \

OBJS = $(SRCS:.c=.o)

INCLUDES = -I libft/includes -I /usr/local/include -I include

LIB = -L libft/ -lft -L /usr/local/lib -lmlx

CC = gcc

FLAG = -Wall -Werror -Wextra 

DEBUG = -g3 -fsanitize=address,undefined -Weverything -pedantic

all : $(NAME)

$(NAME) : $(OBJS)
	@make -C libft/
	@$(CC) $(FLAG) -o $(NAME) $(OBJS) $(INCLUDES) $(LIB) -framework OpenGL -framework AppKit
	@echo "FRACTOL:	FRACTOL READY"

%.o : %.c
	@$(CC) $(FLAG) $(INCLUDES) -c $< -o $@

clean :
	@make -C libft/ clean
	@rm -f $(OBJS)
	@echo "FRACTOL:	Removing OBJ path"

fclean : clean
	@make -C libft/ fclean
	@rm -f $(NAME)
	@echo "FRACTOL:	Removing FRACTOL executable"

re : fclean all

.PHONY: all, clean, fclean, re

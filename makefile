# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adjouber <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/05 12:07:03 by adjouber          #+#    #+#              #
#    Updated: 2018/12/28 13:47:46 by adjouber         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

SRCS = src/main.c \

OBJS = $(SRCS:.c=.o)

INCLUDES = -I libft/includes -I /usr/local/include -I include

LIB = -L libft/ -lft -L /usr/local/lib -lmlx

CC = gcc

FLAG = -Wall -Werror -Wextra -g3 -fsanitize=address

all : $(NAME)

$(NAME) : $(OBJS)
	@make -C libft/
	@$(CC) $(FLAG) -o $(NAME) $(OBJS) $(INCLUDES) $(LIB) -framework OpenGL -framework AppKit
	@echo "FDF:		FDF READY"

%.o : %.c
	@$(CC) $(FLAG) $(INCLUDES) -c $< -o $@

clean :
	@make -C libft/ clean
	@rm -f $(OBJS)
	@echo "FDF:		Removing OBJ path"

fclean : clean
	@make -C libft/ fclean
	@rm -f $(NAME)
	@echo "FDF:		Removing FDF executable"

re : fclean all

.PHONY: all, clean, fclean, re

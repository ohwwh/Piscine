# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ohw <ohw@student.42seoul.kr>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/23 02:36:10 by ohw               #+#    #+#              #
#    Updated: 2021/10/28 13:30:13 by hoh              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME=libft.a
SRCSDIR=srcs
INCS=includes
SRCS=srcs/ft_putstr.c srcs/ft_putchar.c srcs/ft_swap.c srcs/ft_strlen.c srcs/ft_strcmp.c
OBJS=${SRCS:.c=.o}

.PHONY: all clean fclean re

all : $(NAME)

libft.a : $(OBJS)
	ar rc $(NAME) $(OBJS)

$(OBJS) : $(SRCS)
	$(CC) $(CFLAGS) -c $< -o $@ -I$(INCS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

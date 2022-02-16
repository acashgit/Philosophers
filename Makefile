# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acash <acash@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/27 15:46:01 by acash             #+#    #+#              #
#    Updated: 2022/02/02 16:36:22 by acash            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
GCC = gcc
CFLAGS = -Wall -Werror -Wextra

SRCS = philo.c \
		utils1.c \
		utils2.c \
		init.c \
		cycle.c \
		answer.c \
		buisnes.c \

OBJS = $(SRCS:.c=.o)

all:  $(NAME)

$(NAME): $(OBJS) philo.h Makefile
	$(GCC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean
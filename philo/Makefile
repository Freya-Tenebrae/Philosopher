# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/14 23:11:43 by cmaginot          #+#    #+#              #
#    Updated: 2022/03/01 17:05:23 by cmaginot         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME=philo

SRCS=$(addprefix ${FOLDER}/, \
	main.c \
	philo.c \
	messages.c \
	parsing.c \
	init_and_close.c \
	tools_check_if_all_num.c \
	tools_atoi.c \
	tools_putnbr.c \
	tools_time.c)
OBJS=$(SRCS:.c=.o)

INCLUDES=$(addprefix includes/, \
	philo.h)
FOLDER=srcs

CC=clang
CFLAGS=-Wall -Wextra -Werror -pthread
RM=rm -f

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) -c $(CFLAGS) -o $@ $< -I $(INCLUDES)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
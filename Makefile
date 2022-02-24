# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/14 23:11:43 by cmaginot          #+#    #+#              #
#    Updated: 2022/02/24 05:31:47 by cmaginot         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME=philo

SRCS=$(addprefix ${FOLDER}/, \
	philo.c \
	ft_tools_atoi.c)
OBJS=$(SRCS:.c=.o)

INCLUDES=$(addprefix includes/, \
	philo.h)
FOLDER=srcs

CC=clang -g
CFLAGS=-Wall -Wextra -Werror -g3 -fsanitize=address
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
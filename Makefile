# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/14 23:11:43 by cmaginot          #+#    #+#              #
#    Updated: 2021/11/01 19:48:24 by cmaginot         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME=philo
NAME_BONUS=philo_bonus

SRCS=$(addprefix ${FOLDER}/, \
	ft_philo.c)
SRCS_BONUS=$(addprefix ${FOLDER}/, \
	ft_philo.c)
OBJS=$(SRCS:.c=.o)
OBJS_BONUS=$(SRCS_BOUNS:.c=.o)

INCLUDES=$(addprefix includes/, \
	ft_philo.h)
FOLDER=srcs

CC=gcc -g
CFLAGS=-Wall -Wextra -Werror -g3 -fsanitize=address
RM=rm -f

all: $(NAME)

bonus: $(NAME_BONUS)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^ $(INCLUDES)

$(NAME_BONUS): $(OBJS_BONUS)
	$(CC) $(CFLAGS) -o $@ $^ $(INCLUDES)

%.o: %.c
	$(CC) -c $(CFLAGS) -o $@ $< $(INCLUDES)

clean:
	$(RM) $(OBJS) $(OBJS_BONUS)

fclean: clean
	$(RM) $(NAME) $(NAME_BONUS)

re: fclean all

re_bonus: fclean bonus

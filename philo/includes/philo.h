/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 04:46:01 by cmaginot          #+#    #+#             */
/*   Updated: 2022/02/27 17:16:07 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

/* ************************************************************************** */
/*                                  INCLUDES                                  */
/* ************************************************************************** */
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

/* ************************************************************************** */
/*                                   DEFINE                                   */
/* ************************************************************************** */
//status philo
# define EATING 1
# define THINKING 2
# define SLEEPING 3
# define ALIVE 0
# define DEAD -1

//status scene
# define RUNNING 0
# define STOPPED -1

//status message
# define MESSAGE_FORK 0
# define MESSAGE_EAT 1
# define MESSAGE_SLEEP 2
# define MESSAGE_THINK 3
# define MESSAGE_DIE 4

/* ************************************************************************** */
/*                                  TYPEDEF                                   */
/* ************************************************************************** */

typedef struct s_philo {
	int				id;
	pthread_t		philo_thread;
	int				status_philo;
	int				status_start;
	int				number_of_time_eat;
	struct s_scene	*scene;
}					t_philo;

typedef struct 	s_scene {
	int				nbr_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				number_of_time_eating;
	int				number_of_time_eating_set;
	int				status_scene;
	pthread_mutex_t	message;
	t_philo			*philo;
}					t_scene;

/* ************************************************************************** */
/*                                  FONCTION                                  */
/* ************************************************************************** */
int		main(int argc, char **argv);
int		check_if_all_num(int argc, char **argv);
int		parsing(t_scene *scene, int argc, char **argv);
int		init(t_scene *scene);
void	close_thread(t_scene *scene);
void	*philo_loop(void *arg);
void	message(int type_message, t_philo *philo);

/* ************************************************************************** */
/*                                   TOOLS                                    */
/* ************************************************************************** */
size_t	ft_atoi(const char *str);
void	ft_putnbr(int n);
int		get_timestamp(void);

/* ************************************************************************** */
/*                                    END                                     */
/* ************************************************************************** */
#endif
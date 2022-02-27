/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 04:46:01 by cmaginot          #+#    #+#             */
/*   Updated: 2022/02/27 12:36:42 by cmaginot         ###   ########.fr       */
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

/* ************************************************************************** */
/*                                  TYPEDEF                                   */
/* ************************************************************************** */
typedef struct s_philo {
	int			id;
	pthread_t	philo_thread;
	int			status_philo;
	int			status_start;
	int			number_of_time_eat;
}				t_philo;

typedef struct s_scene {
	int			nbr_philo;
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	int			number_of_time_eating;
	int			number_of_time_eating_set;
	int			status_scene;
	t_philo		*philo;
}				t_scene;

/* ************************************************************************** */
/*                                  FONCTION                                  */
/* ************************************************************************** */
int		main(int argc, char **argv);

/* ************************************************************************** */
/*                                   TOOLS                                    */
/* ************************************************************************** */
size_t	ft_atoi(const char *str);
int		parsing(t_scene *scene, int argc, char **argv);
int		init(t_scene *scene);
void	close_thread(t_scene *scene);

/* ************************************************************************** */
/*                                    END                                     */
/* ************************************************************************** */
#endif
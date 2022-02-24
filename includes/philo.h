/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 04:46:01 by cmaginot          #+#    #+#             */
/*   Updated: 2022/02/24 06:48:27 by cmaginot         ###   ########.fr       */
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

/* ************************************************************************** */
/*                                   DEFINE                                   */
/* ************************************************************************** */
//status philo
# define EATING 1
# define THINKING 2
# define SLEAPING 3
# define ALIVE 0
# define DEAD -1

/* ************************************************************************** */
/*                                  TYPEDEF                                   */
/* ************************************************************************** */
typedef struct s_scene {
	int			nbr_philo;
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	int			number_of_time_eating;
	int			number_of_time_eating_set;
}				t_scene;

typedef struct s_philo {
	int			id;
	int			status;
	int			time_to_eat;
	int			time_to_sleep;
	int			number_of_time_eating;
	int			number_of_time_eating_set;
}				t_philo;

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

/* ************************************************************************** */
/*                                    END                                     */
/* ************************************************************************** */
#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 05:49:57 by cmaginot          #+#    #+#             */
/*   Updated: 2022/02/28 05:46:37 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static int	parsing_philo(t_scene *scene)
{
	int	i;

	i = -1;
	while (++i < scene->nbr_philo)
	{
		scene->philo[i].id = i + 1;
		scene->philo[i].status_philo = ALIVE;
		scene->philo[i].time_start_last_meal = 0;
		scene->philo[i].number_of_time_eat = 0;
		scene->philo[i].scene = scene;
	}
	return (0);
}

static int	parsing_2(t_scene *scene, int argc, char **argv)
{
	if (argc == 6)
	{
		scene->number_of_time_eating_set = 1;
		scene->number_of_time_eating = ft_atoi(argv[5]);
		if (scene->number_of_time_eating <= 0)
		{
			write(1, "Error : incorrect number of time each philosopher ", 50);
			write(1, "must eat.\n", 10);
			return (-1);
		}
	}
	else
	{
		scene->number_of_time_eating_set = 0;
		scene->number_of_time_eating = 0;
	}
	scene->philo = malloc(sizeof(t_philo) * (scene->nbr_philo));
	if (!scene->philo || scene->philo == NULL)
	{
		write(1, "Error : malloc error.\n", 22);
		return (-1);
	}
	scene->status_scene = RUNNING;
	return (parsing_philo(scene));
}

int	parsing(t_scene *scene, int argc, char **argv)
{
	scene->nbr_philo = ft_atoi(argv[1]);
	if (scene->nbr_philo <= 0)
	{
		write(1, \
			"Error : number of philosopher can't be null or negetive.\n", 57);
		return (-1);
	}
	else if (scene->nbr_philo > NB_MAX_PHILO)
	{
		write(1, "Error : number of philosopher too hight.\n", 41);
		return (-1);
	}
	scene->time_to_die = ft_atoi(argv[2]);
	if (scene->time_to_die <= 0)
	{
		write(1, "Error : time to die can't be null or negetive.\n", 47);
		return (-1);
	}
	scene->time_to_eat = ft_atoi(argv[3]);
	if (scene->time_to_eat <= 0)
	{
		write(1, "Error : time to eat can't be null or negetive.\n", 47);
		return (-1);
	}
	scene->time_to_sleep = ft_atoi(argv[4]);
	if (scene->time_to_sleep <= 0)
	{
		write(1, "Error : time to sleep can't be null or negetive.\n", 49);
		return (-1);
	}
	return (parsing_2(scene, argc, argv));
}

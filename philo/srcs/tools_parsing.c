/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 05:49:57 by cmaginot          #+#    #+#             */
/*   Updated: 2022/02/27 12:13:59 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int parsing_philo(t_scene *scene)
{
	int	i;

	i = -1;
	while (++i < scene->nbr_philo)
	{
		scene->philo[i].id = i;
		scene->philo[i].status_philo = ALIVE;
		scene->philo[i].status_start = 0;
		scene->philo[i].number_of_time_eat = 0;
	}
	return (0);
}

int	parsing_2(t_scene *scene, int argc, char **argv)
{
	if (argc == 6)
	{
		scene->number_of_time_eating_set = 1;
		scene->number_of_time_eating = ft_atoi(argv[5]);
		if (scene->number_of_time_eating <= 0)
		{
			printf("Error : incorrect number of time each philosopher ");
			printf("must eat.\n");
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
		printf("Error : malloc error.\n");
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
		printf("Error : number of philosopher can't be null or negetive.\n");
		return (-1);
	}
	scene->time_to_die = ft_atoi(argv[2]);
	if (scene->time_to_die <= 0)
	{
		printf("Error : time to die can't be null or negetive.\n");
		return (-1);
	}
	scene->time_to_eat = ft_atoi(argv[3]);
	if (scene->time_to_eat <= 0)
	{
		printf("Error : time to eat can't be null or negetive.\n");
		return (-1);
	}
	scene->time_to_sleep = ft_atoi(argv[4]);
	if (scene->time_to_sleep <= 0)
	{
		printf("Error : time to sleep can't be null or negetive.\n");
		return (-1);
	}
	return (parsing_2(scene, argc, argv));
}
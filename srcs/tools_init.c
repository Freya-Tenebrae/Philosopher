/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 05:49:57 by cmaginot          #+#    #+#             */
/*   Updated: 2022/02/24 06:37:39 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static int	parsing(t_scene *scene, int argc, char **argv)
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
	return (0);
}

int	init(t_scene *scene, int argc, char **argv)
{
	return (parsing(scene, argc, argv));
}

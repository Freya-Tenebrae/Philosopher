/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 04:46:01 by cmaginot          #+#    #+#             */
/*   Updated: 2022/02/28 16:24:52 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static void	everyone_eat(t_scene *scene)
{
	int	i;
	int	res;

	i = -1;
	res = 0;
	if (scene->number_of_time_eating == 0)
		res = 1;
	else
	{
		while (++i < scene->nbr_philo)
		{
			pthread_mutex_lock(&scene->lock);
			if (scene->philo[i].number_of_time_eat <= \
												scene->number_of_time_eating)
				res = 1;
			pthread_mutex_unlock(&scene->lock);
		}
	}
	if (res == 0)
	{
		pthread_mutex_lock(&scene->lock);
		scene->status_scene = STOPPED;
		pthread_mutex_unlock(&scene->lock);
	}
}

static void	update_status_philo(t_scene *scene)
{
	int	i;
	int	timestamp;

	i = -1;
	pthread_mutex_lock(&scene->lock);
	timestamp = get_timestamp();
	pthread_mutex_unlock(&scene->lock);
	while (++i < scene->nbr_philo)
	{
		pthread_mutex_lock(&scene->lock);
		if (timestamp - scene->philo[i].time_start_last_meal >= \
															scene->time_to_die)
		{
			pthread_mutex_unlock(&scene->lock);
			message(MESSAGE_DIE, &scene->philo[i]);
			pthread_mutex_lock(&scene->lock);
			scene->status_scene = STOPPED;
		}
		pthread_mutex_unlock(&scene->lock);
	}
	if (scene->status_scene == RUNNING)
		everyone_eat(scene);
}

int	main(int argc, char **argv)
{
	t_scene	scene;

	if (argc != 5 && argc != 6)
	{
		write(1, "Error : incorrect number of arguments.\n", 39);
		ft_putnbr(argc - 1);
		write(1, " arguments given, 4 or 5 expected.\n", 35);
		return (-1);
	}
	if (check_if_all_num(argc, argv) != 0)
		return (-1);
	if (parsing(&scene, argc, argv) != 0)
		return (-1);
	if (init(&scene) != 0)
		return (-1);
	while (scene.status_scene == RUNNING)
		update_status_philo(&scene);
	close_thread(&scene);
	free (scene.philo);
	return (0);
}

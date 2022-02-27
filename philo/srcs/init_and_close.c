/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_and_close.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 05:49:57 by cmaginot          #+#    #+#             */
/*   Updated: 2022/02/27 16:55:35 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	init(t_scene *scene)
{
	int	i;

	i = -1;
	pthread_mutex_init(&scene->message, NULL);
	while (++i < scene->nbr_philo)
	{
		pthread_create(&(scene->philo[i].philo_thread), NULL, philo_loop, \
			(void *)&(scene->philo[i]));
	}
	return (0);
}

void	close_thread(t_scene *scene)
{
	int	i;

	i = -1;
	while (++i < scene->nbr_philo)
		pthread_join(scene->philo[i].philo_thread, NULL);
}

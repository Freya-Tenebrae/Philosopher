/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 12:42:59 by cmaginot          #+#    #+#             */
/*   Updated: 2022/02/27 16:57:19 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*philo_loop(void *arg)
{
	t_philo	*philo;
	t_philo	*next_philo;

	philo = (t_philo *)arg;
	if (philo->id != philo->scene->nbr_philo)
		next_philo = &(philo->scene->philo[philo->id]);
	else
		next_philo = &(philo->scene->philo[0]);
	printf("id_philo : %i | id_next_philo : %i\n", philo->id, next_philo->id);
	while (philo->scene->status_scene == RUNNING)
	{
		usleep(1000);
		message(MESSAGE_FORK, philo);
		usleep(1000);
		message(MESSAGE_EAT, philo);
		usleep(1000);
		message(MESSAGE_SLEEP, philo);
		usleep(1000);
		message(MESSAGE_THINK, philo);
		usleep(1000);
		message(MESSAGE_DIE, philo);
	}
	return (NULL);
}

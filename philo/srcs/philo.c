/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 12:42:59 by cmaginot          #+#    #+#             */
/*   Updated: 2022/02/28 06:37:38 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static void	philo_sleep(t_philo *philo)
{
	message(MESSAGE_SLEEP, philo);
	philo->status_philo = SLEEPING;
	usleep(1000 * philo->scene->time_to_sleep);
}

static void	philo_eat(t_philo *philo, t_philo *next_philo)
{
	(void)next_philo;
	//pthread_mutex_lock(&philo->fork);
	message(MESSAGE_FORK, philo);
	//pthread_mutex_lock(&next_philo->fork);
	message(MESSAGE_FORK, philo);
	message(MESSAGE_EAT, philo);
	philo->status_philo = EATING;
	philo->time_start_last_meal = get_timestamp();
	usleep(1000 * philo->scene->time_to_eat);
	//pthread_mutex_unlock(&philo->fork);
	//pthread_mutex_unlock(&next_philo->fork);
}

void	*philo_loop(void *arg)
{
	t_philo	*philo;
	t_philo	*next_philo;

	philo = (t_philo *)arg;
	if (philo->id != philo->scene->nbr_philo)
		next_philo = &(philo->scene->philo[philo->id]);
	else
		next_philo = &(philo->scene->philo[0]);
	while (philo->scene->status_scene == RUNNING && philo->status_philo != DEAD)
	{
		philo->status_philo = THINKING;
		message(MESSAGE_THINK, philo);
		philo_eat(philo, next_philo);
		philo_sleep(philo);
	}
	return (NULL);
}

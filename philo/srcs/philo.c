/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 12:42:59 by cmaginot          #+#    #+#             */
/*   Updated: 2022/03/01 18:53:45 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static void	smart_sleep(unsigned long time, t_philo *philo)
{
	unsigned long	i;

	i = get_timestamp();
	while (1)
	{
		pthread_mutex_lock(&philo->scene->lock);
		if (philo->scene->status_scene != RUNNING)
		{
			pthread_mutex_unlock(&philo->scene->lock);
			break ;
		}
		pthread_mutex_unlock(&philo->scene->lock);
		if (get_timestamp() - i >= time)
			break ;
		usleep(1000);
	}
}

static void	philo_sleep(t_philo *philo)
{
	message(MESSAGE_SLEEP, philo);
	smart_sleep(philo->scene->time_to_sleep, philo);
}

static void	philo_eat_if_alone(t_philo *philo)
{
	pthread_mutex_lock(&philo->scene->lock);
	while (philo->scene->status_scene != STOPPED)
	{
		pthread_mutex_unlock(&philo->scene->lock);
		smart_sleep(philo->scene->time_to_eat, philo);
		pthread_mutex_lock(&philo->scene->lock);
	}
	pthread_mutex_unlock(&philo->scene->lock);
}

static void	philo_eat(t_philo *philo, t_philo *next_philo)
{
	if (philo->scene->nbr_philo > 1)
	{
		if (philo->id % 2 == 0)
			pthread_mutex_lock(&philo->fork);
		else
			pthread_mutex_lock(&next_philo->fork);
		message(MESSAGE_FORK, philo);
		if (philo->id % 2 == 0)
			pthread_mutex_lock(&next_philo->fork);
		else
			pthread_mutex_lock(&philo->fork);
		message(MESSAGE_FORK, philo);
		message(MESSAGE_EAT, philo);
		pthread_mutex_lock(&philo->scene->lock);
		philo->time_start_last_meal = get_timestamp();
		philo->number_of_time_eat += 1;
		pthread_mutex_unlock(&philo->scene->lock);
		smart_sleep(philo->scene->time_to_eat, philo);
		pthread_mutex_unlock(&philo->fork);
		pthread_mutex_unlock(&next_philo->fork);
	}
	else
		philo_eat_if_alone(philo);
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
	if (philo->id % 2 == 0)
		usleep(1000);
	while (1)
	{
		philo_eat(philo, next_philo);
		philo_sleep(philo);
		pthread_mutex_lock(&philo->scene->lock);
		if (philo->scene->status_scene == STOPPED)
			break ;
		pthread_mutex_unlock(&philo->scene->lock);
		message(MESSAGE_THINK, philo);
		usleep(1000);
	}
	pthread_mutex_unlock(&philo->scene->lock);
	return (NULL);
}

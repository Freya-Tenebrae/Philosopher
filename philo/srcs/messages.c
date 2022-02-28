/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   messages.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 14:04:07 by cmaginot          #+#    #+#             */
/*   Updated: 2022/02/28 13:36:33 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static void	message_type(int type_message)
{
	if (type_message == MESSAGE_FORK)
		write(1, " has taken a fork\n", 18);
	else if (type_message == MESSAGE_EAT)
		write(1, " is eating\n", 11);
	else if (type_message == MESSAGE_SLEEP)
		write(1, " is sleeping\n", 13);
	else if (type_message == MESSAGE_THINK)
		write(1, " is thinking\n", 13);
	else if (type_message == MESSAGE_DIE)
		write(1, " died\n", 6);
}

void	message(int type_message, t_philo *philo)
{
	int	timestamp;

	pthread_mutex_lock(&philo->scene->lock);
	timestamp = get_timestamp();
	pthread_mutex_unlock(&philo->scene->lock);
	pthread_mutex_lock(&philo->scene->message);
	ft_putnbr(timestamp);
	write(1, " ", 1);
	ft_putnbr(philo->id);
	message_type(type_message);
	pthread_mutex_unlock(&philo->scene->message);
}

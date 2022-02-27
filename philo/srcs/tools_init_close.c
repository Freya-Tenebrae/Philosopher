/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_init_close.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 05:49:57 by cmaginot          #+#    #+#             */
/*   Updated: 2022/02/27 12:38:32 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void *ft_call_itself(void *arg)
{
	t_philo *philo;

	philo = (t_philo *)arg;
	printf("id_philo : %i\n", philo->id);
	return (NULL);
}

int	init(t_scene *scene)
{
	int	i;

	i = -1;
	while (++i < scene->nbr_philo)
	{
		pthread_create(&(scene->philo[i].philo_thread), NULL, ft_call_itself, 
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
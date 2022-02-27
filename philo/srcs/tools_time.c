/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_time.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 14:38:01 by cmaginot          #+#    #+#             */
/*   Updated: 2022/02/27 15:43:24 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static unsigned long	get_time(void)
{
	struct			timeval tv;
	unsigned long	time;

	gettimeofday(&tv, NULL);
	time = tv.tv_sec * 1000;
	time += tv.tv_usec / 1000;
	return (time);
}

int get_timestamp(void)
{
	static unsigned long time_start;
	int	timestamp;

	if (!time_start)
		time_start = get_time();
	timestamp = get_time() - time_start;
	return (timestamp);
}
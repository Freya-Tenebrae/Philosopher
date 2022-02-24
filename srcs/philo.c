/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 04:46:01 by cmaginot          #+#    #+#             */
/*   Updated: 2022/02/24 06:38:14 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

// ARGV = 5 : simulation end when a philosopher die
// ARGV = 6 : simulation end when a philosopher die or when each philosopher
			// eat n times

int	main(int argc, char **argv)
{
	t_scene	scene;

	if (argc != 5 && argc != 6)
	{
		printf("Error : incorrect number of arguments.\n");
		printf("%i arguments given, 4 or 5 expected.\n", argc - 1);
		return (-1);
	}
	if (init(&scene, argc, argv) != 0)
		return (-1);
	// create all thread
	// loop while all philo are alive / philo eat n time (if argc == 6)
	// join all thread
	return (0);
}

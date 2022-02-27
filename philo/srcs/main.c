/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 04:46:01 by cmaginot          #+#    #+#             */
/*   Updated: 2022/02/27 17:46:15 by cmaginot         ###   ########.fr       */
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
	close_thread(&scene);
	free (scene.philo);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 04:46:01 by cmaginot          #+#    #+#             */
/*   Updated: 2022/02/28 06:50:58 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

// static int everyone_eat(t_scene *scene)
// {
// 	int	i;

// 	i = -1;
// 	if (scene->number_of_time_eating == 0)
// 		return (0);
// 	while (++i < scene->nbr_philo)
// 	{
// 		if (scene->philo[i].number_of_time_eat == scene->number_of_time_eating)
// 			return (1);
// 	}
// 	return (0);
// }

// static int everyone_alive(t_scene *scene)
// {
// 	int	i;

// 	i = -1;
// 	while (++i < scene->nbr_philo)
// 	{
// 		if (scene->philo[i].status_philo == DEAD)
// 			return (-1);
// 	}
// 	return (0);
// }

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
	// while (scene.status_scene == RUNNING)
	// {
	// 	if (everyone_alive(&scene) != 0 || everyone_eat(&scene) == 0)
	// 		scene.status_scene = STOPPED;
	// }
	close_thread(&scene);
	free (scene.philo);
	return (0);
}

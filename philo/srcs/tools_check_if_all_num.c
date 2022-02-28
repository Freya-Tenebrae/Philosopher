/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_check_if_all_num.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 18:01:40 by cmaginot          #+#    #+#             */
/*   Updated: 2022/02/28 06:38:18 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static int	is_num(char c)
{
	if (c >= '0' && c <= '9')
		return (0);
	return (-1);
}

int	check_if_all_num(int argc, char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (++i < argc)
	{
		j = 0;
		while (argv[i][j] != 0)
		{
			if (is_num(argv[i][j]) != 0 && argv[i][j] != '-')
			{
				write(1, "Error : parsing error, all args must be numeric\n", \
					48);
				return (-1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

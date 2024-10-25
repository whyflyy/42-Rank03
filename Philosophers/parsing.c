/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcavadas <jcavadas@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 20:29:54 by jcavadas          #+#    #+#             */
/*   Updated: 2024/10/22 14:17:12 by jcavadas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static long	ft_atol(const char *s)
{
	long		res;

	res = 0;
	while ((*s == '+' || *s == 32 || (*s >= 9 && *s <= 13)))
		s++;
	if (*s == '-')
		return (0);
	if (!(*s >= '0' && *s <= '9'))
	{
		error_exit("Input Error: Digit values only");
		return (0);
	}
	while (*s >= '0' && *s <= '9')
		res = (res * 10) + (*s++ - '0');
	return (res);
}

static long	check_int_range(t_table *table, char *argv)
{
	long	input;

	input = ft_atol(argv);
	if (input > INT_MAX)
		error_exit("Input Error: The value cannot exceed 2147483647");
	if (input < 1)
		error_exit("Input Error: Positive values only");
	return (input);
}

void	parse_input(t_table *table, char **argv)
{
	table->philo_nbr = check_int_range(table, argv[1]);
	if (table->philo_nbr > 200 || table->philo_nbr < 1)
		error_exit("Input Error: Total number of philos must be 1 - 200");
	table->time_to_die = check_int_range(table, argv[2]) * 1000;
	table->time_to_eat = check_int_range(table, argv[3]) * 1000;
	table->time_to_sleep = check_int_range(table, argv[4]) * 1000;
	if (table->time_to_die < 60000 || table->time_to_sleep < 60000
		|| table->time_to_eat < 60000)
		error_exit("Input Error: Each of the 'time_to' values must exceed 60");
	if (argv[5])
		table->nbr_limit_meals = check_int_range(table, argv[5]);
	else
		table->nbr_limit_meals = -1;
}

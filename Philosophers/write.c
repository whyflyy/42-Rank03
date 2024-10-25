/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcavadas <jcavadas@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 01:25:31 by jcavadas          #+#    #+#             */
/*   Updated: 2024/10/22 14:34:54 by jcavadas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	write_status(t_ph_status status, t_philo *philo)
{
	long	elapsed;

	elapsed = get_time(MILLISECONDS) - philo->table->sim_start;
	if (philo->full)
		return ;
	pthread_mutex_lock(&philo->table->write_mutex);
	if ((status == TAKES_LEFTFORK || status == TAKES_RIGHTFORK)
		&& !simulation_finished(philo->table))
		printf(C_MAGENTA"%-6ld"C_CYAN" %d"END_COLOR" has taken a fork\n",
			elapsed, philo->id);
	else if (status == EATING && !simulation_finished(philo->table))
		printf(C_MAGENTA"%-6ld"C_CYAN" %d"END_COLOR" is eating\n",
			elapsed, philo->id);
	else if (status == THINKING && !simulation_finished(philo->table))
		printf(C_MAGENTA"%-6ld"C_CYAN" %d"END_COLOR" is thinking\n",
			elapsed, philo->id);
	else if (status == SLEEPING && !simulation_finished(philo->table))
		printf(C_MAGENTA"%-6ld"C_CYAN" %d"END_COLOR" is sleeping\n",
			elapsed, philo->id);
	else if (status == DIED)
		printf(C_RED"%-6ld %d died \n"END_COLOR, elapsed, philo->id);
	pthread_mutex_unlock(&philo->table->write_mutex);
}

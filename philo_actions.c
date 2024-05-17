/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymometto <ymometto@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 13:59:49 by ymometto          #+#    #+#             */
/*   Updated: 2024/05/17 14:17:29 by ymometto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	timestamp(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time->tv_sec * 1000) + (time->tv_usec / 1000));
}

int	is_dead(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->mutex_stop);
	if (philo->table->end_simulation == 1)
	{
		pthread_mutex_unlock(&philo->table->mutex_stop);
		return (1);
	}
	if (philo->time_to_death <= timestamp())
	{
		philo->death = 1;
		pthread_mutex_unlock(&philo->table->mutex_stop);
		return (1);
	}
	pthread_mutex_unlock(&philo->table->mutex_stop);
	return (0);
}

int	philo_wait(t_philo *philo, long act_time)
{
	long	time_wait;

	time_wait = timestamp() + act_time;
	while (timestamp() < time_wait)
	{
		if (is_dead(philo))
			return (0);
		usleep(500);
	}
	return (1);
}

int	philo_slepp(t_philo *philo)
{
	print_action(philo, "The philosopher is sleeping");
	return (philo_wait(philo, philo->table->time_sleep));
}

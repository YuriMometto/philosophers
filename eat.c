/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymometto <ymometto@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 14:39:07 by ymometto          #+#    #+#             */
/*   Updated: 2024/05/17 15:10:48 by ymometto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	one_fork(t_philo *philo, t_philo *fork, char *str)
{
	pthread_mutex_lock(&fork->mutex_fork);
	if (fork->fork)
	{
		fork->fork--;
		pthread_mutex_unlock(&fork->mutex_fork);
		print_action(philo, str);
		return (1);
	}
	pthread_mutex_unlock(&fork->mutex_fork);
	return (0);
}

int	get_fork(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < 2)
	{
		if (is_dead(philo))
			return (0);
		i += one_fork(philo, philo, "Has taken the 1 fork");
		philo->index++;
		if (is_dead(philo))
			return (0);
		i += one_fork(philo, philo, "Has taken the 2 fork");
	}
	return (1);
}

int	eat(t_philo *philo)
{
	if (!get_fork(philo))
		return (0);
	print_action(philo, "The philo is eating");
	philo->death = timestamp() + philo->table->time_eat;
	philo->eated++;
	return (philo_wait(philo, philo->ate));
}

void	return_forks(t_philo *philo)
{
	pthread_mutex_lock(&philo->mutex_fork);
	philo->fork++;
	pthread_mutex_unlock(&philo->mutex_fork);
	philo->index++;
	pthread_mutex_lock(&philo->mutex_fork);
	philo->fork++;
	pthread_mutex_unlock(&philo->mutex_fork);
}

int	haven_eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->mutexes->mutex_eat);
	if (philo->eated == philo->table->meals_limit)
	{
		philo->mutexes->eated--;
		if (!philo->mutexes->eated)
		{
			pthread_mutex_unlock(&philo->mutexes->mutex_eat);
			pthread_mutex_lock(&philo->mutexes->mutex_stop);
			philo->ate = 1;
			pthread_mutex_unlock(&philo->mutexes->mutex_eat);
		}
		else
			pthread_mutex_unlock(&philo->mutexes->mutex_eat);
		return (0);
	}
	pthread_mutex_unlock(&philo->mutexes->mutex_eat);
	return (1);
}
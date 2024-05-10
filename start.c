/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymometto <ymometto@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 15:23:53 by ymometto          #+#    #+#             */
/*   Updated: 2024/05/09 15:35:48 by ymometto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philos.h"

int	start_mutex(t_args *philo)
{
	int	index;

	index = philo->num_philo;
	while (index > 0)
	{
		if (pthread_mutex_init(&(philo->forks[index]), NULL))
			return (1);
		index++;
	}
	return (0);
}

int	start_philosophers(t_args *philo)
{
	int			index;
	int			num_p;
	pthread_t	*philos;

	index = 1;
	num_p = philo->num_philo;
	philos = malloc(sizeof(pthread_t) * num_p);
	while (index <= philo->num_philo)
	{
		pthread_create((philos + index), NULL, &routine, NULL);
		index++;
		}
	index = 1;
	while (index <= philo->num_philo)
	{
		pthread_join(philos[index], NULL);
		index++;
	}
	free(philos);
	return (0);
}

int	create_threads(t_args *philo, char **argv)
{
	philo->num_philo = ft_atoi(argv[1]);
	philo->time_death = ft_atoi(argv[2]);
	philo->time_eat = ft_atoi(argv[3]);
	philo->time_sleep = ft_atoi(argv[4]);
	if (philo->num_philo < 2 || philo->time_death < 0
		|| philo->time_eat < 0 || philo->time_sleep < 0
		|| philo->num_philo > 200)
		return (0);
	if (argv[5])
	{
		philo->num_eats = ft_atoi(argv[5]);
		if (philo->num_eats <= 0)
			return (1);
	}
	else
		philo->num_eats = -1;
	if (start_mutex(philo))
		return (2);
	if (start_philosophers(philo))
		return (1);
	return (0);
}

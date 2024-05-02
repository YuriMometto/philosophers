/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymometto <ymometto@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 15:23:53 by ymometto          #+#    #+#             */
/*   Updated: 2024/04/25 18:14:09 by ymometto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	start_mutex(t_philo *philo)
{
	
}

int	start_philo(t_philo *philo)
{
	int	index;

	index = 1;
	while (index <= philo->num_philo)
	{
		pthread_create(philos + index, NULL, &routine, NULL);
		index++;
	}
	index = 1;
	while (index <= philo->num_philo)
	{
		pthread_join(philos[index]);
		index++;
	}
}

int     create_threads(t_philo *philo, char **argv)
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
        if(start_mutex(philo))
                return (2);
        start_philosophers(philo);
        return (0);
}

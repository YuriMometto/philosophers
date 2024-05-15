/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymometto <ymometto@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 15:30:41 by ymometto          #+#    #+#             */
/*   Updated: 2024/05/15 15:41:22 by ymometto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
// ceiar routine
void	init_philo(t_table *table)
{
	int	i;
	
	i = 0;
	table->philos = malloc(sizeof(t_philo) * table->nbr_philo);
	if (!(table->philos))
	{
		free(table->philos)
		return(NULL);
	}
	while (i < table->nbr_philo)
    {
        table->philos[i].index = i + 1;
        table->philos[i].nbr_meals = 0;
        table->philos[i].full = false;
        table->philos[i].last_meal_time = 0;
        table->philos[i].fork = i;
        table->philos[i].mutex_fork = table->philos[i].mutex_fork;
        table->philos[i].table = table;
		printf("philo index-> %d\n", table->philos[i].index);
        pthread_create(&table->philos->thread_id[i], NULL, routine, &table->philos[i]);
		i++;
    }
	i = 0;
	while (i < table->nbr_philo)
	{
        pthread_join(table->philos[i].thread_id, NULL);
		i++;
	}
}

int	init_mutex(t_table *table)
{
	int	i;

	i = 0;
	while(i < table->nbr_philo)
		if (pthread_mutex_init(&table->philos[i++].mutex_fork, NULL))
			return (1);
	return (0);
}

int	data_init(t_table *table, char **argv)
{
	table->nbr_philo = ft_atoi(argv[1]);
	table->time_die = ft_atoi(argv[2]);
	table->time_eat = ft_atoi(argv[3]);
	table->time_sleep = ft_atoi(argv[4]);
	table->start_simulation = 0;
	table->end_simulation = false;
	if (argv[5])
	{
		table->meals_limit = ft_atoi(argv[5]);
		if (table->meals_limits <= 0)
			return (1);
	}
	else
		table->meals_limit = -1;
	if (init_mutex(table))
		return (2);
	if (init_philo(table))
		return (1);
	return (0);
}

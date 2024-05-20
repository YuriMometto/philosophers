/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymometto <ymometto@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 15:30:41 by ymometto          #+#    #+#             */
/*   Updated: 2024/05/20 14:06:24 by ymometto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
// ceiar routine
void	init_philo(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->nbr_philo)
	{
		table->philos[i].index = i + 1;
		table->philos[i].last_meal_time = 0;
		table->philos[i].fork = i + 1;
		table->philos[i].mutex_fork = table->philos[i].mutex_fork;
		table->philos[i].table = table;
		printf("philo index-> %ld\n", table->philos[i].index);
		pthread_create(&table->philos[i].thread_id, NULL,
			routine, &table->philos[i]);
		i++;
	}
}

void	init_mutex(t_table *table, t_mutexes *mutexes)
{
	mutexes->eated = (long)table->philos;
	pthread_mutex_init(&mutexes->mutex_stop, NULL);
	pthread_mutex_init(&mutexes->mutex_print, NULL);
	pthread_mutex_init(&mutexes->mutex_eat, NULL);
}

void	data_init(t_table *table, char **argv)
{
	int		i;

	table->nbr_philo = ft_atoi(argv[1]);
	table->time_die = ft_atoi(argv[2]);
	table->time_eat = ft_atoi(argv[3]);
	table->time_sleep = ft_atoi(argv[4]);
	if (argv[5])
		table->meals_limit = ft_atoi(argv[5]);
	table->start_simulation = 0;
	table->end_simulation = 0;
	table->philos = malloc(sizeof(t_philo) * table->nbr_philo);
	pthread_create(&table->watcher, NULL, monitor, table);
	pthread_detach(table->watcher);
	init_philo(table);
	i = 0;
	while (i < table->nbr_philo)
	{
        pthread_join(table->philos[i].thread_id, NULL);
		i++;
	}
	free(table->philos);
}

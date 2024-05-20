/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymometto <ymometto@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 15:30:58 by ymometto          #+#    #+#             */
/*   Updated: 2024/05/20 14:05:56 by ymometto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_action(t_philo *philo, char *str)
{
	if (is_dead(philo))
		return;
	pthread_mutex_lock(&philo->mutexes->mutex_print);
	printf("philosopher [%ld] %s\n", philo->index, str);
	pthread_mutex_unlock(&philo->mutexes->mutex_print);
}

void	*monitor(void *arg)
{
	t_philo *watcher;
	t_table	*table;
	int		i;

	table = arg;
	i = 0;
	while(1)
	{
		watcher = &table->philos[i];
		if(watcher->death == 1)
		{
			table->end_simulation = 1;
			pthread_mutex_lock(&watcher->mutexes->mutex_print);
			printf("philosopher[%ld] died\n", table->philos[i].index);
			pthread_mutex_unlock(&watcher->mutexes->mutex_print);
			break;
		}
		if(watcher->full == 1)
			watcher->stop = 1;
		if(i == table->nbr_philo)
			i = 0;
		i++;
	}
	return (NULL);
}

void	*routine(void *arg)
{
	t_philo *philo;

	philo = arg;
	philo->time_to_death = timestamp() + philo->table->time_die;
	if(philo->index % 2 == 0)
		usleep(100);
	while(1)
	{
		print_action(philo,"pensando de cria");
		if(!eat(philo))
			break;
		if(!philo_sleep(philo))
			break;
	}
	return (NULL);
}

int	main(int argc, char **argv)
{
	t_table		*table;
	t_mutexes	*mutexes;

	table = malloc(sizeof(t_table));
	mutexes = malloc(sizeof(t_mutexes));
	if (!table)
		return (free(table), 0);
	if (argc == 5 || argc == 6)
	{
		//start  - check input before putting into table
		//put_input(&table,argv);
		if (check_arguments(argc, argv))
			return (0);
		init_mutex(table, mutexes);
		data_init(table, argv);
		//start_dinner(&table);
		//leaks - > philos full || 1 philo died
		//clean_table(&table);
	}
	else
		print_error("INVALID ARGUMENTS\n");
}

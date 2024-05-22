/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymometto <ymometto@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 13:45:28 by ymometto          #+#    #+#             */
/*   Updated: 2024/05/22 13:45:31 by ymometto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int c, char **v)
{
	t_table	table;

	memset(&table, 0, sizeof(t_table));
	if (c < 5 || c > 6)
	{
		printf("Error: Invalid arguments\n");
		return (1);
	}
	table.start_time = get_current_time();
	table.num_philos = ft_atoi(v[1]);
	table.time_to_die = ft_atoi(v[2]);
	table.time_to_eat = ft_atoi(v[3]);
	table.time_to_sleep = ft_atoi(v[4]);
	if (v[5])
		table.philo_must_eat = ft_atoi(v[5]);
	create_philos(&table);
	free(table.philos);
	free_forks(table.forks, table.num_philos);
	return (0);
}

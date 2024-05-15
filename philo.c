/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymometto <ymometto@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 15:30:58 by ymometto          #+#    #+#             */
/*   Updated: 2024/05/15 16:01:23 by ymometto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_arguments(int argc, char **argv)
{
	int	i;

	i = 0;
	if((ft_atoi(argv[1]) < 1) || (ft_atoi(argv[1]) > 200))
	{
		print_error(RED"Put only 1-200 philosophers\n");
		return (1);
	}
	if(ft_atoi(argv[2]) < 60
	|| ft_atoi(argv[3]) < 60
	|| ft_atoi(argv[4]) < 60)
	{
		print_error(RED"Timestamps needs to be greater than 60\n");
		return (1);
	}
	while (i < argc)
	{
		if ((!ft_isnbr(argv[index]))
			&& (ft_atoi(argv[index]) <= 0))
			return (1);
		else if (ft_atoi(argv[index]) == 1)
			return (1);
		index++;
	}
	return (0);
}

int	main(int argc,char **argv)
{
	t_table	*table;

	table = malloc(sizeof(t_table));
	if (!table)
	{
		free(table);
		return (0);
	}
	if(argc == 5 || argc == 6)
	{
		//start  - check input before putting into table
		//put_input(&table,argv);
		if (check_arguments(&table, argv))
			return (0);
		//printf("philos-> %d\ndie-> %ld\neat-> %ld\nsleep-> %ld\n",table.nbr_philo,table.time_die,table.time_eat,table.time_sleep);
		data_init(&table,argv);

		//start_dinner(&table);

		//leaks - > philos full || 1 philo died
		//clean_table(&table);
	}
	else
		print_error(RED"INVALID ARGUMENTS\n");
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymometto <ymometto@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 13:16:51 by ymometto          #+#    #+#             */
/*   Updated: 2024/05/09 15:21:05 by ymometto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philos.h"

int	check_args(int argc, char **argv)
{
	int	index;

	index = 1;
	if (argc != 5 && argc != 6)
	{
		printf("%s\n", "invalid parameter");
		printf("%s", "<number_of_philosophers> <time_to_die> ");
		printf("%s\n", "<time_to_eat> <time_to_sleep>");
		return (1);
	}
	else
	{
		while (index < argc)
		{
			if ((!ft_isnbr(argv[index]))
				&& (ft_atoi(argv[index]) <= 0))
				return (1);
			else if (ft_atoi(argv[index]) == 1)
				return (1);
			index++;
		}
	}
	return (0);
}

void	*routine()
{
	
}


int	main(int argc, char **argv)
{
	t_args	*philo;

	philo = malloc(sizeof(t_args));
	if (!philo)
	{
		free(philo);
		return (0);
	}
	if (check_args(argc, argv) == 1)
		return (0);
	printf("%d\n", create_threads(philo, argv));
	return (0);
}

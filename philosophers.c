/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymometto <ymometto@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 13:16:51 by ymometto          #+#    #+#             */
/*   Updated: 2024/04/18 14:13:58 by ymometto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philos.h"

long int	ft_isdigit(long int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	else
		return (0);
}

int	ft_isnbr(char *nbr)
{
	int	index;

	index = 0;
	if (nbr[0] == '-')
		return (0);
	while (nbr[index])
	{
		if (!ft_isdigit(nbr[index]))
			return (0);
		index++;
	}
	return (1);
}

long int	ft_atoi(const char *nptr)
{
	long int	index;
	long int	signal;
	long int	counter;

	counter = 0;
	signal = 1;
	index = 0;
	while ((nptr[index] >= 9 && nptr[index] <= 13) || nptr[index] == ' ')
		index++;
	if (nptr[index] == '+' || nptr[index] == '-')
	{
		if (nptr[index] == '-')
			signal *= -1;
		index++;
	}
	while (nptr[index] >= '0' && nptr[index] <= '9')
		counter = counter * 10 + (nptr[index++] - '0');
	return (counter * signal);
}

int	check_args(int argc, char **argv)
{
	int	index;

	index = 1;
	if (argc < 5 || argc > 6)
	{
		printf("%s\n", "invalid parameter");
		printf("%s", "<number_of_philosophers> <time_to_die> <time_to_eat> <time_to_sleep>");
	}
	else
	{
		while (index < argc)
		{
			if ((!ft_isnbr(ft_atoi(argv[index]))) && (ft_atoi(argv[]) <= 0))
				return (1);
			else if (ft_atoi(argv[index]) == 1)
				return (1);
			index++;
		}
	}
	return (0);
}

void	create_threads(int argc, char **argv)
{
	int	index;

	if (argc == 5)
	{
		
	}
}

int	main(int argc, char **argv)
{
	int	number_of_philosophers;
	int time_to_die;
	int time_to_eat;
	int	time_to_sleep;
	int	number_of_times_each_philosophers;

	if (check_args(argc, argv) == 1)
		return (0);
	number_of_philosophers = argv[1];
	time_to_die = argv[2];
	time_to_eat = argv[3];
	time_to_sleep = argv[4];
	if (argc == 6)
		number_of_times_each_philosophers = argv[5];
	
	return(0);
}

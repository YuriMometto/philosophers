/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymometto <ymometto@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 13:16:51 by ymometto          #+#    #+#             */
/*   Updated: 2024/04/25 15:23:42 by ymometto         ###   ########.fr       */
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
	int	index = 0;

	while (index < 10000000)
		index++;
}

int	create_threads(t_philo *philo, char **argv)
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

int	main(int argc, char **argv)
{
	t_philo	philo;

	if (check_args(argc, argv) == 1)
		return (0);
	printf("%d\n", create_threads(&philo, argv));
	return (0);
}

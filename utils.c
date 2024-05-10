/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymometto <ymometto@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 15:10:20 by ymometto          #+#    #+#             */
/*   Updated: 2024/05/09 15:15:37 by ymometto         ###   ########.fr       */
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

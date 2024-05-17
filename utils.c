/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymometto <ymometto@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 15:31:14 by ymometto          #+#    #+#             */
/*   Updated: 2024/05/17 13:59:33 by ymometto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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

char	*valid_input(char *str)
{
	int		len;
	char	*nbr;

	len = 0;
	while (*str && *str == ' ')
		++str;
	if (*str == '+')
		++str;
	if (*str == '-')
		print_error(RED"Negative numbers aren't accepted\n");
	if (!(*str >= '0' && *str <= '9'))
		print_error(RED"Not a correct number!\n");
	nbr = str;
	while (*str++ >= '0' && *str++ <= '9')
		len++;
	if (len > 10)
		print_error(RED"Number too big\n");
	return (nbr);
}

long	ft_atoi(char *str)
{
	long	res;

	res = 0;
	str = valid_input(str);
	while (*str && (*str >= '0' && *str <= '9'))
	{
		res = (res * 10) + (*str - '0');
		str++;
	}
	if (res > INT_MAX)
		print_error(RED"Number too big\n");
	return (res);
}

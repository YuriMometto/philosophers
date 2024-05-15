/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymometto <ymometto@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 15:44:32 by ymometto          #+#    #+#             */
/*   Updated: 2024/05/15 15:46:43 by ymometto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	print_error(char *error)
{
	printf(RED"%s\n",error);
	printf(G"USAGE: <PHILO> <DIE> <EAT> <SLEEP> [LIMIT_MEALS]\n");
	return (1);
}

int	error_type(int error)
{
	if (error == 1)
		error_message("Some invalid argument!");
	else if (error == 2)
		error_message("Failure in the creating mutex!");
	return (1);
}


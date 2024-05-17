/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymometto <ymometto@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 15:44:32 by ymometto          #+#    #+#             */
/*   Updated: 2024/05/17 10:10:29 by ymometto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	print_error(char *error)
{
	printf("%s\n", error);
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

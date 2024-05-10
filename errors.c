/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymometto <ymometto@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 13:43:52 by ymometto          #+#    #+#             */
/*   Updated: 2024/05/03 09:14:52 by ymometto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philos.h"

int	error_message(char *msg)
{
	printf("Error: %s\n", msg);
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

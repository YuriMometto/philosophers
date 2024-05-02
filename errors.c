/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymometto <ymometto@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 13:43:52 by ymometto          #+#    #+#             */
/*   Updated: 2024/04/25 14:23:58 by ymometto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philos.h"

int	error_message(char *msg)
{
	int	index;

	index = 0;
	while (msg[index])
		index++;
	printf("Error: %s\n", msg);
	return (1);
}

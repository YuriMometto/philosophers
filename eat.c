/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymometto <ymometto@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 14:39:07 by ymometto          #+#    #+#             */
/*   Updated: 2024/05/17 15:10:48 by ymometto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	eat(t_philo *philo)
{
	if (!get_fork(philo))
		return (0);
	print_action(philo, "The philo is eating");
	philo->death = timestamp() + &philo->table.time_eat;
	while ()
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymometto <ymometto@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 12:50:10 by ymometto          #+#    #+#             */
/*   Updated: 2024/04/25 18:14:06 by ymometto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOS_H
# define PHILOS_H

# include <pthread.h>
# include <stdio.h>

struct	s_philo;

typedef struct s_philosophers
{
	struct s_philo	*philo;
}	t_philosophers;

typedef struct s_philo
{
	int				num_philo;
	int				time_death;
	int				time_eat;
	int				time_sleep;
	pthread_mutex_t	forks[200];
	t_philosophers	philos[200];
}	t_philo;

long int	ft_atoi(const char *nptr);
long int	ft_isdigit(long int c);
int			check_args(int argc, char **argv);
int			create_threads(int argc, char **argv);

#endif

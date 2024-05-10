/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymometto <ymometto@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 12:50:10 by ymometto          #+#    #+#             */
/*   Updated: 2024/05/09 15:57:57 by ymometto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOS_H
# define PHILOS_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_philosophers
{
	struct s_philo	*args;
}	t_philosophers;

typedef struct s_args
{
	int				num_philo;
	int				time_death;
	int				time_eat;
	int				time_sleep;
	int				num_eats;
	pthread_mutex_t	forks;
}	t_args;

//CHECK_ARGS
long int	ft_atoi(const char *nptr);
long int	ft_isdigit(long int c);
int			ft_isnbr(char *nbr);
int			check_args(int argc, char **argv);
//INIT_FUNCTIONS
int			create_threads(t_args *philo, char **argv);
int			start_philo(t_args *philo);
int			start_mutex(t_args *philo);
//ERROR_MANAGEMANT
int			error_message(char *msg);
int			error_type(int error);
//
#endif

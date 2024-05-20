/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btaveira <btaveira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 11:31:48 by btaveira          #+#    #+#             */
/*   Updated: 2024/05/17 15:11:37 by ymometto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <pthread.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <limits.h>
# include <stdbool.h>

/*-------------STRUCTS-------------*/

typedef struct s_philo	t_philo;

typedef struct s_table
{
	long			nbr_philo;
	long			time_die;
	long			time_eat;
	long			time_sleep;
	long			meals_limit;
	long			start_simulation;
	long			end_simulation;
	pthread_t		watcher;
	t_philo			*philos;
}		t_table;

typedef struct s_mutexes
{
	long			eated;
	pthread_mutex_t	mutex_print;
	pthread_mutex_t	mutex_eat;
	pthread_mutex_t	mutex_stop;
}		t_mutexes;

typedef struct s_philo
{
	long				index;
	long				fork;
	long				nbr_meals;
	long				full;
	long				ate;
	long				eated;
	long				death;
	long				last_meal_time;
	long				time_to_death;
	long				stop;
	pthread_t			thread_id;
	pthread_mutex_t		mutex_fork;
	t_table				*table;
	t_mutexes			*mutexes;
}		t_philo;

/*------------------PROTO----------------------*/
//ERROR TREATEMENT
int			print_error(char *error);
int			check_arguments(int argc, char **argv);
//INIT
void		data_init(t_table *table, char **argv);
void		init_mutex(t_table *table, t_mutexes *mutexes);
void		init_philo(t_table *table);
//UTILS
int			ft_isnbr(char *nbr);
long int	ft_isdigit(char c);
long		ft_atoi(char *str);
char		*valid_input(char *str);
void		print_action(t_philo *philo, char *str);
//ROUTINE
void		*monitor(void *arg);
void		*routine(void *arg);
//ACTIONS
int			one_fork(t_philo *philo, t_philo *fork, char *str);
int			get_fork(t_philo *philo);
void		return_forks(t_philo *philo);
int			haven_eat(t_philo *philo);
int			is_dead(t_philo *philo);
int			philo_wait(t_philo *philo, long act_time);
int			philo_sleep(t_philo *philo);
int			eat(t_philo *philo);
long		timestamp(void);
#endif

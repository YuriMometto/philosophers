/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymometto <ymometto@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 12:50:10 by ymometto          #+#    #+#             */
/*   Updated: 2024/04/18 14:09:58 by ymometto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOS_H
# define PHILOS_H

# include <pthread.h>
# include <stdio.h>

long int	ft_atoi(const char *nptr);
long int	ft_isdigit(long int c);
int			check_args(int argc, char **argv);
void		create_threads(int argc, char **argv);

#endif

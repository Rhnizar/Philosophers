/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhnizar <rrhnizar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 21:05:33 by rrhnizar          #+#    #+#             */
/*   Updated: 2023/03/07 12:58:52 by rrhnizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <pthread.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>

int		cheack(int argc, char **argv);
int		ft_atoi(char *str);

///////// tasks threads ////////
void	*eating(void *x);
void	*sleeping(void *x);
void	*thinking(void *x);
////////////////////////////////////////////////

//////////// struct argv the philo /////////

typedef struct s_philo
{
	int	num_of_philo;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	num_each_philo_eat;
	int	num_of_fork;
}				t_philo;

#endif
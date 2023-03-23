/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhnizar <rrhnizar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 21:05:33 by rrhnizar          #+#    #+#             */
/*   Updated: 2023/03/23 16:24:40 by rrhnizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <pthread.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>

///////////// calcul time ///////
typedef struct s_time
{
	struct timeval	tv;
	long int		start_time;
	long int		current_time;
}				t_time;

// typedef struct s_ph
// {
// 	pthread_t	philo;
// 	int			id;
// 	int			id_ph;
// 	int			time_to_die;
// 	int			time_to_eat;
// 	int			time_to_sleep;
// 	int			right_fork_id;
// 	int			left_fork_id;
// 	long int	last_time_eating;
// }	t_ph;

typedef struct s_ph
{
	pthread_t	philo;
	int			id;
	int			id_ph;
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	int			right_fork_id;
	int			left_fork_id;
	long int	last_time_eating;
	int			num_of_philo;
	int			num_each_philo_eat;

	pthread_mutex_t	*th_m;
	t_time			t;
}	t_ph;

// typedef struct s_data
// {
// 	int				id;
// 	int				num_of_philo;
// 	int				num_each_philo_eat;
// 	t_ph			*ph;
// 	pthread_mutex_t	*th_m;
// 	t_time			t;
// }				t_data;

int		cheack(int argc, char **argv);
int		ft_atoi(char *str);
void	init2(int argc, char **argv, t_ph *ph);

#endif
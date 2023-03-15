/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhnizar <rrhnizar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 21:05:33 by rrhnizar          #+#    #+#             */
/*   Updated: 2023/03/15 17:38:00 by rrhnizar         ###   ########.fr       */
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


///////////// calcul time ///////
typedef struct s_time
{
	struct timeval tv;
	long int		start_time;
	long int		current_time;
}				t_time;

//////////// struct t9dar tkhdme //////

typedef struct s_philosopher
{
	int	id_philo;
	int	forks;
	int right_fork_id;
	int	left_fork_id;
}				t_philosopher;

//////////// struct argv the philo /////////

typedef struct s_philo
{
	int				num_of_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				num_each_philo_eat;
	t_philosopher	ph;
	t_time			t;
}				t_philo;




#endif
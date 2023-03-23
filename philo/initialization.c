/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhnizar <rrhnizar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 13:06:59 by rrhnizar          #+#    #+#             */
/*   Updated: 2023/03/23 16:24:17 by rrhnizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init2(int argc, char **argv, t_ph *ph)
{
	int	i;

	i = 0;
	gettimeofday(&(ph->t.tv), NULL);
	ph->t.start_time = ((ph->t.tv.tv_sec) * 1000000) + ph->t.tv.tv_usec;
	ph->t.current_time = ph->t.start_time;
	ph->num_of_philo = ft_atoi(argv[1]);
	while (i < ft_atoi(argv[1]))
	{
		ph[i].id_ph = i + 1;
		ph[i].time_to_die = ft_atoi(argv[2]) * 1000;
		ph[i].time_to_eat = ft_atoi(argv[3]) * 1000;
		ph[i].time_to_sleep = ft_atoi(argv[4]) * 1000;
		ph[i].right_fork_id = i;
		ph[i].left_fork_id = (i + ph->num_of_philo - 1) % ph->num_of_philo;
		ph[i].last_time_eating = ph->t.start_time;
		i++;
	}
	if (argc == 6)
		ph->num_each_philo_eat = ft_atoi(argv[5]);
	else
		ph->num_each_philo_eat = 0;
}



//// .  / // / / init dat a/////
// void	init2(int argc, char **argv, t_ph *ph)
// {
// 	int	i;

// 	i = 0;
// 	gettimeofday(&(ph->t.tv), NULL);
// 	ph->t.start_time = ((ph->t.tv.tv_sec) * 1000000) + ph->t.tv.tv_usec;
// 	ph->t.current_time = ph->t.start_time;
// 	ph->num_of_philo = ft_atoi(argv[1]);
// 	while (i < ft_atoi(argv[1]))
// 	{
// 		data->ph[i].id_ph = i + 1;
// 		data->ph[i].time_to_die = ft_atoi(argv[2]) * 1000;
// 		data->ph[i].time_to_eat = ft_atoi(argv[3]) * 1000;
// 		data->ph[i].time_to_sleep = ft_atoi(argv[4]) * 1000;
// 		data->ph[i].right_fork_id = i;
// 		data->ph[i].left_fork_id = (i + data->num_of_philo - 1) % data->num_of_philo;
// 		data->ph[i].last_time_eating = data->t.start_time;
// 		i++;
// 	}
// 	if (argc == 6)
// 		data->num_each_philo_eat = ft_atoi(argv[5]);
// 	else
// 		data->num_each_philo_eat = 0;
// }
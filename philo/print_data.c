/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhnizar <rrhnizar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 13:38:53 by rrhnizar          #+#    #+#             */
/*   Updated: 2023/03/23 13:39:18 by rrhnizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_print_data_all_philos(t_data data)
{
	int	i;
	i = 0;
	while(i < data.num_of_philo)
	{
		printf("\n-------------   philo %d    -------------\n", data.ph[i].id_ph);
		printf("num_of_philo       : %d\n\n", data.num_of_philo);
		printf("num_each_philo_eat : %d\n\n", data.num_each_philo_eat);
		printf("time_to_die        : %d\n\n", data.ph[i].time_to_die);
		printf("time_to_eat        : %d\n\n", data.ph[i].time_to_eat);
		printf("time_to_sleep      : %d\n\n", data.ph[i].time_to_sleep);
		printf("left_fork_id       : %d\n\n", data.ph[i].left_fork_id);
		printf("right_fork_id      : %d\n\n", data.ph[i].right_fork_id);
		printf("===============================================================\n");
		i++;
	}
}

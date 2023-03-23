/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhnizar <rrhnizar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 18:47:47 by rrhnizar          #+#    #+#             */
/*   Updated: 2023/03/23 16:20:31 by rrhnizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*tasks(void *x)
{
	t_data		*data;

	// if (data->ph[data->id].id_ph % 2 == 0)
		// 	usleep(100);
	data = (t_data *)x;
	while (1)
	{
		gettimeofday(&(data->t.tv), NULL);
		printf("%ld %d is thinking\n",  (((data->t.tv.tv_sec) * 1000000) 
			+ data->t.tv.tv_usec - data->t.start_time) / 1000, data->ph[data->id].id_ph);

		// printf("======>1 %d time %ld ==> test\n",data->id ,(((data->t.tv.tv_sec) * 1000000) + data->t.tv.tv_usec - data->t.start_time) / 1000);
		printf("%ld %d is sleeping\n", (((data->t.tv.tv_sec) * 1000000) 
			+ data->t.tv.tv_usec - data->t.start_time) / 1000, data->ph[data->id].id_ph);
		usleep(data->ph[data->id].time_to_sleep);
		// gettimeofday(&(data->t.tv), NULL);
		// printf("=======>2 %d time %ld ==> test\n",data->id ,(((data->t.tv.tv_sec) * 1000000) + data->t.tv.tv_usec - data->t.start_time) / 1000);
		exit(1);
		pthread_mutex_lock(&(data->th_m[data->ph[data->id].left_fork_id]));
		printf("%ld %d has taken a fork\n", (((data->t.tv.tv_sec) * 1000000) 
			+ data->t.tv.tv_usec - data->t.start_time) / 1000, data->ph[data->id].id_ph);

		pthread_mutex_lock(&(data->th_m[data->ph[data->id].right_fork_id]));
		printf("%ld %d has taken a fork\n", (((data->t.tv.tv_sec) * 1000000) 
			+ data->t.tv.tv_usec - data->t.start_time) / 1000, data->ph[data->id].id_ph);
		data->ph[data->id].last_time_eating = ((data->t.tv.tv_sec) * 1000000) + data->t.tv.tv_usec - data->t.start_time;
		printf("%ld %d is eating\n",  (((data->t.tv.tv_sec) * 1000000) 
			+ data->t.tv.tv_usec - data->t.start_time) / 1000, data->ph[data->id].id_ph);
		usleep(data->ph[data->id].time_to_eat);
		pthread_mutex_unlock(&(data->th_m[data->ph[data->id].left_fork_id]));
		pthread_mutex_unlock(&(data->th_m[data->ph[data->id].right_fork_id]));	
		
	}
	return (NULL);
}

void	create_threads(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_of_philo)
	{
		data->id = i;
		pthread_create(&(data->ph[i++].philo), NULL, tasks, data);
		usleep(100);
	}
	i = 0;
	while (i < data->num_of_philo)
		pthread_join(data->ph[i++].philo, NULL);
}


int main(int argc, char **argv)
{
	t_ph	*ph;
	int		i;

	i = 0;
	ph = malloc(sizeof(t_ph) * ft_atoi(argv[1]));
	// data.ph = malloc(sizeof(t_ph) * ft_atoi(argv[1]));
	ph->th_m = malloc(sizeof(pthread_mutex_t) * ft_atoi(argv[1]));
	if (!(ph) || !(ph->th_m))
		return (1);
	while (i < ft_atoi(argv[1]))
		pthread_mutex_init(&(ph->th_m[i]), NULL);

	if (cheack(argc, argv))
	{
		init2(argc, argv, &ph);
		create_threads(&ph);
	}
	else
		printf("noooooo\n");
	i = 0;
	while (i < ft_atoi(argv[1]))
		pthread_mutex_destroy(&(ph->th_m[i]));
	free(ph);
	free(ph->th_m);
	return (0);
}

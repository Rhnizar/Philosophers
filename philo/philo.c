/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhnizar <rrhnizar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 18:47:47 by rrhnizar          #+#    #+#             */
/*   Updated: 2023/03/20 15:39:25 by rrhnizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

///////////// calcul time ///////
typedef struct s_time
{
	struct timeval	tv;
	long int		start_time;
	long int		current_time;
}				t_time;

typedef struct s_ph
{
	pthread_t	philo;
	int			id_ph;
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	int			right_fork_id;
	int			left_fork_id;
	long int			last_time_eating;
}	t_ph;

typedef struct s_data
{
	int				id;
	int				num_of_philo;
	int				num_each_philo_eat;
	t_ph			*ph;
	pthread_mutex_t	*th_m;
	t_time			t;
}				t_data;

void	*tasks(void *x)
{
	t_data		*data;
	long int	ti;

	data = (t_data *)x;
	gettimeofday(&(data->t.tv), NULL);
	data->t.current_time = ((data->t.tv.tv_sec) * 1000000) + data->t.tv.tv_usec;
	ti = data->t.current_time - data->t.start_time;
	while (1)
	{
		if (data->t.current_time - data->ph[data->id].last_time_eating >= data->ph[data->id].time_to_die)
		{
			printf("philosopher %d is died \n", data->ph[data->id].id_ph);
			break ;
		}
		data->ph[data->id].last_time_eating = data->t.current_time;
		printf("test%d\n", data->ph[data->id].id_ph);
	}
	return(NULL);
}

void	init2(int argc, char **argv, t_data *data)
{
	int	i;

	i = 0;
	gettimeofday(&(data->t.tv), NULL);
	data->t.start_time = ((data->t.tv.tv_sec) * 1000000) + data->t.tv.tv_usec;
	data->t.current_time = data->t.start_time;
	data->num_of_philo = ft_atoi(argv[1]);
	while (i < ft_atoi(argv[1]))
	{
		data->ph[i].id_ph = i + 1;
		data->ph[i].time_to_die = ft_atoi(argv[2]) * 1000;
		data->ph[i].time_to_eat = ft_atoi(argv[3]) * 1000;
		data->ph[i].time_to_sleep = ft_atoi(argv[4]) * 1000;
		data->ph[i].right_fork_id = i;
		data->ph[i].left_fork_id = (i + data->num_of_philo - 1) % data->num_of_philo;
		data->ph[i].last_time_eating = data->t.start_time;
		i++;
	}
	if (argc == 6)
		data->num_each_philo_eat = ft_atoi(argv[5]);
	else
		data->num_each_philo_eat = 0;
}

void	create_threads(t_data *data)
{
	int	i;

	i = 0;
	while(i < data->num_of_philo)
	{
		data->id = i;
		pthread_create(&(data->ph[i++].philo), NULL, tasks, data);
		usleep(500);
	}
	i = 0;
	while (i < data->num_of_philo)
		pthread_join(data->ph[i++].philo, NULL);
}

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
int main(int argc, char **argv)
{
	t_data	data;
	int		i;

	i = 0;
	data.ph = malloc(sizeof(t_ph) * ft_atoi(argv[1]));
	data.th_m = malloc(sizeof(pthread_mutex_t) * ft_atoi(argv[1]));
	if (!(data.ph) || !(data.th_m))
		return (1);
	while (i < ft_atoi(argv[1]))
		pthread_mutex_init(&(data.th_m[i++]), NULL);

	if (cheack(argc, argv))
	{
		init2(argc, argv, &data);
		// ft_print_data_all_philos(data);
		create_threads(&data);
		// printf("%d\n", data.num_of_philo);
	}
	else
		printf("noooooo\n");
	i = 0;
	while (i < ft_atoi(argv[1]))
		pthread_mutex_destroy(&(data.th_m[i++]));
	free(data.ph);
	free(data.th_m);
	return (0);
}

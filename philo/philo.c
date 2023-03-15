/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhnizar <rrhnizar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 18:47:47 by rrhnizar          #+#    #+#             */
/*   Updated: 2023/03/15 18:18:25 by rrhnizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

///////////// initialization ///////////

void	init(int argc, char **argv, t_philo *philo)
{
	if (argc == 5 || argc == 6)
	{
		philo->num_of_philo = ft_atoi(argv[1]);
		philo->time_to_die = ft_atoi(argv[2]);
		philo->time_to_eat = ft_atoi(argv[3]);
		philo->time_to_sleep = ft_atoi(argv[4]);
		philo->ph.forks = 0;
		philo->t.start_time = 0;
		philo->t.current_time = 0;
		if (argc == 6)
			philo->num_each_philo_eat = ft_atoi(argv[5]);
		else
			philo->num_each_philo_eat = 0;
	}
}

/////////// all tasks the threads ///////////

void	*task(void	*philo)
{
	(void)philo;
	t_philo *philos;
	philos = (t_philo *)philo;
	gettimeofday(&(philos->t.tv), NULL);
	if(philos->t.start_time == 0)
		philos->t.start_time = (philos->t.tv.tv_sec / 1000) + (philos->t.tv.tv_usec * 1000);
	philos->t.current_time = (philos->t.tv.tv_sec / 1000) + (philos->t.tv.tv_usec * 1000);
	printf("%ld\n", philos->t.current_time - philos->t.start_time);
	return (NULL);
}
/////////////// full arr philosopher //////
// void	full_arr(int **arr, t_philo *philo)
// {
// 	int i;
// 	int	j;

// 	i = 0;
// 	j = 0;
	
// 	**arr = malloc(sizeof(int) * philo->num_of_philo);
// }
////////// create_thread ///////

void	create_thread(t_philo *philo)
{
	pthread_t	*th;
	int			i;

	th = malloc(sizeof(pthread_t) * philo->num_of_philo);
	if (!th)
		return ;
	i = 0;
	while (i != philo->num_of_philo)
	{
		philo->ph.id_philo = i;
		philo->ph.right_fork_id = (philo->ph.id_philo + 1) % philo->num_of_philo;
		philo->ph.left_fork_id = (philo->ph.id_philo + philo->num_of_philo - 1) % philo->num_of_philo;
		// printf("===> right_fork : %d\n", philo->ph.right_fork_id);
		// printf("===> left_fork : %d\n", philo->ph.left_fork_id);
		// exit(1);
		pthread_create(&th[i], NULL, task, philo);
		// usleep(100);
		i++;
	}
	i = 0;
	while (i != philo->num_of_philo)
		pthread_join(th[i++], NULL);
}

int	main(int argc, char **argv)
{
	t_philo	philo;

	if (cheack(argc, argv))
	{
		
		init(argc, argv, &philo);
		create_thread(&philo);
	}
	else
	{
		write(2, "Error\n", 6);
		return (1);
	}
	return (0);
}

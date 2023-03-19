/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xihaja_t9dar_tkhdme.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhnizar <rrhnizar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 17:28:41 by rrhnizar          #+#    #+#             */
/*   Updated: 2023/03/17 17:28:56 by rrhnizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/////// function to print /////////////
void	ft_to_print(t_philo *philo)
{
	long int timestamp_in_ms;

	gettimeofday(&(philo->t.tv), NULL);
	philo->t.current_time = (philo->t.tv.tv_sec * 1000) + (philo->t.tv.tv_usec / 1000);
	timestamp_in_ms = philo->t.current_time - philo->t.start_time;
	pthread_mutex_lock(&(philo->lock));
	printf("%ld philosopher %d	is thinking\n", timestamp_in_ms, philo->ph.id_philo + 1);
	pthread_mutex_unlock(&(philo->lock));
	
}
/////////// all tasks the threads ///////////

void	*tasks(void	*philo)
{
	t_philo *philos;

	philos = (t_philo *)philo;

	ft_to_print(philos);
	return (NULL);
}

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
		pthread_create(&th[i], NULL, tasks, philo);
		usleep(50);
		i++;
	}
	i = 0;
	while (i != philo->num_of_philo)
		pthread_join(th[i++], NULL);
}

int	main(int argc, char **argv)
{
	t_philo	philo;

	pthread_mutex_init(&(philo.lock), NULL);
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
	pthread_mutex_destroy(&(philo.lock));
	return (0);
}
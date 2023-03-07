/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhnizar <rrhnizar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 18:47:47 by rrhnizar          #+#    #+#             */
/*   Updated: 2023/03/07 21:00:20 by rrhnizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

////////// create_thread ///////

void	create_thread(int num_of_philo)
{
	pthread_t	*th;
	int			i;

	th = malloc(sizeof(pthread_t) * num_of_philo);
	if (!th)
		return ;
	i = 0;
	while (i != num_of_philo)
		pthread_create(&th[i++], NULL, eating, NULL);
	i = 0;
	while (i != num_of_philo)
		pthread_join(th[i++], NULL);
}

void	init(int argc, char **argv, t_philo *philo)
{
	if (argc == 5 || argc == 6)
	{
		philo->num_of_philo = ft_atoi(argv[1]);
		philo->time_to_die = ft_atoi(argv[2]);
		philo->time_to_eat = ft_atoi(argv[3]);
		philo->time_to_sleep = ft_atoi(argv[4]);
		philo->num_of_fork = philo->num_of_philo;
		if (argc == 6)
			philo->num_each_philo_eat = ft_atoi(argv[5]);
		else
			philo->num_each_philo_eat = 0;
	}
}

int	main(int argc, char **argv)
{
	t_philo	philo;

	if (cheack(argc, argv))
	{
		init(argc, argv, &philo);
		create_thread(philo.num_of_philo);
	}
	else
	{
		write(2, "Error\n", 6);
		return (1);
	}
	return (0);
}

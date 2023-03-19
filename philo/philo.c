/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhnizar <rrhnizar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 18:47:47 by rrhnizar          #+#    #+#             */
/*   Updated: 2023/03/19 17:26:14 by rrhnizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

typedef struct s_ph
{
	int	num_of_philo;
	int	id_ph;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	right_fork_id;
	int	left_fork_id;
	int	num_each_philo_eat;
}				t_ph;

void	*tasks(void *x)
{
	t_ph	*philo;
	
	philo = (t_ph *)x;
	if (philo->id_ph % 2 == 1)
		usleep (100);
	printf("test %d\n", (philo->id_ph));
	return(NULL);
}

void	create_thread(t_ph *philo)
{
	pthread_t	*th;
	t_ph		*ph;
	int			i;

	i = 0;
	th = malloc(sizeof(pthread_t) * 5);
	ph = malloc(sizeof(t_ph) * 5);
	while (i < 5)
	{
		pthread_create(&th[i++], NULL, tasks, philo);
		// usleep(50);
	}
	i = 0;
	while (i < 5)
		pthread_join(th[i++], NULL);
}
int main(int argc, char **argv)
{
	t_ph	philo;
	if(cheack(argc, argv))
	{
		philo.num_of_philo = ft_atoi(argv[1]);
		create_thread(&philo);
	}
	else
		printf("noooooo\n");	
	return (0);
}

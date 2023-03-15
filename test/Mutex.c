/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhnizar <rrhnizar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 10:24:03 by rrhnizar          #+#    #+#             */
/*   Updated: 2023/03/15 11:23:17 by rrhnizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct s_philo
{
	int num_philo;
	int	num_fork;
}				t_philo;

typedef	struct s_philosopher
{
	int	id;
	int	count_fork;
	char	*status;
}				t_philosopher;

void	init(t_philo	*ph)
{
	ph->num_philo = 5;
	ph->num_fork = 5;
}
pthread_mutex_t forkk;
void	*test(void *x)
{
	t_philosopher *philo;
	philo = (t_philosopher *)x;
	// printf("====>rr%d\n", philo->id);
	// exit(1);
	pthread_mutex_lock(&forkk);
	printf("hello %d\n", philo->id);
	// pthread_mutex_unlock(&forkk);
	return (NULL);
}

int main(void)
{
	pthread_t *th;
	t_philosopher	philo;
	int			i;
	i = 0;
	th= malloc(sizeof(pthread_t) * 50);
	if(!th)
		return(0);
	pthread_mutex_init(&forkk, NULL);
	while(i <= 50)
	{
		philo.id = i;
		philo.count_fork = 1;
		pthread_create(&th[i], NULL, test, &philo);
		usleep(100);
		i++;
	}
	i = 0;
	while (i <= 50)
		pthread_join(th[i++], NULL);
	pthread_mutex_destroy(&forkk);
	return(0);
}
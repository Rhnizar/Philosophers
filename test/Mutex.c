/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhnizar <rrhnizar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 10:24:03 by rrhnizar          #+#    #+#             */
/*   Updated: 2023/03/17 15:37:18 by rrhnizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

// typedef struct s_philo
// {
// 	int num_philo;
// 	int	num_fork;
// }				t_philo;

// typedef	struct s_philosopher
// {
// 	int	id;
// 	int	count_fork;
// 	char	*status;
// }				t_philosopher;

// void	init(t_philo	*ph)
// {
// 	ph->num_philo = 5;
// 	ph->num_fork = 5;
// }
// pthread_mutex_t forkk;
// void	*test(void *x)
// {
// 	t_philosopher *philo;
// 	philo = (t_philosopher *)x;
// 	// printf("====>rr%d\n", philo->id);
// 	// exit(1);
// 	pthread_mutex_lock(&forkk);
// 	printf("hello %d\n", philo->id);
// 	// pthread_mutex_unlock(&forkk);
// 	return (NULL);
// }

// int main(void)
// {
// 	pthread_t *th;
// 	t_philosopher	philo;
// 	int			i;
// 	i = 0;
// 	th= malloc(sizeof(pthread_t) * 50);
// 	if(!th)
// 		return(0);
// 	pthread_mutex_init(&forkk, NULL);
// 	while(i <= 50)
// 	{
// 		philo.id = i;
// 		philo.count_fork = 1;
// 		pthread_create(&th[i], NULL, test, &philo);
// 		usleep(100);
// 		i++;
// 	}
// 	i = 0;
// 	while (i <= 50)
// 		pthread_join(th[i++], NULL);
// 	pthread_mutex_destroy(&forkk);
// 	return(0);
// }

pthread_mutex_t arr_m[5];

void	*task(void *x)
{
	(void)x;
	pthread_mutex_lock(&arr_m[1]);
	printf("OOOooooo\n");
	return(NULL);
}

int main(void)
{
	pthread_t th[5];
	int i;
	i = 0;
	while(i != 5)
		pthread_mutex_init(&arr_m[i++], NULL);
	i = 0;
	while(i != 5)
	{
		pthread_create(&th[i], NULL, task, NULL);
		i++;
	}
	i = 0;
	while(i != 5)
		pthread_join(th[i++], NULL);
	i = 0;
	while(i != 5)
		pthread_mutex_destroy(&arr_m[i]);
	
	// pthread_mutex_init(&arr_m[i], NULL);
	// pthread_mutex_lock(&arr_m[i]);
	// printf("just test\n");
	// // pthread_mutex_unlock(&arr_m[i]);
	// pthread_mutex_destroy(&arr_m[i]);
	return 0;
}
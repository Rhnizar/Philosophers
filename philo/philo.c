/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhnizar <rrhnizar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 18:47:47 by rrhnizar          #+#    #+#             */
/*   Updated: 2023/03/05 12:46:41 by rrhnizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

void	*eating(void *x)
{
	(void)x;
	printf("I'am eating !!!\n");
	pthread_exit(0);
}
void	*sleeping(void *x)
{
	(void)x;
	printf("I'am sleeping !!!\n");
	pthread_exit(0);
}
void	*thinking(void	*x)
{
	(void)x;
	printf("I'am thinking !!!!\n");
	pthread_exit(0);
}
int main()
{
	pthread_t	t1;
	pthread_create(&t1, NULL, eating, NULL);
	pthread_create(&t1, NULL, sleeping, NULL);
	pthread_create(&t1, NULL, thinking, NULL);
	pthread_join(t1, NULL);
	return (0);
}
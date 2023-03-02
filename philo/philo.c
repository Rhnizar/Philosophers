/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhnizar <rrhnizar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 18:47:47 by rrhnizar          #+#    #+#             */
/*   Updated: 2023/03/02 20:27:19 by rrhnizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

void	*f1(void *x)
{
	printf("juste test thread %d\n", *(int *)x);
	pthread_exit(0);
}
int main()
{
	pthread_t thread1;
	int	*x;
	x = malloc(sizeof(int) * 4);
	*x = 9;

	printf("i'am processe parent!!!\n");
	pthread_create(&thread1, NULL, f1, (void *)x);
	pthread_join(thread1, NULL);
	return (0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usleep.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhnizar <rrhnizar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 11:26:21 by rrhnizar          #+#    #+#             */
/*   Updated: 2023/03/07 12:12:50 by rrhnizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

void	*Read(void *x)
{
	(void)x;
	printf("\033[0;31m");
	printf("this is Red\n");
	return (NULL);
}

void	*Green(void *x)
{
	(void)x;
	printf("\033[0;32m");
	printf("this is Green\n");
	return (NULL);
}

int main(int argc, char **argv) 
{
	if(argc == 2)
	{
		pthread_t	th[atoi(argv[1])];
		int i = 0;
		while(i != atoi(argv[1]))
		{
			pthread_create(&th[i], NULL, Read, NULL);
			usleep(5000);
			pthread_create(&th[i], NULL, Green, NULL);
			i++;
		}
		i = 0;
		while(i != atoi(argv[1]))
			pthread_join(th[i++], NULL);
	}
	else
		printf("error\n");
    return 0;
}
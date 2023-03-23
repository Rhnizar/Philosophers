/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_of_struct.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhnizar <rrhnizar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 17:10:18 by rrhnizar          #+#    #+#             */
/*   Updated: 2023/03/21 17:15:34 by rrhnizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <math.h>
#include <limits.h>

// typedef struct s_ph
// {
// 	int	id_ph;
// 	int num;
// }				t_ph;

// void	*test()
// {
// 	return (NULL);
// }

int main(void)
{
	// t_ph *ph;
	// int		i = 0;
	
	// ph = malloc(sizeof(t_ph) * 5);
	// while(i <= 5)
	// {
	// 	ph[i].id_ph = 1;
	// 	ph[i].num = 2;
	// 	i++;
	// }
	// printf("%d	%d\n", ph[5].id_ph, ph[5].num);
	// pthread_t th;

	// pthread_create(&th, NULL, &test, NULL);
	// pthread_join(th, NULL);
	// printf("%d\n", th);

	printf("%d", abs(-98));
	return (0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tasks_threads.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhnizar <rrhnizar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 12:34:40 by rrhnizar          #+#    #+#             */
/*   Updated: 2023/03/07 12:42:41 by rrhnizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//////// this is task eating ////////

void	*eating(void *x)
{
	(void)x;
	printf("I'am eating !!\n");
	return (NULL);
}

//////// this is task sleeping ////////

void	*sleeping(void *x)
{
	(void)x;
	printf("I'am sleeping !!\n");
	return (NULL);
}

//////// this is task thinking ////////

void	*thinking(void *x)
{
	(void)x;
	printf("I'am thinking !!\n");
	return (NULL);
}

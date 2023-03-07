/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhnizar <rrhnizar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 18:47:47 by rrhnizar          #+#    #+#             */
/*   Updated: 2023/03/07 11:19:43 by rrhnizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

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

////////// create_thread ///////

void	create_thread(int num_of_philo)
{
	pthread_t th[num_of_philo];
	int	i;

	i = 0;
	while (i != num_of_philo)
		pthread_create(&th[i++], NULL, eating, NULL);
	i = 0;
	while (i != num_of_philo)
		pthread_join(th[i++], NULL);
}

int	main(int argc, char **argv)
{
	if (cheack(argc, argv))
		create_thread(ft_atoi(argv[1]));
	else
	{
		write(2, "Error\n", 6);
		return (1);
	}
	return (0);
}

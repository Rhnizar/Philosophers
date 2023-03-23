/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   knowledge.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhnizar <rrhnizar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 14:19:45 by rrhnizar          #+#    #+#             */
/*   Updated: 2023/03/23 13:39:47 by rrhnizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
* What is deadlock : A deadlock is a situation in which two computer
		programs sharing the same resource are effectively
		preventing each other from accessing the resource, resulting in both programs ceasing to function.

* What is race of data : A data race occurs when: two or more threads
		in a single process access the same memory location concurrently,
		and. at least one of the accesses is for writing, and. the threads
		are not using any exclusive locks to control their accesses to that memory.
*
*/




//hado modification
			// while(i < data.num_of_philo)
			// {
			// 	// data->id = i;
			// 	pthread_create(&(data.ph[i++].philo), NULL, tasks, &(data));
			// 	usleep(100);
			// }
			// i = 0;
			// while (i < data.num_of_philo)
			// 	pthread_join(data.ph[i++].philo, NULL);
		// end modification
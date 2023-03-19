/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_of_struct.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhnizar <rrhnizar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 17:10:18 by rrhnizar          #+#    #+#             */
/*   Updated: 2023/03/19 17:15:49 by rrhnizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

typedef struct s_ph
{
	int	id_ph;
	int num;
}				t_ph;

int main(void)
{
	t_ph *ph;
	int		i = 0;
	
	ph = malloc(sizeof(t_ph) * 5);
	while(i <= 5)
	{
		ph[i].id_ph = 1;
		ph[i].num = 2;
		i++;
	}
	printf("%d	%d\n", ph[5].id_ph, ph[5].num);
	return (0);
}
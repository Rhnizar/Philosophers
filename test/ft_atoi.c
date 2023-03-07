/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhnizar <rrhnizar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 21:47:42 by rrhnizar          #+#    #+#             */
/*   Updated: 2023/03/06 21:58:02 by rrhnizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(char *str)
{
	int i;
	int res;
	int signe;

	res = 0;
	signe = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if(str[i] == '-')
	{
		signe *= -1;
		i++;
	}
	if(str[i] == '+' && str[i - 1] != '-')
		i++;
	
	while (str[i] >= '0' && str[i] <= '9')
	{
		res *= 10;
		res += str[i] - 48;
		i++;
	}
	return(res * signe);
}

#include <stdio.h>

int main(void)
{
	printf("%d\n", ft_atoi("+5555      "));
}
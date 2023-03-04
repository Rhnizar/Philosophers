/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhnizar <rrhnizar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 17:22:08 by rrhnizar          #+#    #+#             */
/*   Updated: 2023/03/04 19:45:57 by rrhnizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
int main() {
    char    *str;
    int     i;
    
    i = 0;
    str = malloc(sizeof(char) * 1);
    while (i < 10000000)
    {
        str[i] = 'a';
        i++;
    }
    printf("%s\n", str);
    return 0;
}

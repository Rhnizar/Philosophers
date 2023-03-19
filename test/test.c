/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhnizar <rrhnizar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 17:22:08 by rrhnizar          #+#    #+#             */
/*   Updated: 2023/03/15 13:19:22 by rrhnizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int r = 0;
void    *f1(void *x)
{
    (void)x;
    char *r;
    r = malloc(sizeof(char) * 5);
    if(!r)
    {
        perror("malloc_thread");
        return(NULL);
    }
    int i = 0;
    while (i < 5)
        r[i++] = 'a';
    printf("%s\n", r);
    return (NULL);
}

int main() 
{
    int **arr;
    int i;
    int	j;

	i = 0;
	
	arr = malloc(sizeof(int *) * 5);
    if(!arr)
        return (0);
    while (i < 5)
    {
	    arr[i] = malloc(sizeof(int) * 3);
        j = 0;
        while (j < 3)
        {
            arr[i][j] = 1;
            j++;
        }
        i++;
    }
    
    i = 0;
    while (i < 5)
    {
        j = 0;
        while (j < 3)
        {
            printf("%d\t", arr[i][0]);
            j++;
        }
        printf("\n");
        i++;
    }
    // while (i < 5)
    // {
	//     arr[i] = malloc(sizeof(int) * 3);
    //     arr[i][0] = 1;
    //     // printf("%d\n", i);
    //     // exit(1);
    //     arr[i][1] = 4;
    //     arr[i][2] = 1;
    //     i++;
    // }
    
    // while (i < 5)
    // {
    //     // printf("%d\n", arr[0][0]);
    //     // exit(1);
    //     printf("%d\n", arr[i][0]);
    //     i++;
    // }

    return 0;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhnizar <rrhnizar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 17:22:08 by rrhnizar          #+#    #+#             */
/*   Updated: 2023/03/06 16:23:16 by rrhnizar         ###   ########.fr       */
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
    pthread_t   *th;
    th = malloc(sizeof(pthread_t) * 1000000);
    if(!th)
    {
        perror("malloc");
        return(0);
    }
    int i = 0;
    while (1)
    {
        pthread_create(&th[i], NULL, f1, NULL);
        printf("===>%d\n", i);
        i++;
    }
    return 0;
}

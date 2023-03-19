# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rrhnizar <rrhnizar@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/02 18:39:46 by rrhnizar          #+#    #+#              #
#    Updated: 2023/03/17 13:10:31 by rrhnizar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

Name = philo

RFLAGS = -Wall -Werror -Wextra -I.

CC = cc ${RFLAGS}

SRCM = philo.c check_arg.c initialization.c

OBJM = ${SRCM:.c=.o}

%.o : %.c
	${CC} -c $< -o $@

all : ${Name}

${Name} : ${OBJM} philo.h
	${CC} ${OBJM} -o ${Name}
	
clean :
	rm -rf ${OBJM}

fclean : clean
	rm -rf ${Name}

re : fclean all

.PHONY : all clean fclean re
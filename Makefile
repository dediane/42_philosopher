# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ddecourt <ddecourt@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/13 23:02:52 by ddecourt          #+#    #+#              #
#    Updated: 2021/10/15 14:30:43 by ddecourt         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	philo.c \
		srcs/parsing.c \
		srcs/philo_utils.c \

OBJS = ${SRCS:.c=.o}

NAME = philo

HEADER = philo.h

CC = clang

CFLAGS = -Wall -Werror -Wextra -pthread -g -fsanitize=address -g3
RM = rm -f

.c.o:
	${CC} -c ${CFLAGS} -o $@ $< 

$(NAME):    ${OBJS}
	${CC} ${CFLAGS} ${OBJS} -o ${NAME}

all:	${NAME}

clean: 
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re:	 fclean all

.PHONY: all clean fclean re

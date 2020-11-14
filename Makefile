# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: meldora <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/08 15:20:57 by meldora           #+#    #+#              #
#    Updated: 2020/11/14 13:28:31 by meldora          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a

BINARY		= ft_printf.out

SRCS		= $(wildcard *.c)

OBJS		= ${SRCS:.c=.o}

CC			= gcc

CFLAGS		= -Wall -Wextra -Werror

AR			= ar

ARFLAGS		= rc

RM			= rm -rf

.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME):	${OBJS}
			${AR} ${ARFLAGS} $@ $^

binary:		re
			${CC} ${CFLAGS} ${SRCS} -o ${BINARY}

all:		${NAME}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

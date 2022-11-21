# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cpapot <cpapot@student.42lyon.fr >         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/08 14:44:54 by cpapot            #+#    #+#              #
#    Updated: 2022/11/21 16:52:44 by cpapot           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a

SRCS	= ft_printf.c

HEADERS = ft_printf.h

CFLAGS = -Wall -Wextra -Werror

OBJS	= ${SRCS:.c=.o}

%.o:	%.c ${HEADERS} Makefile
	$(CC) -I ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
	ar rcs ${NAME} ${OBJS}

all: ${NAME}

clean:
	${RM} ${OBJS}

fclean:		clean
	${RM} ${NAME}

re:	fclean all

.PHONY : re all clean fclean

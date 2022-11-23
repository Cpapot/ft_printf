# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cpapot <cpapot@student.42lyon.fr >         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/08 14:44:54 by cpapot            #+#    #+#              #
#    Updated: 2022/11/23 19:04:54 by cpapot           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a

SRC_ROOT =	ft_printf.c

SRCS	=	ft_putunsint_len.c ft_putstr_len.c \
			ft_putpercent_len.c ft_putnull_len.c ft_putint_len.c \
			ft_puthexavoid_len.c ft_puthexamin_len.c ft_puthexamaj_len.c \
			ft_putchar_len.c ft_findformat.c

SRC_DIR = $(addprefix printf_utils/, $(SRCS))

HEADERS = ft_printf.h

CFLAGS = -Wall -Wextra -Werror

OBJS	= $(SRC_ROOT:.c=.o) ${SRC_DIR:.c=.o}

%.o:	%.c ${HEADERS} Makefile
	$(CC) -I ${CFLAGS} -c $< -o $@

${NAME}:	${OBJS} libft
	ar rcs ${NAME} libft/libft.a ${OBJS}

libft:
	$(MAKE) -C libft/ all

all: ${NAME}

clean:
	$(MAKE) -C libft/ clean
	${RM} ${OBJS}

fclean:		clean
	$(MAKE) -C libft/ fclean
	${RM} ${NAME}

re:	fclean all

.PHONY : re all clean fclean libft

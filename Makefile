# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aorynbay <@student.42abudhabi.ae>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/10 08:08:06 by aorynbay          #+#    #+#              #
#    Updated: 2024/07/10 15:13:01 by aorynbay         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	ft_printf.c ft_printf_char.c ft_printf_decimal.c ft_printf_hexa.c \
			ft_printf_percent.c ft_printf_str.c ft_printf_unsigned.c ft_printf_ptr.c

OBJS	=	${SRCS:.c=.o}

CC		=	cc

RM		=	rm -f

CFLAGS	=	-Wall -Werror -Wextra

NAME	=	libftprintf.a

all:	${NAME}

%.o:	%.c
	${CC} ${CFLAGS} -c $< -o $@

${NAME}:	${OBJS}
	ar rcs ${NAME} ${OBJS}

clean:
	${RM} ${OBJS}

fclean:
	${RM} ${NAME}

re:	fclean ${NAME}

.PHONY: all clean fclean re
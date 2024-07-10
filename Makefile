# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aorynbay <@student.42abudhabi.ae>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/10 08:08:06 by aorynbay          #+#    #+#              #
#    Updated: 2024/07/10 10:52:20 by aorynbay         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	printf.c

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
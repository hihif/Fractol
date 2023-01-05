# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fhihi <fhihi@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/21 16:10:39 by fhihi             #+#    #+#              #
#    Updated: 2022/10/23 15:36:56 by fhihi            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

SRC =  ft_printf.c ft_putnbr_base.c ft_putstr.c \
	   ft_putchar.c ft_putnbr_hex.c \
	   ft_putpointer.c ft_putunbr.c

OBJ = $(SRC:.c=.o)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJ)
	ar -rcs $(NAME) $(OBJ)

all : $(NAME)

clean : 
	$(RM) $(OBJ)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re 
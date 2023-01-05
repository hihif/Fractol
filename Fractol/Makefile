# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fhihi <fhihi@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/03 09:34:13 by fhihi             #+#    #+#              #
#    Updated: 2023/01/03 10:36:18 by fhihi            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

SRC = events.c juliasets.c main.c mandlebrotset.c Utils.c window.c 

FRAME = -framework OpenGL -framework Appkit -lmlx

OBJ = $(SRC:.c=.o) 

%.o: %.c
	cc $(CFLAGS) -c $< -o $@ -I.

$(NAME): $(OBJ)
	make -C ft_printf
	make -C libft
	cc $(OBJ) $(FRAME) ./libft/libft.a ./ft_printf/libftprintf.a -o $@

all: $(NAME) 

clean:
	make -C ft_printf clean
	make -C libft clean
	$(RM) $(OBJ)

fclean: clean
	make -C ft_printf fclean
	make -C libft fclean
	$(RM) $(NAME)

re: fclean all
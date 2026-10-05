# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbustos- <jbustos-@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/10/04 12:49:33 by jbustos-          #+#    #+#              #
#    Updated: 2026/10/05 16:27:11 by jbustos-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SOURCE =	ft_printf.c ft_strlen.c ft_putstrcount.c ft_putchar.c			 \
			ft_itoa.c ft_print_hex.c ft_print_unsigned.c					 \

CFLAGS = -Wall -Wextra -Werror 
CC = cc

OBJECTS = $(SOURCE:.c=.o)
BONUS_OBJ = $(BONUS:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	ar -rcs $(NAME) $(OBJECTS)

bonus: $(NAME) $(BONUS_OBJ)
	ar -rcs $(NAME) $(BONUS_OBJ)

clean:
	rm -rf $(OBJECTS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
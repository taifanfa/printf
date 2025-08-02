# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmorais- <tmorais-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/02 14:24:05 by tmorais-          #+#    #+#              #
#    Updated: 2025/08/02 14:31:08 by tmorais-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror

NAME = libftprintf.a

HEADER = ft_printf.h

SRCS = ft_printf.c \
		ft_count_utils.c \
		ft_print_numbers.c \
		ft_printf_hex.c \
		ft_print_conversions.c \

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
  ar rcs $(NAME) $(OBJS)

%.o: %.c $(HEADER)
   $(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

test: $(NAME)
  $(CC) $(CFLAGS) -L. -lftprintf test_printf.c -o test_printf

.PHONY: all clean fclean re test
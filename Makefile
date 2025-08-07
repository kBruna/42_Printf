# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: buehara <buehara@student.42sp.org.br>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/06 14:42:28 by buehara           #+#    #+#              #
#    Updated: 2025/08/07 17:13:18 by buehara          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprint.a

AR = ar

RCS = rcs

CC = cc

C_FLAGS = -Wall -Werror -Wextra

C_SOURCE = ft_printf.c		\
			ft_putstr_fd.c 	\
			ft_strlen.c		\
			ft_putchar_fd.c

OBJ = $(C_SOURCE:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(RCS) $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(C_FLAGS) -c $< -o $@


clean:
	rm -f $(OBJ)

fclean: clean
	rm -fr $(NAME)

re: fclean all

.PHONY: all clean fclean re

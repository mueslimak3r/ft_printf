# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: calamber <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/17 11:20:37 by calamber          #+#    #+#              #
#    Updated: 2018/10/01 22:07:16 by calamber         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = ft_printf.c tools.c uitoa_base.c print_buffer.c \
parse_u.c flags.c parse_chars.c parse_d.c parse_wchar.c

OBJ = $(SRC:.c=.o)

SRC_PATH = src/

SRC_POS = $(addprefix $(SRC_PATH),$(SRC))

INC = -I includes

CC = gcc

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ) libft/*.o
	@ranlib $(NAME)

$(OBJ):
	@make -C libft
	@$(CC) $(FLAGS) $(INC) -c $(SRC_POS)

clean:
	@make clean -C libft
	@rm -f $(OBJ)

fclean: clean
	@make fclean -C libft
	@rm -f $(NAME)

re: fclean all

compile: re
	@$(CC) $(FLAGS) $(INC) mymain.c $(NAME)
	@make clean

cleanup: fclean
	@rm -rf *.out*

.PHONY : all, re, clean, fclean, leaks, cleanup

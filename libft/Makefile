# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rhoke <rhoke@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/21 13:23:49 by rhoke             #+#    #+#              #
#    Updated: 2021/09/21 14:22:30 by rhoke            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

HEADER = ./includes/libft.h

LIST = $(wildcard ./sources/*.c)

OBJ = ${LIST:.c=.o}

FLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(OBJ) $(HEADER)
	ar rcs $(NAME) $?

%.o : %.c
	gcc $(FLAGS) -c $< -o $@

clean :
	@rm -f $(OBJ) $(BONUS_OBJ)

fclean : clean
	@rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean bonus
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dsheptun <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/22 10:57:47 by dsheptun          #+#    #+#              #
#    Updated: 2017/11/22 10:57:49 by dsheptun         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRCS = src/ft_create_list.c src/ft_create_map.c src/ft_parse.c src/ft_push.c \
		src/ft_small_push_check.c src/ft_left_corner.c src/ft_push_check.c \
		src/ft_clear.c src/ft_increment_map.c src/fillit.c src/validation.c

OBJ = *.o

INC = includes/

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME) :
	@make -C libft
	@gcc $(FLAGS) -I $(INC) -c $(SRCS)
	@gcc $(OBJ) -L libft/ -lft -o $(NAME)

clean:
	@make -C libft/ clean
	@rm -f $(OBJ)

fclean: clean
	@make -C libft/ fclean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

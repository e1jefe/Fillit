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

NAME = f.a

HEADER = f.h

FLAGS = -Wall -Werror -Wextra

SRC = ft_create_list.c ft_create_map.c ft_parse.c 

OBJ = ft_create_list.o ft_create_map.o ft_parse.o 

all: $(NAME)

$(NAME):
	@gcc -c $(SRC) $(FLAGS)
	@ar rc $(NAME) $(OBJ) $(HEADER)

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
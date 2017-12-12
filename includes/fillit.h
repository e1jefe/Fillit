/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f.h                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsheptun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 09:19:43 by dsheptun          #+#    #+#             */
/*   Updated: 2017/11/24 09:19:45 by dsheptun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "../libft/libft.h"
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# define BUFF_SIZE 546

typedef struct			s_position
{
	int					**xy;
	char				c;
	struct s_position	*next;
	struct s_position	*prev;
}						t_position;

char					**g_map;
void					ft_left_corner(t_position *tetr);
int						**ft_parse(char **buf, int i, int r, int c);
t_position				*ft_create_list(char **buf, int lines_numb);
char					**ft_create_map(short size);
int						ft_push_check(t_position *tetr, int map_size);
void					ft_clear(t_position *tetr);
void					ft_push(t_position *tetr);
int						ft_small_push_check(t_position *tetr);
char					**ft_increment_map(short size);
int						ft_validation(char *buf);

#endif

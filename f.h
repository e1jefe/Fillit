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

#ifndef F_H
# define F_H

# include "libft.h"
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

void			ft_left_corner(t_position *tetr);
int				**ft_parse(char **buf, int i, int r, int c);
t_position		*ft_create_list(char **buf, int lines_numb);
char			**ft_create_map(short size);
int				ft_push_check(t_position *tetr, char **map, int map_size);
void			ft_clear(t_position *tetr, char **map);
char			**ft_push(t_position *tetr, char **map);
int				ft_small_push_check(t_position *tetr, char **map);
#endif
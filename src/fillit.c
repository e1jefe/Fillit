/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsheptun <dsheptun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 17:15:09 by proshchy          #+#    #+#             */
/*   Updated: 2017/12/12 14:41:02 by dsheptun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		print_map(void)
{
	int		i;
	int		j;

	i = 0;
	while (g_map[i])
	{
		j = 0;
		while (g_map[i][j])
		{
			ft_putchar(g_map[i][j]);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
	exit(0);
}

void		ft_fillit(t_position *coord, int map_size)
{
	if (ft_small_push_check(coord) == 1)
	{
		ft_push(coord);
		coord = coord->next;
	}
	else
	{
		while (coord)
		{
			if (ft_push_check(coord, map_size) == 1)
			{
				ft_push(coord);
				coord = coord->next;
			}
			else
			{
				if (coord->c == 'A')
				{
					map_size++;
					g_map = ft_increment_map(map_size);
					ft_left_corner(coord);
					ft_fillit(coord, map_size);
				}
				ft_left_corner(coord);
				coord = coord->prev;
				ft_clear(coord);
			}
		}
	}
	if (coord != NULL)
		ft_fillit(coord, map_size);
	else
		print_map();
}

int			ft_sqrt(int len)
{
	int i;

	i = 2;
	while (i * i < len)
		i++;
	return (i);
}

int			count_tetr(char *str)
{
	int		i;
	int		nb_t;

	nb_t = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			nb_t++;
		i++;
	}
	return ((nb_t + 1) / 5);
}

int			main(int argc, char **argv)
{
	int			fd;
	int			bytes;
	char		**buffer;
	char		*buf;
	int			map_size;
	t_position	*coord;

	if (argc != 2)
	{
		ft_putstr("usage: fillit input_file\n");
		exit(0);
	}
	fd = open(argv[1], O_RDONLY);
	buf = (char*)malloc(545 + 1);
	bytes = read(fd, buf, 545 + 1);
	buf[bytes] = '\0';
	if (ft_validation(buf) == 0)
	{
		ft_putstr("error\n");
		exit(0);
	}
	buffer = ft_strsplit(buf, '\n');
	coord = ft_create_list(buffer, 10);
	map_size = ft_sqrt(count_tetr(buf) * 4);
	g_map = ft_create_map(map_size);
	ft_fillit(coord, map_size);
	print_map();
	return (0);
}

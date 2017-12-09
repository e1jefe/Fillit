/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proshchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 17:15:09 by proshchy          #+#    #+#             */
/*   Updated: 2017/12/04 17:15:11 by proshchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "f.h"

static int in_map(char c, char **map)
{
	int 	i;
	int 	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == c)
				return (0);
			j++;
		}
		i++;
	}
    return (1);
}

static int count_coord(const t_position *head, char **map)
{
	int			count;
	t_position	*coord;

	count = 0;
	coord = (t_position*)head;
	while (coord)
	{
		if (in_map(coord->c, map) == 1)
			return (0);
		coord = coord->next;
	}
	return (1);
}

int		ft_fillit(const t_position *head, t_position *coord, char **map, int map_size)
{
	if (count_coord(head, map))
		return (1);
	coord = (t_position *)head;

		while (coord)
		{
			if (in_map(coord->c, map))
			{
				if (ft_push_check(coord, map, map_size) == 1)
				{
					// printf("coord = %c\n", coord->c);
					ft_push(coord, map);

					int i = 0;
					while (i < map_size)
					{
						ft_putendl(map[i]);
						i++;
					}
					write(1, "\n", 1);

					if (ft_fillit(head, coord, map, map_size) == 1)
						return (1);
					ft_clear(coord, map);
				}
			}
			ft_left_corner(coord);
			coord = coord->next;
		}
	return (0);
}

char	**check_fillit(const t_position *head, t_position *coord, char **map, int map_size)
{
	if (ft_push_check((t_position *)head, map, map_size))
	{
		printf("ft_push_check\n");
		ft_push((t_position *)head, map);
		ft_fillit((t_position *)head->next, coord, map, map_size);
	}
	else
	{
		map_size++;
		map = ft_create_map(map_size);
		ft_fillit(coord, coord, map, map_size);
	}
	return (NULL);
}

int	main()
{
	int i;
	char **buffer;
	char **map;
	t_position *coord;
	int map_size = 3;
	//buffer = ft_strsplit(".##.\n..#.\n..#.\n....\n\n....\n####\n....\n....\n\n#...\n###.\n....\n....\n\n....\n##..\n.##.\n....\n", '\n');
	buffer = ft_strsplit(".##.\n..#.\n..#.\n....\n\n##\n##..\n....\n....\n", '\n');
	//buffer = ft_strsplit("###.\n#...\n....\n....\n\n....\n....\n#...\n###.\n\n....\n.##.\n.##.\n....\n\n...#\n...#\n...#\n...#\n", '\n');
	coord = ft_create_list(buffer, 8);
	map = ft_create_map(map_size);
	i = 0;
	//ft_fillit(coord, coord, map, map_size);
	// while (ft_fillit(coord, coord, map, map_size) == 0)
	// {
	// 	map_size++;
	// 	map = ft_create_map(map_size);
	// }
	check_fillit(coord,coord,map,map_size);
	while (i < map_size)
	{
		ft_putendl(map[i]);
		i++;
	}
	return (0);
}
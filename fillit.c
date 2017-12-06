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

void		ft_fillit(t_position *coord, char **map, int map_size)
{
	int i;

	i = 0;
	ft_left_corner(coord);
//	ft_left_corner(coord->next);
	while (/*coord*/i < 4)
	{
		//ft_left_corner(coord);
		if (ft_small_push_check(coord, map) == 1) // 
		{
			//printf("%s\n","0");
			ft_push(coord, map);
			coord = coord->next;
//			printf("%s\n",coord);
	//		printf("%s\n","0");
		}
		else
		{
			//coord = coord->prev;
			// ft_clear(coord, map);
			if (ft_push_check(coord, map, map_size) == 1) // move -> can push? move:exit;
			{
				// printf("%s\n", "1");
				ft_push(coord, map);
				coord = coord->next;
			}
			else
			{
			//	if (coord == head)
			//		ft_fillit(coord, map_size++);
			//	else
				//map_size++;
			 //printf("%s\n", "404");
			}
		}
		i++;
	}
}

int	main()
{
	int i;
	char **buffer;
	char **map;
	t_position *coord;
	buffer = ft_strsplit("....\n####\n....\n....\n\n....\n.##.\n.##.\n....\n\n#...\n#...\n#...\n#...\n\n#...\n#...\n#...\n#...\n", '\n');
//	printf("%s\n", "tyt");
	coord = ft_create_list(buffer, 10);
	map = ft_create_map(5);
	i = 0;
	ft_fillit(coord, map, 5);
	while (i < 5)
	{
		ft_putendl(map[i]);
		i++;
	}
	return (0);
}

//gcc ft_left_corner.c ft_push.c ft_push_check.c ft_clear.c ft_small_push_check.c ft_create_list.c ft_create_map.c fillit.c libft.a ft_parse.c
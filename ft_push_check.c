/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proshchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 13:00:47 by proshchy          #+#    #+#             */
/*   Updated: 2017/12/02 13:00:49 by proshchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "f.h"

//1.can move right? move right(+return 1) : (can move down? mobe down : 0)

t_position		*ft_x_increment(t_position *tetr)
{
	int x;

	x = 0;
	while (x < 4)
		tetr->xy[x++][0] += 1;
//	printf("%s\n", "->" );
	return(tetr);
}

t_position		*ft_y_increment(t_position *tetr)
{
	int x;

	x = 0;
	while (x < 4)
		tetr->xy[x++][1] += 1;
//	printf("%s\n", "<-" );
	return(tetr);
}

int 			ft_walls_check(t_position *tetr, int map_size, int i)
{
	int x;

	x = 0;
	if (i == 1)
	{
		while (x < 4)
			if (tetr->xy[x++][0] >= map_size)
				return (0);
//		printf("%s\n", "rwall OK");
		return (1);
	}
	while (x < 4)
		if (tetr->xy[x++][1] >= map_size)
			return (0);
//	printf("%s\n", "dwall OK");
	return (1);
}

t_position		*ft_to_left_wall(t_position *tetr)
{
	int min_x;
	int x;

	x = 0;
	min_x = tetr->xy[0][0];
	while (x < 4)
	{
		if (min_x > tetr->xy[x][0])
			min_x = tetr->xy[x][0];
		x++;
	}
	x = 0;
	while (x < 4)
	{
		tetr->xy[x][0] -= min_x;
		x++;
	}
	return (tetr);
}

int		ft_push_check(t_position *tetr, char **map, int map_size)
{
	int x;
	int y;

	x = 0;
	y = 0;
	ft_x_increment(tetr);
	while (x < 4)
	{
		if (ft_walls_check(tetr, map_size, 1) == 1)
		{
			if (map[tetr->xy[x][y + 1]][tetr->xy[x][y]] == '#')
				ft_x_increment(tetr);
			else
				x++;
		}
		else
		{
		//printf("%d %d\n", tetr->xy[0][0], tetr->xy[0][1]);
			ft_to_left_wall(tetr);
			ft_y_increment(tetr);
			if (ft_walls_check(tetr, map_size, -1) == 1)
				x = 0;
			else
			{
				// printf("%d %d\n", tetr->xy[0][0], tetr->xy[0][1]);
				// printf("%d %d\n", tetr->xy[1][0], tetr->xy[1][1]);
				// printf("%d %d\n", tetr->xy[2][0], tetr->xy[2][1]);
				// printf("%d %d\n", tetr->xy[3][0], tetr->xy[3][1]);
				return (0);
			}
		}
	}
	// printf("%d %d\n", tetr->xy[0][0], tetr->xy[0][1]);
	// printf("%d %d\n", tetr->xy[1][0], tetr->xy[1][1]);
	// printf("%d %d\n", tetr->xy[2][0], tetr->xy[2][1]);
	// printf("%d %d\n", tetr->xy[3][0], tetr->xy[3][1]);
	return (1);
}

// int main()
// {
// 	t_position *head;
// 	char **map;
// 	char **tetr;

// 	tetr = ft_strsplit("....\n####\n....\n....\n", '\n');
// 	map = ft_strsplit("....\n.##.\n..##\n....\n", '\n');
// 	head = ft_create_list(tetr, 4);
	
// 	printf("%d\n", ft_push_check(head, map, 4));
// 	return (0);
// }






















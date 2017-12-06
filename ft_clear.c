/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clear.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proshchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 15:59:09 by proshchy          #+#    #+#             */
/*   Updated: 2017/12/04 15:59:10 by proshchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "f.h"
#include "libft.h"
//1.delete coord from map
//2.change coord to upper left corner

void	ft_clear(t_position *tetr, char **map)
{
	int x;

	x = 0;
	while (x < 4)
	{
		map[tetr->xy[x][1]][tetr->xy[x][0]] = '.';
		x++;
	}
	ft_left_corner(tetr);
}

// int	main()
// {
// 	t_position *head;
// 	char **map;
// 	char **tetr;

// 	tetr = ft_strsplit("##..\n##..\n....\n....\n", '\n');
// 	map = ft_strsplit("##..\n##..\n....\n....\n", '\n');
// 	head = ft_create_list(tetr, 4);
// //	ft_clear(head, map);
// 	printf("%c\n", map[0][0]);
// 	printf("%c\n", map[0][1]);
// 	printf("%c\n", map[1][0]);
// 	printf("%c\n", map[1][1]);
// 	return (0);
// }
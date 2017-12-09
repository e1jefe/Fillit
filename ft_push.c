/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proshchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 16:46:59 by proshchy          #+#    #+#             */
/*   Updated: 2017/12/04 16:47:03 by proshchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "f.h"

char	**ft_push(t_position *tetr, char **map)
{
	int x;

	x = 0;
	while (x < 4)
	{
		map[tetr->xy[x][1]][tetr->xy[x][0]] = tetr->c;
		x++;
	}
	return (map);
}

// int	main()
// {
// 	t_position *head;
// 	char **map;
// 	char **tetr;

// 	tetr = ft_strsplit("##..\n##..\n....\n....\n", '\n');
// 	map = ft_strsplit("....\n....\n....\n....\n", '\n');
// 	head = ft_create_list(tetr, 4);
// //	ft_push(head, map);
// 	printf("%c", map[0][0]);
// 	printf("%c\n", map[0][1]);
// 	printf("%c", map[1][0]);
// 	printf("%c\n", map[1][1]);
// 	return (0);
// }
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_increment_map.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proshchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 16:43:13 by proshchy          #+#    #+#             */
/*   Updated: 2017/12/07 16:43:14 by proshchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "f.h"

char	**ft_increment_map(char **map, short size)
{
	int 	i;
	int 	j;
	char	**new_map;

	i = 0;
	new_map = ft_create_map(size);
	while (map[i] != 0)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			new_map[i][j] = map[i][j];
			j++;
		}
		i++;
	}
    return (new_map);
}

// int main()
// {
// 	char *pos[41];
// 	int **res;

// 	 pos[0] = "...#\n";
// 	 pos[1] = "...#\n";
// 	 pos[2] = "...#\n";
// 	 pos[3] = "...#\n";
// 	//  pos[4] = "#...\n";
// 	//  pos[5] = "#...\n";
// 	//  pos[6] = "#...\n";
// 	//  pos[7] = "#...\n";
// 	//  pos[8] = "....\n";
// 	//  pos[9] = ".##.\n";
// 	// pos[10] = ".##.\n";
// 	// pos[11] = "....\n";
// 	pos[4] = 0;

// 	// pos[12] = "....\n";
// 	// pos[13] = ".##.\n";
// 	// pos[14] = "..##\n";
// 	// pos[15] = "....\n";

// 	ft_increment_map(pos, 5);
// 	return (0);
// }
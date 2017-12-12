/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsheptun <dsheptun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 14:27:20 by dsheptun          #+#    #+#             */
/*   Updated: 2017/12/12 14:37:43 by dsheptun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**ft_create_map(short size)
{
	char	**map;
	short	i;
	short	j;

	i = 0;
	map = (char**)malloc(sizeof(char*) * (size + 1));
	if (!map)
		return (NULL);
	while (size - i)
	{
		map[i] = (char*)malloc(sizeof(char) * (size + 1));
		if (!map[i])
			return (NULL);
		j = 0;
		while (size - j)
		{
			map[i][j] = '.';
			j++;
		}
		map[i][j] = '\0';
		i++;
	}
	map[i] = 0;
	return (map);
}

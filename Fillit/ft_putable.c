/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putable.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsheptun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 09:59:57 by dsheptun          #+#    #+#             */
/*   Updated: 2017/12/01 09:59:59 by dsheptun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

char	**ft_create_map(short size)
{
	char 			**map;
	short			i;
	short			j;

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

// int	main()
// {
// 	char **map;
// 	short size;
// 	int i = -1;
// 	size = 4;
// 	map = ft_create_map(size);
// 	while (map[++i])
// 		printf("%s\n", map[i]);
// 	return (0);
// }

int		count_tetr(char *buf)
{
	int		i;
	int		newline;

	nl = 0;
	i = 0;
	while (buf[i])
	{
		if (buf[i] == '\n')
			newline++;
		i++;
	}
	return ((newline + 1) / 5);
}
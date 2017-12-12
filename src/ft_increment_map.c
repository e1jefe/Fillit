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

#include "fillit.h"

char	**ft_increment_map(short size)
{
	int		i;
	int		j;
	char	**new_map;

	i = 0;
	new_map = ft_create_map(size);
	while (g_map[i] != 0)
	{
		j = 0;
		while (g_map[i][j] != '\0')
		{
			new_map[i][j] = g_map[i][j];
			j++;
		}
		i++;
	}
	return (new_map);
}

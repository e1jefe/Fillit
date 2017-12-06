/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_push.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proshchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 18:17:37 by proshchy          #+#    #+#             */
/*   Updated: 2017/12/04 18:17:39 by proshchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "f.h"

int		ft_small_push_check(t_position *tetr, char **map)
{
	int x;

	x = 0;
	while (x < 4)
	{
		if (map[tetr->xy[x][1]][tetr->xy[x][0]] != '#')
			x++;
		else
			return (0);
	}
	return (1);
}

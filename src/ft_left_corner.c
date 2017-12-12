/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_left_corner.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proshchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 17:37:04 by proshchy          #+#    #+#             */
/*   Updated: 2017/11/30 17:37:07 by proshchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_left_corner(t_position *tetr)
{
	int min_x;
	int min_y;
	int x;
	int y;

	x = 1;
	y = 0;
	min_x = tetr->xy[0][0];
	min_y = tetr->xy[0][1];
	while (x < 4)
	{
		if (min_x > tetr->xy[x][0])
			min_x = tetr->xy[x][0];
		if (min_y > tetr->xy[x][1])
			min_y = tetr->xy[x][1];
		x++;
	}
	x = 0;
	while (x < 4)
	{
		tetr->xy[x][0] -= (min_x + 1);
		tetr->xy[x][1] -= min_y;
		x++;
	}
}

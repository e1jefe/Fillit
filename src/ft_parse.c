/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proshchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 11:28:12 by proshchy          #+#    #+#             */
/*   Updated: 2017/11/29 11:28:16 by proshchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void			ft_hard_left_corner(int **tetr_xy)
{
	int min_x;
	int min_y;
	int x;
	int y;

	x = 1;
	y = 0;
	min_x = tetr_xy[0][0];
	min_y = tetr_xy[0][1];
	while (x < 4)
	{
		if (min_x > tetr_xy[x][0])
			min_x = tetr_xy[x][0];
		if (min_y > tetr_xy[x][1])
			min_y = tetr_xy[x][1];
		x++;
	}
	x = 0;
	while (x < 4)
	{
		tetr_xy[x][0] -= (min_x + 1);
		tetr_xy[x][1] -= min_y;
		x++;
	}
}

int				**ft_parse(char **buf, int i, int r, int c)
{
	int **row_col;
	int j;
	int counter;

	counter = -1;
	if ((row_col = (int **)malloc((sizeof(int *) * 4))) != NULL)
	{
		while (++counter < 4 && i++ < 104)
		{
			j = -1;
			while (++j < 4)
			{
				if (buf[i][j] == '#')
				{
					if ((row_col[r] = (int *)malloc(sizeof(int) * 2)) != NULL)
					{
						row_col[r][c] = j;
						row_col[r][c + 1] = counter;
						r++;
					}
					else
						return (0);
				}
			}
		}
		ft_hard_left_corner(row_col);
		return (row_col);
	}
	return (0);
}

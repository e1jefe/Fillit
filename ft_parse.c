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

#include "f.h"

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
//			printf("%d %d\n",counter, i);
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

//  int		main()
// {
// 	char *pos[41];
// 	int **res;

// 	 pos[0] = "...#";
// 	 pos[1] = "...#";
// 	 pos[2] = "...#";
// 	 pos[3] = "...#";

// 	 pos[4] = "....";
// 	 pos[5] = ".##.";
// 	 pos[6] = "..##";
// 	 pos[7] = "....";

// 	 pos[8] = "....";
// 	 pos[9] = ".##.";
// 	pos[10] = "..##";
// 	pos[11] = "....";

// 	pos[12] = "....";
// 	pos[13] = ".##.";
// 	pos[14] = "..##";
// 	pos[15] = "....";

// 	pos[16] = "....";
// 	pos[17] = ".##.";
// 	pos[18] = "..##";
// 	pos[19] = "....";

// 	pos[20] = "####";
// 	pos[21] = "....";
// 	pos[22] = "....";
// 	pos[23] = "....";

// 	pos[24] = "....";
// 	pos[25] = ".##.";
// 	pos[26] = "..##";
// 	pos[27] = "....";

// 	pos[28] = "....";
// 	pos[29] = ".##.";
// 	pos[30] = "..##";
// 	pos[31] = "....";

// 	pos[32] = "....";
// 	pos[33] = ".##.";
// 	pos[34] = "..##";
// 	pos[35] = "....";

// 	pos[36] = "....";
// 	pos[37] = "....";
// 	pos[38] = "..##";
// 	pos[39] = "..##";
// 	//pos[8] = "\0";
// 	res = ft_parse(pos, 35, 0, 0);
// 	// while (i < 4 && j < 4)
// 	// {
// 	// 	printf("%d %d\n", res[i][j], res[i][j + 1]);
// 	// 	i++;
// 	// 	j++;
// 	// }
// 	printf("%d %d\n", res[0][0], res[0][1]);
// 	printf("%d %d\n", res[1][0], res[1][1]);
// 	printf("%d %d\n", res[2][0], res[2][1]);
// 	printf("%d %d\n", res[3][0], res[3][1]);
// 	return(0);
// }
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proshchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 13:58:28 by proshchy          #+#    #+#             */
/*   Updated: 2017/11/22 14:11:48 by proshchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int		newline_check(char *s)
{
	int count;

	count = 1;
	while (count >= 1)
	{
		if ((*s != '.' || *s != '#') && *(s + 4) != '\n')
			return (0);
		if (count == 4)
		{
			if (*(s + 5) == '\n' && (*(s + 6) == '.' || *(s + 6) == '#'))
				return (1);
			else if (*(s + 5) == '\0')
				return (1);
			else
				return (0);
		}
		count++;
		s += 5;
	}
	return (1);
}

int		sharp_numb_check(char *s)
{
	int count;
	int sharp;

	sharp = 0;
	count = 0;
	while (count < 19)
	{
		if (*s == '#')
			sharp++;
		s++;
		count++;
	}
	return (sharp == 4);
}

int		tetr_check(char *str, int i)
{
	int conn;

	conn = 0;
	if (str[i + 1] == '#')
		conn++;
	if (str[i - 1] == '#')
		conn++;
	if (i > 5 && str[i - 5] == '#')
		conn++;
	if (str[i + 5] == '#')
		conn++;
//	printf("coord: %d%d\n",j,i);
//	printf("%d\n", conn);
	return (conn);
}

int		find_sharp(char *buf, int i)
{
	int conn;
	int count;

	count = 0;
	conn = 0;
	while (count < 19)
	{
		if (buf[i] == '#')
			conn += tetr_check(buf, i);	
		i++;
		count++;
	}
	//	printf("%d\n", conn);
	if (conn == 6 || conn == 8)
		return (1);
	return (0);
}

int		ft_validation(char *buf)
{
	int i;

	i = 0;
	if (ft_strlen(buf) < 21 || ft_strlen(buf) > 545)
		return (0);
	while (buf[i])
	{
		if (newline_check(&buf[i]) == 1)
		{
//			printf("%s\n", "square OK");
			if (sharp_numb_check(&buf[i]) == 1)
			{
//				printf("%s\n", "sharp numbers OK");
				if (find_sharp(buf, i) == 1)
				{
//					printf("%s\n", "connection OK");
					if (buf[i + 20] == '\0')
						return (1);
					if (buf[i + 20] == '\n')
						i += 21;
				}
				else
				{
//					printf("%s\n","connection KO" );
					return (0);
				}
			}
			else
			{
//				printf("%s\n", "sharp numbers KO");
				return (0);
			}
		}
		else
		{
//			printf("%s\n", "square KO");
			return (0);
		}
	}
	return (0);
}

int		main()
{
//	printf("result: %d\n", find_sharp(".#...#...#...#.."));
//	char **arr;
//	printf("result :%d\n", newline_check("....\n....\n####\n....\n"));
//	arr = ft_strsplit(".#...#...#...#..", '\n');
//	printf("%s\n", arr[0]);
//	printf("%d\n", find_sharp("...#\n...#\n...#\n...#\n", 0));
//	printf("result: %d\n", ft_validation("...#\n...#\n...#\n...#\n\n....\n####\n....\n.....\n"));
//	printf("%d\n", sharp_numb_check("#...\n#...\n#...\n#...\n"));
	if (ft_validation("...#\n...#\n...#\n...#\n\n....\n####\n....\n....\n") == 0)
	{
		ft_putstr("error\n");
		exit (0);
	}
	return (0);
}



















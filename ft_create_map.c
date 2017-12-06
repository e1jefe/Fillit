/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proshchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 16:18:32 by proshchy          #+#    #+#             */
/*   Updated: 2017/12/02 16:18:34 by proshchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "f.h"

char	**ft_create_map(short size)
{
    char            **map;
    short           i;
    short           j;
    
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
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchiorea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/26 17:24:37 by rchiorea          #+#    #+#             */
/*   Updated: 2016/12/23 12:37:45 by rchiorea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	size_t	i;
	char	*d;

	i = 0;
	while (s[i])
		i++;
	d = malloc(sizeof(char) * i + 1);
	if (!d)
		return (0);
	i = 0;
	while (s[i])
	{
		d[i] = f(s[i]);
		i++;
	}
	d[i] = '\0';
	return (d);
}

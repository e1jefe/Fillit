/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchiorea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/01 22:28:22 by rchiorea          #+#    #+#             */
/*   Updated: 2016/12/22 17:20:10 by rchiorea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*s1;
	unsigned char	*s2;
	unsigned char	temp[n];

	i = 0;
	s1 = (unsigned char *)src;
	s2 = (unsigned char *)dest;
	while (i < n)
	{
		temp[i] = s1[i];
		i++;
	}
	i = 0;
	while (i < n)
	{
		s2[i] = temp[i];
		i++;
	}
	return (dest);
}

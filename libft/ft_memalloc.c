/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchiorea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/22 19:08:52 by rchiorea          #+#    #+#             */
/*   Updated: 2016/12/23 13:30:49 by rchiorea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*s;

	if (!size)
		return (0);
	s = malloc(sizeof(*s) * size);
	if (!s)
		return (0);
	s = ft_memset(s, 0, size);
	return (s);
}

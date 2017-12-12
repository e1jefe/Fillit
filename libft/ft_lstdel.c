/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchiorea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 16:36:20 by rchiorea          #+#    #+#             */
/*   Updated: 2016/12/23 16:51:49 by rchiorea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*next;

	while (*alst != NULL)
	{
		next = (*alst)->next;
		del((*alst)->content, (*alst)->content_size);
		free(*alst);
		*alst = next;
	}
}

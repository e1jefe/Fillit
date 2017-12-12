/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchiorea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 17:14:57 by rchiorea          #+#    #+#             */
/*   Updated: 2016/12/23 18:38:35 by rchiorea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*k;

	new = (t_list *)malloc(sizeof(t_list));
	k = (t_list *)malloc(sizeof(t_list));
	k = f(lst);
	new = k;
	if (new == NULL || lst == NULL)
		return (NULL);
	while (lst->next)
	{
		lst = lst->next;
		k->next = f(lst);
		if ((k->next) == NULL)
			return (NULL);
		k = k->next;
	}
	return (new);
}

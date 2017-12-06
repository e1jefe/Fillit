/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proshchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 14:56:55 by proshchy          #+#    #+#             */
/*   Updated: 2017/12/02 14:56:58 by proshchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "f.h"

t_position		*ft_create_list(char **buf, int lines_numb)
{
	int i;
	int j;
	int c;
	t_position *head;
	t_position *elem;

	i = 4;
	j = 0;
	c = 0;
	if ((elem = malloc(sizeof(t_position))) != NULL)
	{
		if ((head = malloc(sizeof(t_position))) != NULL)
		{
			head->xy = ft_parse(buf, -1, 0, 0);
			// head->c = 65 + c;
			// printf("%c\n", head->c);
			// c++;
			elem->prev = NULL;
			if (lines_numb > 4)
			{
				head->next = elem;
				elem->prev = head;
				while (buf[i] != NULL)
				{
					//printf("i :%d\n", i);
					elem->xy = ft_parse(buf, (i - 1), 0, 0);
				//	printf("%d%s\n", i,"ft_parse OK");
					elem->next = malloc(sizeof(t_position));
					elem->next->prev = elem;
					elem = elem->next;
					// elem->c = 65 + c;
					 // printf("%c\n", elem->c);
					// c++;
					i += 4;
				}
				elem = NULL;
			}
			else
				head->next = NULL;
		}
	}
	else
		return (NULL);
	return (head);
}
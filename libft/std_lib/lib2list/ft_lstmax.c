/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmax.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleann <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 18:50:39 by jleann            #+#    #+#             */
/*   Updated: 2019/04/05 18:50:40 by jleann           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list_node	*ft_lstmax(t_list *lst, int (*comp)(void *, void *))
{
	t_list_node	*res;
	t_list_node	*cur_node;

	res = NULL;
	if (lst->begin)
	{
		res = lst->begin;
		cur_node = lst->begin->next;
		while (cur_node)
		{
			if (comp(res, cur_node) < 0)
				res = cur_node;
			cur_node = cur_node->next;
		}
	}
	return (res);
}

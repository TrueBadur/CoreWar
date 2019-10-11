/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lsttake.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleann <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 18:50:39 by jleann            #+#    #+#             */
/*   Updated: 2019/04/05 18:50:40 by jleann           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list_node	*ft_lsttake(t_list *lst)
{
	t_list_node *res;

	if (!(lst->begin))
		return (NULL);
	res = lst->begin;
	lst->begin = res->next;
	lst->len -= 1;
	res->next = NULL;
	res->prev = NULL;
	if (lst->len == 0)
		lst->end = NULL;
	return (res);
}

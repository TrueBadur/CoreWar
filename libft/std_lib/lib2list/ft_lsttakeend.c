/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lsttakeend.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleann <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 18:50:39 by jleann            #+#    #+#             */
/*   Updated: 2019/04/05 18:50:40 by jleann           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list_node	*ft_lsttakeend(t_list *lst)
{
	t_list_node *res;

	if (!(lst->end))
		return (NULL);
	res = lst->end;
	lst->end = res->prev;
	lst->end->next = NULL;
	lst->len -= 1;
	res->next = NULL;
	res->prev = NULL;
	if (lst->len == 0)
		lst->begin = NULL;
	return (res);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleann <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 18:50:39 by jleann            #+#    #+#             */
/*   Updated: 2019/04/05 18:50:40 by jleann           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

int	ft_lstiter(t_list *list, int (*f)(void *))
{
	t_list_node	*cur;
	int			res;

	res = 0;
	cur = list->begin;
	while (cur)
	{
		res += f(cur->content);
		cur = cur->next;
	}
	return (res);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstat.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleann <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 18:50:39 by jleann            #+#    #+#             */
/*   Updated: 2019/04/05 18:50:40 by jleann           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list_node	*ft_lstat(t_list *lst, size_t offset)
{
	t_list_node	*res;
	size_t		cur;

	cur = 0;
	res = lst->begin;
	while (cur < offset && res)
	{
		res = res->next;
		cur++;
	}
	return (res);
}

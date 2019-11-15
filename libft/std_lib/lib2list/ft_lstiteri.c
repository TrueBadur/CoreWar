/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleann <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 18:50:39 by jleann            #+#    #+#             */
/*   Updated: 2019/04/05 18:50:40 by jleann           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

int	ft_lstiteri(t_list *list, int (*f)(void *, int))
{
	t_list_node	*cur;
	int			res;
	int			cur_cnt;

	cur_cnt = 0;
	res = 0;
	cur = list->begin;
	while (cur)
	{
		res += f(cur->content, cur_cnt);
		cur = cur->next;
		cur_cnt++;
	}
	return (res);
}

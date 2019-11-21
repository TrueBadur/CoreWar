/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 16:24:31 by wgorold           #+#    #+#             */
/*   Updated: 2019/11/21 21:44:31 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "merge.h"

void	free_list_without_content(t_list *lst)
{
	t_list_node	*node;
	t_list_node	*tmp;

	if (lst->len == 0)
	{
		free(lst);
		return ;
	}
	node = lst->begin;
	while (node)
	{
		tmp = node->next;
		free(node);
		node = tmp;
	}
	free(lst);
}

/*
** code - 0 - never pass
** code - 1 - error malloc list
** code - 2 - list already sorter
** code - 3 - ok after merge
*/

int		free_nms(t_list *control, t_list *trash, int code)
{
	if (code == 3)
	{
		free_list_without_content(trash);
		free(control->end);
		free(control);
	}
	else
	{
		free_list_without_content(trash);
		free_list_without_content(control);
	}
	return (code == 1) ? 1 : 0;
}

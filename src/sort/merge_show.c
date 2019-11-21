/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_show.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 16:24:31 by wgorold           #+#    #+#             */
/*   Updated: 2019/11/21 21:44:35 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "merge.h"

int		show(void *data)
{
	printf("%d -> ", *(int *)(data));
	return (0);
}

int		show_sub(void *data)
{
	t_list_node	*cur;

	cur = (t_list_node	*)data;
	while (cur)
	{
		printf("%d -> ", *(int *)(cur->content));
		cur = cur->next;
	}
	return (0);
}

void	show_cs_from_back(t_list_node *node, t_list_node *end)
{
	if (SILENT_NMS)
		return ;
	printf("node: ");
	show_sub(node->content);
	printf("\n");
	while (end)
	{
		printf("%zu: ", end->content_size);
		show_sub(end->content);
		end = end->prev;
		printf("\n");
	}
	printf("\n");
}

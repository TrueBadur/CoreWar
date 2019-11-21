/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_nature_merge.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 16:24:31 by wgorold           #+#    #+#             */
/*   Updated: 2019/11/21 21:44:34 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "merge.h"

int		nms_init(t_list *to_sort, t_list **control, t_list **trash,
					int (*f)(void *left, void *right))
{
	*control = ft_lstinit();
	*trash = ft_lstinit();
	return (nms_cnt_lst(*control, to_sort, f));
}

int		nms_end(t_list *to_sort, t_list *control,
				t_list *trash, t_list_node *node)
{
	to_sort->begin = node->content;
	while (to_sort->end->next)
		to_sort->end = to_sort->end->next;
	return (free_nms(control, trash, 3));
}

int		nms(t_list *to_sort, int (*f)(void *left, void *right))
{
	t_list		*control;
	t_list		*trash;
	t_list_node	*node;
	int			err;

	if ((err = nms_init(to_sort, &control, &trash, f)))
		return (free_nms(control, trash, err));
	node = control->begin;
	show_cs_from_back(node, control->end);
	while (!(node->next == NULL && node->prev == NULL))
	{
		if (node->prev == NULL)
			node = node->next;
		else if (node->next == NULL && node->prev->prev == NULL)
			to_sort->end = merge(node->prev, node, trash, f);
		else if (node->next == NULL)
			merge(node->prev, node, trash, f);
		else if (node->content_size == node->prev->content_size)
			merge(node->prev, node, trash, f);
		else
			node = node->next;
		show_cs_from_back(node, control->end);
	}
	return (nms_end(to_sort, control, trash, node));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_control.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 16:24:31 by wgorold           #+#    #+#             */
/*   Updated: 2019/11/21 21:44:30 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "merge.h"

/*
** TODO add insert sort for small lists
*/
/*
** 0 - ok
** 1 - error
** 2 - sorted
*/

int		nms_cnt_lst_end(t_list *control, t_list_node *begin)
{
	t_list_node	*to_add;

	if (control->len > 0)
	{
		if ((to_add = ft_lstnew_noc(begin, 0)) == NULL)
			return (1);
		ft_lstaddend(control, to_add);
		return (0);
	}
	return (2);
}

int		nms_cnt_lst(t_list *control, t_list *to_sort,
					int (*f)(void *left, void *right))
{
	t_list_node	*n_left;
	t_list_node	*n_right;
	t_list_node	*to_add;
	t_list_node *begin;

	begin = to_sort->begin;
	n_left = to_sort->begin;
	n_right = n_left->next;
	while (n_right)
	{
		if (!f(n_left->content, n_right->content))
		{
			if ((to_add = ft_lstnew_noc(begin, 0)) == NULL)
				return (1);
			ft_lstaddend(control, to_add);
			begin = n_right;
			n_left->next = NULL;
			n_right->prev = NULL;
		}
		n_left = n_right;
		n_right = n_left->next;
	}
	return (nms_cnt_lst_end(control, begin));
}

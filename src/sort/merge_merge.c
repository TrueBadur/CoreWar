/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_merge.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 16:24:31 by wgorold           #+#    #+#             */
/*   Updated: 2019/11/21 21:44:33 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "merge.h"

/*
** update value of merged right node
** delete from list merged left node
** add deleted node to trash
*/

void		update_node(t_list_node *left, t_list_node *right, t_list *trash)
{
	left->content = NULL;
	if (left->content_size > right->content_size)
		right->content_size = left->content_size;
	right->content_size += 1;
	right->prev = left->prev;
	left->next = NULL;
	left->prev = NULL;
	left->content = NULL;
	left->content_size = 0;
	ft_lstaddend(trash, left);
}

/*
** merge return last yarn node
*/

t_list_node	*merge(t_list_node *left, t_list_node *right, t_list *trash,
						int (*f)(void *left, void *right))
{
	t_list_node	*yarn;
	t_list_node	*lf_tmp;
	t_list_node	*rg_tmp;
	int			yarn_state;
	int			compare;

	lf_tmp = (t_list_node *)(left->content);
	rg_tmp = (t_list_node *)(right->content);
	yarn = NULL;
	compare = f(lf_tmp->content, rg_tmp->content);
	right->content = (compare) ? lf_tmp : rg_tmp;
	yarn_state = (compare) ? -1 : 1;
	while (weave(&yarn, &lf_tmp, &rg_tmp, yarn_state))
	{
		compare = f(lf_tmp->content, rg_tmp->content);
		if (yarn_state == 1 && compare)
			swap_clew(yarn, lf_tmp, rg_tmp, &yarn_state);
		else if (yarn_state == -1 && !compare)
			swap_clew(yarn, lf_tmp, rg_tmp, &yarn_state);
	}
	update_node(left, right, trash);
	return (yarn);
}

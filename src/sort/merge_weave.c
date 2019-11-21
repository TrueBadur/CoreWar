/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_weave.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 16:24:31 by wgorold           #+#    #+#             */
/*   Updated: 2019/11/21 21:44:36 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "merge.h"

int		weave_job(t_list_node **yarn, t_list_node **clew, t_list_node *nthr)
{
	*yarn = *clew;
	*clew = (*clew)->next;
	if (*clew == NULL)
	{
		(*yarn)->next = nthr;
		nthr->prev = *yarn;
		return (0);
	}
	return (1);
}

int		weave(t_list_node **yarn, t_list_node **left_clew,
				t_list_node **right_clew, int yarn_state)
{
	t_list_node **clew;
	t_list_node *nthr;

	clew = (yarn_state == 1) ? right_clew : left_clew;
	nthr = (yarn_state == 1) ? *left_clew : *right_clew;
	return (weave_job(yarn, clew, nthr));
}

void	swap_clew_job(t_list_node *yarn, t_list_node *trg_clew,
						t_list_node *old, int *yarn_state)
{
	yarn->next = trg_clew;
	trg_clew->prev = yarn;
	old->prev = NULL;
	*yarn_state = -(*yarn_state);
}

void	swap_clew(t_list_node *yarn, t_list_node *left_clew,
					t_list_node *right_clew, int *yarn_state)
{
	t_list_node *trg_clew;
	t_list_node *old;

	trg_clew = (*yarn_state == 1) ? left_clew : right_clew;
	old = (*yarn_state == 1) ? right_clew : left_clew;
	swap_clew_job(yarn, trg_clew, old, yarn_state);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timeline_mngmnt.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehugh-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 21:42:20 by ehugh-be          #+#    #+#             */
/*   Updated: 2019/10/18 20:16:25 by ehugh-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	tl_put(t_mngr *mngr, short time, t_car *car)
{
	if (!mngr->timeline[time])
		if (!(mngr->timeline[time] = ft_memalloc(sizeof(t_list))))
			safe_exit(mngr, MALLOC_ERROR);
	ft_lstadd(mngr->timeline[time], ft_lstnew_noc(car, sizeof(void *)));
	if (mngr->timeline[time]->len && !mngr->timeline[time]->end)
		safe_exit(mngr, MALLOC_ERROR);
}

void	tl_car_iter(t_mngr *mngr, void (*f)(t_mngr*, t_car*))
{
	t_list_node *lst;

	if (!mngr->timeline[mngr->cycle % (MAX_OP_TIME + 1)])
		return ;
	lst = mngr->timeline[mngr->cycle % (MAX_OP_TIME + 1)]->begin;
	while (lst)
	{
		f(mngr, (t_car*)lst->content);
		lst = lst->next;
	}
}

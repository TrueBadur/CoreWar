/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timeline_mngmnt.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehugh-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 21:42:20 by ehugh-be          #+#    #+#             */
/*   Updated: 2019/10/14 22:15:59 by ehugh-be         ###   ########.fr       */
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

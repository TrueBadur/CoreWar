/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timeline_mngmnt.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blomo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 19:22:18 by ehugh-be          #+#    #+#             */
/*   Updated: 2019/11/13 20:11:41 by blomo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void			tl_put(t_mngr *mngr, short time, t_car *car)
{
	if (!mngr->timeline[time])
		if (!(mngr->timeline[time] = ft_vecinit(sizeof(void*) * VEC_ST_S)))
			safe_exit(mngr, MALLOC_ERROR, NULL);
	if (!(mngr->timeline[time] = ft_vecpush(mngr->timeline[time], &car,
			sizeof(void*))))
		safe_exit(mngr, MALLOC_ERROR, NULL);
}

void			tl_car_iter(t_mngr *mngr, void (*f)(t_mngr*, t_car*, short))
{
	t_car		**cars;
	int			i;
	int			cur_time;
	t_vector	*vec;

	cur_time = mngr->cycle % (MAX_OP_TIME + 1);
	vec = mngr->timeline[cur_time];
	i = mngr->timeline[cur_time]->len / sizeof(void*);
	while (--i > -1)
	{
		cars = (t_car**)mngr->timeline[cur_time]->data;
		if (cars[i]->eval_in != cur_time)
			continue ;
		f(mngr, cars[i], cur_time);
	}
	mngr->timeline[cur_time]->len = 0;
	mngr->timeline[cur_time]->offset = 0;
}

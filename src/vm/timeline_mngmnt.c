/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timeline_mngmnt.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehugh-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 19:22:18 by ehugh-be          #+#    #+#             */
/*   Updated: 2019/11/12 12:52:44 by ehugh-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void tl_put(t_mngr *mngr, short time, t_car *car)
{
	if (!mngr->timeline[time])
		if (!(mngr->timeline[time] = ft_vecinit(sizeof(void*) * VEC_ST_S)))
			safe_exit(mngr, MALLOC_ERROR);
	if(!(mngr->timeline[time] = ft_vecpush(mngr->timeline[time], &car,
			sizeof(void*))))
		safe_exit(mngr, MALLOC_ERROR);
}

void	tl_car_iter(t_mngr *mngr, void (*f)(t_mngr*, t_car*, short))
{
	t_car	**cars;
	int		i;
	int		cur_time;
	t_car	*tmp;

	cur_time = mngr->cycle % (MAX_OP_TIME + 1);
	t_vector *vec = mngr->timeline[cur_time];
	i = mngr->timeline[cur_time]->len / sizeof(void*);
	while (--i > -1)
	{
		cars = (t_car**)mngr->timeline[cur_time]->data;
		tmp = cars[i];
		// if op is valid do the op move car in space and move one step in time
		// else read op move in space and move N steps in time
		if (cars[i]->eval_in != cur_time)
			continue ;
		f(mngr, cars[i], cur_time);
	}
}

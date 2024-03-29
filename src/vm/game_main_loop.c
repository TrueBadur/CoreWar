/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_main_loop.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blomo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 16:26:51 by ehugh-be          #+#    #+#             */
/*   Updated: 2019/11/15 18:01:35 by blomo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "visu.h"

t_car			*resurect_car(t_mngr *mngr)
{
	if (mngr->dead_cars->len >= sizeof(void*))
	{
		mngr->dead_cars->len -= sizeof(void*);
		return (((t_car **)mngr->dead_cars->data)[mngr->dead_cars->len /
		sizeof(void*)]);
	}
	return (NULL);
}

t_car			*pop_car(t_vector *vec, int pos)
{
	t_car		*tmp_car;

	tmp_car = ((t_car **)vec->data)[pos];
	vec->len -= sizeof(void*);
	((t_car **)vec->data)[pos] = ((t_car**)vec->data)[vec->len / sizeof(void*)];
	return (tmp_car);
}

void			bury_car(t_mngr *mngr, int i)
{
	t_car		*car_tmp;

	car_tmp = pop_car(mngr->cars, i);
	mngr->timeline[car_tmp->eval_in]->offset =
		car_tmp->eval_in == ft_abs(mngr->timeline[car_tmp->eval_in]->offset) ?
		-mngr->num_cars : mngr->timeline[car_tmp->eval_in]->offset;
	car_tmp->eval_in = -1;
	if (!ft_vecpush_small(mngr->dead_cars, (long)car_tmp, sizeof(void*)))
		safe_exit(mngr, MALLOC_ERROR, NULL);
	mngr->num_cars--;
	if (mngr->flags & FLAG_V)
		ft_printf("Process %d hasn't lived for %d cycles (CTD %d)\n",
				car_tmp->id + 1,
		mngr->cycle - car_tmp->live_cycle, mngr->cycles_delta);
}

void			check_cars_job(t_mngr *mngr, t_car **cars)
{
	unsigned long	i;

	i = -1;
	while (++i < mngr->cars->len / sizeof(void*))
	{
		add_cars_stats(mngr, *(int*)cars[i]->regs);
		if (cars[i]->live_cycle - 1 < mngr->cycle - mngr->cycles_delta ||
			mngr->cycles_delta <= 0)
		{
			add_dies_stats(mngr, *(int*)cars[i]->regs);
			bury_car(mngr, i--);
		}
	}
}

void			check_cars(t_mngr *mngr)
{
	t_car		**cars;

	refresh_stats(mngr);
	mngr->num_checks++;
	cars = mngr->cars->data;
	check_cars_job(mngr, cars);
	if (mngr->live_num >= NBR_LIVE || mngr->num_checks >= MAX_CHECKS)
	{
		mngr->cycles_delta -= CYCLE_DELTA;
		mngr->num_checks = 0;
		if (mngr->flags & FLAG_V)
			ft_printf("Cycle to die is now %d\n", mngr->cycles_delta);
	}
	set_cycles_die_new(mngr);
	if (mngr->cycles_delta > 0)
		mngr->cycles_to_die += mngr->cycles_delta;
	mngr->live_num = 0;
	show_time_to_die(mngr);
}

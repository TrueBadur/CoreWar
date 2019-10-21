/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_main_loop.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehugh-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 16:26:51 by ehugh-be          #+#    #+#             */
/*   Updated: 2019/10/21 16:15:57 by ehugh-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	bury_car(t_mngr *mngr, int i)
{
	// push pointer to car to dead_cars
	// swap cur pointer with the last one and set decrease len
	// if cycles_delta <= 0 delete car instead of movement
	// decrease num of cars
}

void	check_cars(t_mngr *mngr)
{
	t_car	**cars;
	int		i;

	mngr->num_checks++;
	cars = mngr->cars->data;
	i = -1;
	while (++i < mngr->cars->len / sizeof(void*))
	{
		if (cars[i]->live_cycle < mngr->cycle - mngr->cycles_delta || mngr->cycles_delta <= 0)
			bury_car(mngr, i);
	}
	if (mngr->live_num >= NBR_LIVE || mngr->num_checks >= MAX_CHECKS)
	{
		mngr->cycles_delta -= CYCLE_DELTA;
		mngr->num_checks = 0;
	}
	if (mngr->cycles_delta > 0)
	mngr->cycles_to_die += mngr->cycles_delta;
}

void	dump_arena(t_mngr *mngr)
{

}

void	game_main(t_mngr *mngr)
{
	while (mngr->num_cars)
	{
		if (mngr->cycle >= mngr->cycles_to_die || mngr->cycles_delta <= 0)
			check_cars(mngr);
		make_one_turn(mngr);
		if (mngr->flags & DUMP)
			dump_arena(mngr);
		mngr->cycle++;
	}
}
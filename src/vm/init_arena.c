/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_arena.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blomo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 16:28:19 by ehugh-be          #+#    #+#             */
/*   Updated: 2019/11/13 17:17:43 by blomo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	put_champs(t_mngr *mngr)
{
	int i;
	int j;

	i = -1;
	j = -1;
	while (i < mngr->chmp_num && ++j < MAX_PLAYERS)
        if (mngr->chmps[j])
		{
			ft_memcpy(mngr->arena + (++i * MEM_SIZE / mngr->chmp_num),
					  mngr->chmps[j]->code, mngr->chmps[j]->size);
		}
}

static void init_carrieges(t_mngr *mngr)
{
	int i;
	t_car	*car;
	int j;

	if (!(mngr->cars = ft_vecinit(2 * mngr->chmp_num)))
		safe_exit(mngr, MALLOC_ERROR);
	i = 0;
	j = -1;
	while (++j < MAX_PLAYERS)
	{
		if (!mngr->chmps[j])
			continue ;
		if (!(car = ft_memalloc(sizeof(t_car))))
			safe_exit(mngr, MALLOC_ERROR);
		car->id = mngr->next_id++;
		car->pos = i++ * MEM_SIZE / mngr->chmp_num;
		car->eval_in = 1;
		if (!(mngr->cars = ft_vecpush(mngr->cars, &car, sizeof(void *))))
			safe_exit(mngr, MALLOC_ERROR);
		tl_put(mngr, 1, car);
		mngr->num_cars++;
		*(int*)car->regs = (int)(-j - 1);
		mngr->winner = j;
	}
}

void	init_arena(t_mngr *mngr)
{
	if (!(mngr->arena = ft_memalloc(MEM_SIZE)))
		safe_exit(mngr, MALLOC_ERROR);
	if (!(mngr->rxsort_out = ft_vecinit(sizeof(void*) * VEC_ST_S)))
		safe_exit(mngr, MALLOC_ERROR);
	put_champs(mngr);
	init_carrieges(mngr);
	mngr->cycle = 1;
	mngr->cycles_to_die = CYCLE_TO_DIE;
	mngr->cycles_delta = CYCLE_TO_DIE;
	if (!(mngr->dead_cars = ft_vecinit(sizeof(void*) * 8)))
		safe_exit(mngr, MALLOC_ERROR);
//	proceed_cars(mngr, 0);
}

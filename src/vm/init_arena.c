/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_arena.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blomo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 16:28:19 by ehugh-be          #+#    #+#             */
/*   Updated: 2019/10/24 14:37:59 by blomo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	put_champs(t_mngr *mngr)
{
	int i;

	i = -1;
	while (++i < mngr->chmp_num)
        if (mngr->chmps[i])
		    ft_memcpy(mngr->arena + i * MEM_SIZE / mngr->chmp_num,
				mngr->chmps[i]->code, mngr->chmps[i]->size);
}

static void init_carrieges(t_mngr *mngr)
{
	int i;
	t_car	*car;

	if (!(mngr->cars = ft_vecinit(2 * mngr->chmp_num)))
		safe_exit(mngr, MALLOC_ERROR);
	i = -1;
	while (++i < mngr->chmp_num)
	{
		if (!(car = ft_memalloc(sizeof(t_car))))
			safe_exit(mngr, MALLOC_ERROR);
		car->id = mngr->next_id;
		car->pos = i * MEM_SIZE / mngr->chmp_num;
		if (!ft_vecpush(mngr->cars, &car, sizeof(void *)))
			safe_exit(mngr, MALLOC_ERROR);
        tl_put(mngr, 0, ft_lstnew_noc(car, sizeof(void *)), 0);
		mngr->num_cars++;
		mngr->next_id++;
		*(int*)car->regs = -car->id -1 - i; //TODO deal with endians
		mngr->winner = car->id;
	}
}

void	init_arena(t_mngr *mngr)
{
	if (!(mngr->arena = ft_memalloc(MEM_SIZE)))
		safe_exit(mngr, MALLOC_ERROR);
	put_champs(mngr);
	init_carrieges(mngr);
	mngr->cycles_to_die = CYCLE_TO_DIE;
	mngr->cycles_delta = CYCLE_TO_DIE;
	mngr->dead_cars = ft_vecinit(sizeof(void*) * 8);
	proceed_cars(mngr, 0);
}

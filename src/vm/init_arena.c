/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_arena.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehugh-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 16:28:19 by ehugh-be          #+#    #+#             */
/*   Updated: 2019/11/01 17:20:49 by ehugh-be         ###   ########.fr       */
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
		safe_exit(mngr, MALLOC_ERROR, NULL);
	i = -1;
	while (++i < mngr->chmp_num)
	{
		if (!(car = ft_memalloc(sizeof(t_car))))
			safe_exit(mngr, MALLOC_ERROR, NULL);
		car->id = mngr->next_id;
		car->pos = i * MEM_SIZE / mngr->chmp_num;
		if (!ft_vecpush(mngr->cars, &car, sizeof(void *)))
			safe_exit(mngr, MALLOC_ERROR, NULL);
        tl_put(mngr, 0, ft_lstnew_noc(car, sizeof(void *)), 0);
		mngr->num_cars++;
		mngr->next_id++;
		*(int*)car->regs = (char)(-car->id - 1);
		mngr->winner = car->id;
	}
}

void	init_arena(t_mngr *mngr)
{
	if (!(mngr->arena = ft_memalloc(MEM_SIZE)))
		safe_exit(mngr, MALLOC_ERROR, NULL);
	put_champs(mngr);
	init_carrieges(mngr);
	mngr->cycles_to_die = CYCLE_TO_DIE;
	mngr->cycles_delta = CYCLE_TO_DIE;
	mngr->dead_cars = ft_vecinit(sizeof(void*) * 8);
	proceed_cars(mngr, 0);
}

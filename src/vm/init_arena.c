/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_arena.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehugh-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 16:28:19 by ehugh-be          #+#    #+#             */
/*   Updated: 2019/10/14 20:50:55 by ehugh-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	put_champs(t_mngr *mngr)
{
	int i;

	i = -1;
	while (++i < mngr->chmp_num)
		ft_memcpy(mngr->arena + i * MEM_SIZE / mngr->chmp_num,
				mngr->chmps[i].code, mngr->chmps[i].size);
}

static void init_carrieges(t_mngr *mngr)
{
	int i;
	t_car	*car;

	if (!(mngr->cars = ft_vecinit(2 * mngr->chmp_num)))
		safe_exit(mngr, MALLOC_ERROR);
	i = mngr->chmp_num;
	while (--i >= 0)
	{
		if (!(car = ft_memalloc(sizeof(t_car))))
			safe_exit(mngr, MALLOC_ERROR);
		car->id = i;
		car->pos = i * MEM_SIZE / mngr->chmp_num;
		if (!ft_vecpush(mngr->cars, &car, sizeof(void *)) ||
		!ft_vecpush(&mngr->timeline[0], &car, sizeof(void*)))
			safe_exit(mngr, MALLOC_ERROR);
	}
}

void	init_arena(t_mngr *mngr)
{
	if (!(mngr->arena = ft_memalloc(MEM_SIZE)))
		safe_exit(mngr, MALLOC_ERROR);
	put_champs(mngr);
	init_carrieges(mngr);
}

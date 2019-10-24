/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_main_loop.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blomo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 16:26:51 by ehugh-be          #+#    #+#             */
/*   Updated: 2019/10/23 18:52:28 by blomo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

t_car	*resurect_car(t_mngr *mngr)
{
    if (mngr->dead_cars->len >= sizeof(void*))
	{
		mngr->dead_cars->len -= sizeof(void*);
		return (((t_car **) mngr->dead_cars->data)[mngr->dead_cars->len / sizeof(void*)]);
	}
	return (NULL);
}

t_car	*pop_car(t_vector *vec, int pos)
{
	t_car	*tmp_car;

	tmp_car = ((t_car **)vec->data)[pos];
	vec->len -= sizeof(void*);
	((t_car **)vec->data)[pos] = ((t_car**)vec->data)[vec->len / sizeof(void*)];
	return (tmp_car);
}

void	bury_car(t_mngr *mngr, int i)
{
	t_car *car_tmp;

	car_tmp = pop_car(mngr->cars, i);
	if (mngr->cycles_delta <= 0)
		free(car_tmp);
	else
		ft_vecpush_small(mngr->dead_cars, (long)car_tmp, sizeof(void*));
	mngr->num_cars--;
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
    int i;
    int j;

    j = 0;
    i = 0;
    while (i < 64)
    {
        if(i == 0)
            ft_printf("0x0000 : ");
        else
            ft_printf("%#.4x : ", i*64);
        while(j < 64)
        {
            if(mngr->arena[j + 64*i] < 16)
            {
                ft_printf("0");
                ft_printf("%x ", mngr->arena[j + 64 * i]);
            }
            else
                ft_printf("{\\76}%x {eof}", mngr->arena[j + 64 * i]);
            j++;
        }
        printf("\n");
        j = 0;
        i++;
    }
    exit(0);
}

#define DUMP_TIME 1

void	game_main(t_mngr *mngr)
{
	while (mngr->num_cars)
	{
		make_one_turn(mngr);
        if (mngr->flags & DUMP && mngr->cycle == mngr->dump_nbr)
            dump_arena(mngr);
        if (mngr->cycle >= mngr->cycles_to_die || mngr->cycles_delta <= 0)
            check_cars(mngr);
		mngr->cycle++;
	}
}
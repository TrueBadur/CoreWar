/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_main_loop.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehugh-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 16:26:51 by ehugh-be          #+#    #+#             */
/*   Updated: 2019/11/06 22:44:10 by ehugh-be         ###   ########.fr       */
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

void ft_lstdel_by_val(t_list *lst, int (*f)(void*, void*), void *cmp)
{
	t_list_node *node;

	node = lst->begin;
	while(node)
	{
		if (!f(node->content, cmp))
		{
			if (node->prev)
				node->prev->next = node->next;
			else
				lst->begin = node->next;
			if (node->next)
				node->next->prev = node->prev;
			else
				lst->end = node->prev;
			lst->len -= 1;
			free(node);
			return ;
		}
		node = node->next;
	}
}

int car_in_lst(void *lst_cont, void *car_cont)
{
	return (lst_cont != car_cont);
}

void	bury_car(t_mngr *mngr, int i)
{
	t_car *car_tmp;
	int			car_i;
	t_vector *time;

	car_tmp = pop_car(mngr->cars, i);
	time = mngr->timeline[car_tmp->eval_in]; //todo car can't be find in given time
	car_i = ft_vecbinsearch(time, car_tmp, NULL);
	time->len -= sizeof(void*);
	ft_memmove(time->data + car_i * sizeof(void*), time->data + time->len,
			sizeof(void*));
	if (mngr->cycles_delta <= 0)
		free(car_tmp);
	else
		if (!ft_vecpush_small(mngr->dead_cars, (long)car_tmp, sizeof(void*)))
			safe_exit(mngr, MALLOC_ERROR);
	mngr->num_cars--;
	if (mngr->flags & FLAG_V)
		ft_printf("{\\200}Process {Red}%d {\\200}hasn't lived for {Red}%d"
"{\\200} (CTD {Red}%d{eof})\n", car_tmp->id + 1, mngr->cycle - car_tmp->live_cycle,
mngr->cycles_delta);
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
		if (cars[i]->live_cycle - 1 < mngr->cycle - mngr->cycles_delta || mngr->cycles_delta <= 0)
			bury_car(mngr, i--);
	}
	if (mngr->live_num >= NBR_LIVE || mngr->num_checks >= MAX_CHECKS)
	{
		mngr->cycles_delta -= CYCLE_DELTA;
		mngr->num_checks = 0;
		if (mngr->flags & FLAG_V)
			ft_printf("{\\35}Cycles to die{eof} is now {\\92}%d{eof}\n",
				  mngr->cycles_delta);
	}
	if (mngr->cycles_delta > 0)
		mngr->cycles_to_die += mngr->cycles_delta;
	mngr->live_num = 0;
}

void	dump_arena(t_mngr *mngr)
{
    int i;
    int j;

    i = -1;
    while (++i < 64)
    {
        if(i == 0)
            ft_printf("0x0000 : ");
        else
            ft_printf("%#.4x : ", i * 64);
		j = -1;
        while(++j < 64)
        {
//            if(mngr->arena[j + 64 * i] <=9 && mngr->arena[j + 64 * i] > 0)
//                ft_printf("{Green}0%x {eof}", mngr->arena[j + 64 * i]);
//            else if (mngr->arena[j + 64 * i] == 0)
//                ft_printf("{Black}0%x {eof}", mngr->arena[j + 64 * i]);
//            else if (mngr->arena[j + 64 * i] < 16)
//                ft_printf("{\\200}0%x {eof}", mngr->arena[j + 64 * i]);
//            else
//                ft_printf("{Red}%x {eof}", mngr->arena[j + 64 * i]);
			if(mngr->arena[j + 64 * i] <=9 && mngr->arena[j + 64 * i] > 0)
				ft_printf("0%x ", mngr->arena[j + 64 * i]);
			else if (mngr->arena[j + 64 * i] == 0)
				ft_printf("0%x ", mngr->arena[j + 64 * i]);
			else if (mngr->arena[j + 64 * i] < 16)
				ft_printf("0%x ", mngr->arena[j + 64 * i]);
			else
				ft_printf("%x ", mngr->arena[j + 64 * i]);
        }
        ft_printf("\n");
    }
   safe_exit(mngr,CALL_DUMP);
}

#define DUMP_TIME 1
#define CYCLE_DEBUG 1

void	game_main(t_mngr *mngr)
{
	while (mngr->num_cars)
	{
	    make_one_turn(mngr);
        if (mngr->flags & FLAG_DUMP && mngr->cycle == mngr->dump_nbr)
            dump_arena(mngr);
        if (mngr->cycle >= mngr->cycles_to_die || mngr->cycles_delta <= 0)
            check_cars(mngr);
		mngr->cycle++;
		if (mngr->flags & FLAG_V)
			ft_printf("Now in cycle {Red}%d{eof}\n", mngr->cycle);
	}
}
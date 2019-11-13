/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stats.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 18:38:24 by wgorold           #+#    #+#             */
/*   Updated: 2019/11/01 18:38:35 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

t_stats	*get_stats(void)
{
	static t_stats	st;
	static int		init;
	int i;


	if (init == 0)
	{
		st.images[0] = show_skull_two;
		st.images[1] = show_skull_two;
		st.images[2] = show_skull_two;
		st.images[3] = show_skull_three;
		st.last_death_wave_cycle = 0;
		st.rate = 0;
		st.phase_game = G_PHASE_INIT;
		st.game_mod = G_MOD_PAUSE_SELECT;
		init = 1;
		i = -1;
		while (++i)
		{
			st.arena[i] = 0;
			st.color[i] = 0;
            st.arena_old[i] = 0;
            st.color_old[i] = 0;
		}
	}
	return &st;
}

void	refresh_stats(t_mngr *mngr)
{
	t_stats *st;
	int		idx;

	if (!(mngr->flags & FLAG_S))
		return ;
	st = get_stats();
	idx = -1;
	while (++idx < MAX_PLAYERS + 1)
	{
		st->cars[idx] = 0;
		st->dies[idx] = 0;
	}
	st->cycles_to_die = 0;
	st->cycles_to_die_new = 0;
	st->cycle = 0;
	st->total = 0;
	st->total_die = 0;
	st->death_wave += 1;
	set_cycles_die(mngr);
	set_cycle(mngr);
}

void 	add_cars_stats(t_mngr *mngr, int reg)
{
	t_stats *st;

	if (!(mngr->flags & FLAG_S))
		return ;
	st = get_stats();
	if (reg > -1 || reg < -4)
		st->cars[4] += 1;
	else
		st->cars[-reg - 1] += 1;
}

void 	add_dies_stats(t_mngr *mngr, int reg)
{
	t_stats *st;

	if (!(mngr->flags & FLAG_S))
		return ;
	st = get_stats();
	if (reg > -1 || reg < -4)
		st->dies[4] += 1;
	else
		st->dies[-reg - 1] += 1;
}

void	recalc_total()
{
	t_stats *st;
	int		idx;

	st = get_stats();
	st->total = 0;
	st->total_die = 0;
	idx = -1;
	while (++idx < MAX_PLAYERS + 1)
		st->total += (int)st->cars[idx];
	idx = -1;
	while (++idx < MAX_PLAYERS + 1)
		st->total_die += (int)st->dies[idx];
}

void	set_cycles_die(t_mngr *mngr)
{
	t_stats *st;

	st = get_stats();
	st->cycles_to_die = mngr->cycles_delta;
}

void	set_cycles_die_new(t_mngr *mngr)
{
	t_stats *st;

	if (!(mngr->flags & FLAG_S))
		return ;
	st = get_stats();
	st->cycles_to_die_new = mngr->cycles_to_die;
}

void	set_cycle(t_mngr *mngr)
{
	t_stats *st;

	if (!(mngr->flags & FLAG_S))
		return ;
	st = get_stats();
	st->cycle = mngr->cycle;
}
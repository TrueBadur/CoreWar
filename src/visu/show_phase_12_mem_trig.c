/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_phase_12_mem_trig.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 18:38:24 by wgorold           #+#    #+#             */
/*   Updated: 2019/11/14 13:42:45 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	show_bar_death(WINDOW *win, t_mngr *mngr, t_stats *st)
{
	int total;
	int	next_in;
	int bar;

	total = mngr->cycles_to_die - st->last_death_wave_cycle;
	next_in = mngr->cycles_to_die - mngr->cycle;
	next_in = (int)(100.0 * next_in / total);
	bar = -1;
	wprintw(win, "    [");
	while (bar++ < next_in / 2)
		wprintw(win, "-");
	while (bar++ < 50)
		wprintw(win, " ");
	wprintw(win, "]\n\n");
}

void	show_scnd_panel(t_mngr *mngr)
{
	t_stats *st;
	WINDOW	*win;

	st = get_stats();
	win = get_win(WIN_G_PLY);
	werase(win);
	wprintw(win, "    Cycle:");
	wprintw(win, "\t\t\t%d\n\n", mngr->cycle);
	wprintw(win, "    Cars:\t\t\t%d\n\n", mngr->num_cars);
	wprintw(win, "    Next death wave in:");
	wprintw(win, "\t\t%d\n", mngr->cycles_to_die - mngr->cycle);
	show_bar_death(win, mngr, st);
	wrefresh(win);
}

int		reprint_mem(t_mngr *mngr, t_stats *st)
{
	int	idx;
	int	out;

	out = 0;
	idx = -1;
	while (++idx < MEM_SIZE)
	{
		if (st->arena_old[idx] == st->arena[idx]
			&& st->color_old[idx] / 10 == 0)
			continue;
		if (st->arena_old[idx] == st->arena[idx]
			&& st->color_old[idx] / 10)
		{
			st->color_old[idx] -= 10;
			show_pos_in_arena(mngr, idx, st->color_old[idx]);
			continue;
		}
		st->arena_old[idx] = st->arena[idx];
		st->color_old[idx] = -st->color[idx] + 10;
		st->color[idx] = -st->color[idx];
		show_pos_in_arena(mngr, idx, st->color_old[idx]);
		out = 1;
	}
	return (out);
}

void	show_area(t_mngr *mngr)
{
	t_stats *st;

	if (!(mngr->flags & FLAG_S))
		return ;
	st = get_stats();
	if (st->phase_game == G_PHASE_TTD)
		reshow_area(mngr);
	st->phase_game = G_PHASE_MEM;
	show_scnd_panel(mngr);
	if (reprint_mem(mngr, st))
	{
		curs_set(0);
		wrefresh(get_win(WIN_MAIN));
		pause_or_wait_mem_change(st);
	}
}

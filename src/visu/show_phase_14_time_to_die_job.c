/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_phase_13_time_to_die.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 18:38:24 by wgorold           #+#    #+#             */
/*   Updated: 2019/11/14 13:42:46 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	show_bar_gen(t_stats *st, WINDOW *win)
{
	int bar;
	int	rip;

	rip = (int)(100.0 * st->total_die / st->total);
	bar = -1;
	wprintw(win, "\t    [");
	while (++bar < 100 - rip)
		wprintw(win, "+");
	while (bar++ < 100)
		wprintw(win, "-");
	wprintw(win, "]\n");
}

void	print_gen(t_stats *st, WINDOW *win)
{
	double	per;

	wattron(win, COLOR_PAIR(DEF));
	per = 100.0 * st->total_die / st->total;
	wprintw(win, "Death wave  = \t%d\n", st->death_wave);
	wprintw(win, "Cycle       = \t%d\n", st->cycle);
	wprintw(win, "Num cars    = \t%d\n", st->total);
	wprintw(win, "Num dies    = %3.0f%%\t%d\n", per, st->total_die);
	wprintw(win, "Cycle 2 die = \t%d -> %d\n",
			st->cycles_to_die, st->cycles_to_die_new);
	show_bar_gen(st, win);
}

void	show_bar(int id, t_stats *st, WINDOW *win)
{
	int bar;
	int	live;
	int	rip;

	if (st->cars[id] == 0)
	{
		wprintw(win, "\n");
		return ;
	}
	live = (int)(100.0 * st->cars[id] / st->total);
	rip = (int)(100.0 * st->dies[id] / st->total);
	bar = -1;
	wprintw(win, "\t    [");
	while (++bar < live - rip)
		wprintw(win, "#");
	if (live - rip < 1)
		wattron(win, COLOR_PAIR(DOOM));
	else
		wattron(win, COLOR_PAIR(RIP));
	while (bar++ < live)
		wprintw(win, "#");
	wattron(win, COLOR_PAIR(id + COL_PLY_SHIFT));
	while (bar++ < 100)
		wprintw(win, " ");
	wprintw(win, "]\n");
}

void	show_champ_name(t_mngr *mngr, WINDOW *win, int idx)
{
	wattron(win, COLOR_PAIR(idx + COL_PLY_SHIFT));
	wprintw(win, "\n\nidx=%d\t", idx + 1);
	if (idx < mngr->chmp_num || idx == 4)
	{
		wattron(win, COLOR_PAIR(idx + COL_PLY_HIGH_SHIFT));
		if (idx == 4)
			wprintw(win, " unknown ");
		else
			wprintw(win, " %.16s ", mngr->chmps[idx]->name);
	}
}

void	show_champ_stats(t_mngr *mngr, WINDOW *win)
{
	t_stats	*st;
	int		idx;
	double	per;

	st = get_stats();
	recalc_total();
	print_gen(st, win);
	idx = -1;
	while (++idx < MAX_PLAYERS + 1)
	{
		show_champ_name(mngr, win, idx);
		wattron(win, COLOR_PAIR(idx + COL_PLY_SHIFT));
		per = 100.0 * st->dies[idx] / st->cars[idx];
		wprintw(win, "\np%d_cars    = %3.0f%%\t%d\n",
		idx + 1, 100.0 * st->cars[idx] / st->total, st->cars[idx]);
		wprintw(win, "p%d_dies    = ", idx + 1);
		if ((int)per == 100)
			wattron(win, COLOR_PAIR(DOOM));
		else if ((int)per > 0)
			wattron(win, COLOR_PAIR(RIP));
		wprintw(win, "%3.0f%%", per);
		wattron(win, COLOR_PAIR(idx + COL_PLY_SHIFT));
		wprintw(win, "\t%d\n", st->dies[idx]);
		show_bar(idx, st, win);
	}
}

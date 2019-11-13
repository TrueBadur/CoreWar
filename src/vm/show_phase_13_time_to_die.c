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

void	show_bar_gen(t_stats *st, WINDOW *win)
{
	int bar;
	int	rip;

	rip = (int) (100.0 * st->total_die / st->total);
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
	wprintw(win, "Cycle 2 die = \t%d -> %d\n", st->cycles_to_die, st->cycles_to_die_new);
	show_bar_gen(st, win);
}

void	show_bar(int id, t_stats *st, WINDOW *win)
{
	int bar;
	int	live;
	int	rip;

	if (st->cars[id] == 0) {
		wprintw(win, "\n");
		return;
	}
	live = (int) (100.0 * st->cars[id] / st->total);
	rip = (int) (100.0 * st->dies[id] / st->total);
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
	wattron(win, COLOR_PAIR(id + 1));
	while (bar++ < 100)
		wprintw(win, " ");
	wprintw(win, "]\n");
}

void	show_champ_stats(WINDOW	*win, t_mngr *mngr)
{
	t_stats	*st;
	int		idx;
	double	per;
	double	pop;

	st = get_stats();
	recalc_total();
	print_gen(st, win);
	idx = -1;
	while (++idx < MAX_PLAYERS + 1)
	{
		wattron(win, COLOR_PAIR(idx + 1));
		wprintw(win,"\n\nidx=%d\t", idx + 1);
		if (idx < mngr->chmp_num || idx == 4)
		{
			wattron(win, COLOR_PAIR(idx + 1 + 10));
			if (idx == 4)
				wprintw(win, " unknown ");
			else
				wprintw(win, " %.16s ", mngr->chmps[idx]->name);
		}
		wattron(win, COLOR_PAIR(idx + 1));
		pop = 100.0 * st->cars[idx] / st->total;
		per = 100.0 * st->dies[idx] / st->cars[idx];
		wprintw(win, "\np%d_cars    = %3.0f%%\t%d\n", idx + 1, pop, st->cars[idx]);
		wprintw(win, "p%d_dies    = ", idx + 1);
		if ((int)per == 100)
			wattron(win, COLOR_PAIR(DOOM));
		else if ((int)per > 0)
			wattron(win,COLOR_PAIR(RIP));
		wprintw(win, "%3.0f%%", per);
		wattron(win, COLOR_PAIR(idx + 1));
		wprintw(win, "\t%d\n", st->dies[idx]);
		show_bar(idx, st, win);
	}
}

void	show_time_to_die(t_mngr *mngr)
{
	t_stats *st;
	WINDOW	*win;

	if (!(mngr->flags & FLAG_S))
		return ;
	st = get_stats();
	st->last_death_wave_cycle = mngr->cycle;
	if (st->game_mod == G_MOD_NO_PAUSE)
		return ;
	clear_mem_trig_screen();
	st->phase_game = G_PHASE_TTD;
	win = get_win(WIN_D_IMG);
	//wborder(win, '#', '#', '#', '#', '#', '#', '#', '#');
	show_skull_one(win);
	wrefresh(win);

	win = get_win(WIN_D_BAN);
	//wborder(win, '#', '#', '#', '#', '#', '#', '#', '#');
	show_time_banner(win);
	wrefresh(win);

	win = get_win(WIN_D_STA);
	//wborder(win, '#', '#', '#', '#', '#', '#', '#', '#');
	show_champ_stats(win, mngr);
	wrefresh(win);
	getchar();
}
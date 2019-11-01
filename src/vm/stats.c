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
	static t_stats st;

	return &st;
}

WINDOW	**get_windows()
{
	static WINDOW *wins[6];
	static int is_set;

	if (is_set == 0)
	{
		int lin;
		int col;
		int spac;

		lin = 10;
		col = 20;
		spac = 10;
		wins[0] = newwin(lin, col, spac, spac);
		wins[1] = newwin(lin, col, spac, col + spac);
		wins[2] = newwin(lin, col, lin + spac, spac);
		wins[3] = newwin(lin, col, lin + spac, col + spac);
		wins[4] = newwin(lin, col, 2 * lin + spac, spac);
		wins[5] = newwin(lin, col, 2 * lin + spac, col + spac);
		wattron(wins[0], COLOR_PAIR(1));
		wattron(wins[1], COLOR_PAIR(2));
		wattron(wins[2], COLOR_PAIR(3));
		wattron(wins[3], COLOR_PAIR(4));
		wattron(wins[4], COLOR_PAIR(5));
		wattron(wins[5], COLOR_PAIR(6));
		is_set = 1;
	}

	return wins;
}

WINDOW	*get_win(int id)
{
	WINDOW	**tmp;

	tmp = get_windows();
	return tmp[id];
}

void	refresh_stats()
{
	t_stats *st;
	int		idx;

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
}

void 	add_cars_stats(int reg) {
	t_stats *st;

	st = get_stats();
	if (reg > -1 || reg < -4)
		st->cars[4] += 1;
	else
		st->cars[-reg - 1] += 1;
}

void 	add_dies_stats(int reg)
{
	t_stats *st;

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
	idx = -1;
	while (++idx < MAX_PLAYERS + 1)
		st->total += (int)st->cars[idx];
}

void	print_gen(t_stats *st)
{
	WINDOW	*win;
	int		lin;

	lin = 1;

	win = get_win(0);
	wborder(win, 0, 0, 0, 0, 0, 0, 0, 0);
	printw("Cycle \n# %d\n(%d)\n", st->cycle, st->total);
	printw("Cycles to die\n %d \n-> \n%d\n", st->cycles_to_die, st->cycles_to_die_new);
	wrefresh(win);
	getchar();
}

void	show_stats()
{
	t_stats	*st;
	int		lin;
	int		idx;
	int		total;
	double	per;
	double	per_tot;
	WINDOW	*win;

	lin = 0;
	total = 0;
	st = get_stats();
	recalc_total();
	print_gen (st);

	idx = -1;
	while (++idx < MAX_PLAYERS + 1)
	{
		win = get_win(idx + 1);
		wborder(win, 0, 0, 0, 0, 0, 0, 0, 0);
		wrefresh(win);
		getchar();
		/*
		move(lin++, 0);
		if (st->cars[idx] == 0)
			clrtoeol();
		else
		{
			per = 100.0 * st->dies[idx] / st->cars[idx];
			per_tot = 100.0 * st->dies[idx] / total;
			printw("p%d_cars= %d\tvs\t%d\t[ %3.0f%% ][ %3.0f%% ]\n", idx + 1, st->cars[idx],
				   st->dies[idx], per, per_tot);
		}
		 */
	}
	getchar();
	curs_set(0);
	refresh();
	getchar();
}

void	set_cycles_die(int to_set)
{
	t_stats *st;

	st = get_stats();
	st->cycles_to_die = to_set;
}

void	set_cycles_die_new(int to_set)
{
	t_stats *st;

	st = get_stats();
	st->cycles_to_die_new = to_set;
}

void	set_cycle(int to_set)
{
	t_stats *st;

	st = get_stats();
	st->cycle = to_set;
}
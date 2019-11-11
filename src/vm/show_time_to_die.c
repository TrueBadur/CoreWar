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

# define COL_SEP 100
# define LIN_SHIFT 2
# define RND 1

void	show_bar_gen(t_stats *st)
{
	int bar;
	int	rip;

	rip = (int) (100.0 * st->total_die / st->total);
	bar = -1;
	printw("\t\t[");
	while (++bar < 100 - rip)
		printw("+");
	//attron(COLOR_PAIR(DOOM));
	while (bar++ < 100)
		printw("-");
	//attron(COLOR_PAIR(DEF));
	printw("]");
}

void	print_gen(t_stats *st)
{
	int		lin;
	int		col;
	double	per;

	lin = 9;
	col = COL_SEP;
	per = 100.0 * st->total_die / st->total;

	mvprintw(lin++, col, "Death wave  = \t%d", st->death_wave);
	mvprintw(lin++, col, "Cycle       = \t%d", st->cycle);
	mvprintw(lin++, col, "Num cars    = \t%d", st->total);
	mvprintw(lin++, col, "Num dies    = %3.0f%%\t%d", per, st->total_die);
	mvprintw(lin++, col, "Cycle 2 die = \t%d -> %d", st->cycles_to_die, st->cycles_to_die_new);
	move(lin++, col);
	show_bar_gen(st);
}

/*
** printw("total= %d\tlive= %d\trip= %d\n", st->total, live, rip);
*/

void	show_bar(int id, t_stats *st)
{
	int bar;
	int	live;
	int	rip;

	if (st->cars[id] == 0)
		return ;
	live = (int) (100.0 * st->cars[id] / st->total);
	rip = (int) (100.0 * st->dies[id] / st->total);
	bar = -1;
	printw("\t\t[");
	while (++bar < live - rip)
		printw("#");
	if (live - rip < 1)
		attron(COLOR_PAIR(DOOM));
	else
		attron(COLOR_PAIR(RIP));
	while (bar++ < live)
		printw("#");
	attron_ply_clr(id);
	while (bar++ < 100)
		printw(" ");
	printw("]");
}

void	show_stats()
{
	t_stats	*st;
	int		idx;
	double	per;
	double	pop;
	int		lin;

	st = get_stats();
	recalc_total();
	attron(COLOR_PAIR(DEF));
	move(0,0);

	show_skull_one();
	//show_skull_two();
	//show_skull_three();
	//show_nuke();
	/*
	if (RND < IMG_NUM)
		st->images[rand() % RND]();
	else
		st->images[rand() % IMG_NUM]();
	 */
	show_time_to_die();
	print_gen(st);
	idx = -1;
	lin = 16;
	while (++idx < MAX_PLAYERS + 1)
	{
		attron_ply_clr(idx);
		mvprintw(lin++, COL_SEP,"idx=%d", idx + 1);
		pop = 100.0 * st->cars[idx] / st->total;
		per = 100.0 * st->dies[idx] / st->cars[idx];
		mvprintw(lin++, COL_SEP, "p%d_cars    = %3.0f%%\t%d", idx + 1, pop, st->cars[idx]);
		mvprintw(lin++, COL_SEP, "p%d_dies    = ", idx + 1);
		if ((int)per == 100)
			attron(COLOR_PAIR(DOOM));
		else if ((int)per > 0)
			attron(COLOR_PAIR(RIP));
		printw("%3.0f%%", per);
		attron_ply_clr(idx);
		printw("\t%d", st->dies[idx]);
		move(lin++, COL_SEP);
		show_bar(idx, st);
		lin += LIN_SHIFT;
	}
	curs_set(0);
	refresh();
	getchar();
}
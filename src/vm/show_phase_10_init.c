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

void 	show_game_init_border()
{
	WINDOW	*win;

	win = get_win(WIN_MAIN_BORDER);
	wborder(win, '#', '#', '#', '#', '#', '#', '#', '#');
	wrefresh(win);
	win = get_win(WIN_CNTR_BORDER);
	wborder(win, '#', '#', '#', '#', '#', '#', '#', '#');
	wprintw(win, "> Control panel <");
	wrefresh(win);
	win = get_win(WIN_PLY_BORDER);
	wborder(win, '#', '#', '#', '#', '#', '#', '#', '#');
	wprintw(win, "> Players panel <");
	wrefresh(win);
}

void	show_game_init(t_mngr *mngr)
{
	int i;
	int j;
	int lin;
	WINDOW	*win;

	if (!(mngr->flags & FLAG_S))
		return ;
	show_game_init_border();
	win = get_win(WIN_MAIN);
	lin = LIN_STEP - 1;
	i = -1;
	while ((++i * COL_IN_LIN) < MEM_SIZE)
	{
		move(++lin, 0);
		j = -1;
		while(++j < COL_IN_LIN - 1)
			wprintw(win, "%02x ", mngr->arena[j + COL_IN_LIN * i]);
		wprintw(win, "%02x", mngr->arena[j + COL_IN_LIN * i]);
	}
	wrefresh(win);
	show_side_panel_init(mngr, -1);
	getchar();
}

void	show_champ_mem_init(t_mngr *mngr, int start, int size, int idx)
{
	t_stats *st;

	if (!(mngr->flags & FLAG_S))
		return ;
	st = get_stats();
	size += start;
	while (start < size)
	{
		st->arena[start] = mngr->arena[start];
		st->color[start] = idx + 1;
		st->arena_old[start] = mngr->arena[start];
		st->color_old[start] = idx + 1;
		show_pos_in_arena(mngr, start, idx + 1);
		start += 1;
	}
	wrefresh(get_win(WIN_MAIN));
	curs_set(0);
	show_side_panel_init(mngr, idx);
	getchar();
}
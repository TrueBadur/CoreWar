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

void	game_panel_reshow()
{
	WINDOW	*win;

	game_panel_border();
	win = get_win(WIN_G_PLY);
	wprintw(win, "\t\tFor continue : PRESS ANY KEY");
	wrefresh(win);
}

void	reshow_area(t_mngr *mngr)
{
	t_stats	*st;
	WINDOW	*win;
	int		idx;

	st = get_stats();
	if (st->game_mod == G_MOD_NO_PAUSE)
		return ;
	clear_time_to_die_screen();
	win = get_win(WIN_MAIN_BORDER);
	wborder(win, '#', '#', '#', '#', '#', '#', '#', '#');
	wrefresh(win);
	win = get_win(WIN_MAIN);
	idx = -1;
	while (++idx < MEM_SIZE)
		show_pos_in_arena(mngr, idx, st->color_old[idx]);
	wrefresh(win);
	show_side_cntr(mngr);
	game_panel_reshow();
	pause_or_wait_reshow(st);
}
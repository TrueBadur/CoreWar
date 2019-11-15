/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_phase_14_reshow.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 18:38:24 by wgorold           #+#    #+#             */
/*   Updated: 2019/11/14 13:42:47 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

void	game_panel_reshow(void)
{
	t_nwin	win;

	game_panel_border();
	win.w = get_win(WIN_G_PLY);
	wprintw(win.w, "\t\tFor continue : PRESS ANY KEY");
	wrefresh(win.w);
}

void	reshow_area(t_mngr *mngr)
{
	t_stats	*st;
	t_nwin	win;
	int		idx;

	st = get_stats();
	st->phase_game = G_PHASE_RESHOW;
	if (st->game_mod == G_MOD_NO_PAUSE)
		return ;
	clear_time_to_die_screen();
	win.w = get_win(WIN_MAIN_BORDER);
	wborder(win.w, '#', '#', '#', '#', '#', '#', '#', '#');
	wrefresh(win.w);
	win.w = get_win(WIN_MAIN);
	idx = -1;
	while (++idx < MEM_SIZE)
		show_pos_in_arena(mngr, idx, st->color_old[idx]);
	wrefresh(win.w);
	show_side_cntr();
	game_panel_reshow();
	pause_or_wait_reshow(st);
}

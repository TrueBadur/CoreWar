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

#include "visu.h"

void	show_time_to_die(t_mngr *mngr)
{
	t_stats *st;
	t_nwin	win;

	if (!(mngr->flags & FLAG_S))
		return ;
	st = get_stats();
	st->last_death_wave_cycle = mngr->cycle;
	if (st->game_mod == G_MOD_NO_PAUSE)
		return ;
	clear_mem_trig_screen();
	st->phase_game = G_PHASE_TTD;
	win.w = get_win(WIN_D_IMG);
	show_skull_one(win.w);
	wrefresh(win.w);
	win.w = get_win(WIN_D_BAN);
	show_time_banner(win.w);
	wrefresh(win.w);
	win.w = get_win(WIN_D_STA);
	show_champ_stats(mngr, win.w);
	wrefresh(win.w);
	getchar();
}

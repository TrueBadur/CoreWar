/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_side_panel.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 18:38:24 by wgorold           #+#    #+#             */
/*   Updated: 2019/11/14 13:42:49 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

void	control_panel(void)
{
	t_nwin	win;

	win.w = get_win(WIN_CNTR);
	wprintw(win.w, "    >>>> PRESS ANY KEY <<<<");
	wrefresh(win.w);
}

void	show_side_panel_init(t_mngr *mngr, int idx_champ)
{
	t_nwin	win;
	int		id_champ_to_show;

	win.w = get_win(WIN_PLY);
	if (idx_champ == -1)
	{
		control_panel();
		wprintw(win.w, "   >>>> PRESS ANY KEY <<<<\n");
		wprintw(win.w, "   and next champ will enter to the game");
	}
	else
	{
		werase(win.w);
		id_champ_to_show = -(mngr->chmps[idx_champ]->id) - 1;
		wprintw(win.w, "Player %d : \n\n\t", id_champ_to_show);
		wattron(win.w, COLOR_PAIR(idx_champ + COL_PLY_SHIFT));
		wprintw(win.w, "%s\n\n", mngr->chmps[idx_champ]->name);
		wattron(win.w, COLOR_PAIR(DEF));
		wprintw(win.w, "Comment   : \n\n\t");
		wattron(win.w, COLOR_PAIR(idx_champ + COL_PLY_SHIFT));
		wprintw(win.w, "%s\n", mngr->chmps[idx_champ]->moto);
		wattron(win.w, COLOR_PAIR(DEF));
	}
	wrefresh(win.w);
}

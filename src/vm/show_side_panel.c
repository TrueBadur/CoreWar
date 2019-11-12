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

void	control_panel()
{
	WINDOW *win;

	win = get_win(WIN_CNTR);
	wprintw(win, "    >>>> PRESS ANY KEY <<<<");
	wrefresh(win);
}

void	show_side_panel_init(t_mngr *mngr, int idx_champ)
{
	WINDOW	*win;
	int		id_champ_to_show;

	win = get_win(WIN_PLY);
	if (idx_champ == -1)
	{
		control_panel();
		wprintw(win, "   >>>> PRESS ANY KEY <<<<\n");
		wprintw(win, "   and next champ will enter to the game");
	}
	else
	{
		werase(win);
		id_champ_to_show = -(mngr->chmps[idx_champ]->id) - 1;
		wprintw(win, "Player %d : \n\n\t", id_champ_to_show);
		wattron(win, COLOR_PAIR(idx_champ + 1));
		wprintw(win, "%s\n\n", mngr->chmps[idx_champ]->name);
		wattron(win, COLOR_PAIR(DEF));
		wprintw(win, "Comment   : \n\n\t");
		wattron(win, COLOR_PAIR(idx_champ + 1));
		wprintw(win, "%s\n", mngr->chmps[idx_champ]->moto);
		wattron(win, COLOR_PAIR(DEF));
	}
	wrefresh(win);
}
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

void	show_pos_in_arena(t_mngr *mngr, int pos, int id_ply)
{
	WINDOW	*win;
	int		col;
	int		lin;

	win = get_win(WIN_MAIN);
    wattron(win, COLOR_PAIR(id_ply));
	lin = pos / COL_IN_LIN;
	col = (pos % COL_IN_LIN) * 3;
	wmove(win, lin, col);
	wprintw(win, "%02x", mngr->arena[pos]);
	wattron(win, COLOR_PAIR(DEF));
}

void	update_mem(t_mngr *mngr, int id_ply)
{
	t_stats *st;
	int		idx;

	st = get_stats();
	idx = -1;
	while (++idx < MEM_SIZE)
	{
		if (mngr->arena[idx] == st->arena[idx])
			continue;
		st->arena[idx] = mngr->arena[idx];
		st->color[idx] = (id_ply > -4 && id_ply < 0) ? id_ply : -5;
	}
}

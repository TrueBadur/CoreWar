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

void	side_board(int lin)
{
	move (lin, 0);
	printw("#");
	move (lin, COL_IN_LIN * 3 + COL_STEP * 2 - 2);
	printw("#");
}

void 	top_bot_board(int lin)
{
	int i;

	move(lin, 0);
	printw("#");
	i = 0;
	while (++i < COL_IN_LIN * 3 + COL_STEP * 2 - 2)
		printw("#");
	printw("#");
}

void	show_board()
{
	int i;
	int lin;

	top_bot_board(0);
	lin = 1;
	i = -1;
	while (++i < LIN_STEP - 1)
		side_board(lin++);
	i = -1;
	while ((++i * COL_IN_LIN) < MEM_SIZE)
		side_board(lin++);
	i = -1;
	while (++i < LIN_STEP - 1)
		side_board(lin++);
	top_bot_board(lin);
}

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

void    show_area(t_mngr *mngr)
{
    t_stats *st;
    int		idx;
    int		happend;
    int 	cmd;

    st = get_stats();
	rate_control(st);
    happend = 0;
    idx = -1;
	show_scnd_panel(mngr);
    while (++idx < MEM_SIZE)
    {
        if (st->arena_old[idx] == st->arena[idx] && st->color_old[idx] / 10 == 0)
        	continue;
		if (st->arena_old[idx] == st->arena[idx] && st->color_old[idx] / 10)
        {
        	st->color_old[idx] -= 10;
            show_pos_in_arena(mngr, idx, st->color_old[idx]);
            continue;
        }
        st->arena_old[idx] = st->arena[idx];
        st->color_old[idx] = -st->color[idx] + 10;
        st->color[idx] = -st->color[idx];
        show_pos_in_arena(mngr, idx, st->color_old[idx]);
		happend = 1;
    }
    if (happend)
    {
		curs_set(0);
		refresh();
		pause_or_wait(st, G_PHASE_MEM_CHANGE);
	}
}

void	reshow_area(t_mngr *mngr)
{
	t_stats *st;
	int	idx;

	erase();
	attron(COLOR_PAIR(DEF));
	show_board();
	st = get_stats();
	idx = -1;
	while (++idx < MEM_SIZE)
		show_pos_in_arena(mngr, idx, st->color_old[idx]);
	show_scnd_panel(mngr);
	refresh();
	getchar();
}
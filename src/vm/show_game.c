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

#define COL_STEP 3
#define LIN_STEP 2
#define	COL_IN_LIN 64

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

void	show_game_init(t_mngr *mngr)
{

	int i;
	int j;
	int lin;

	lin = LIN_STEP - 1;
	i = -1;
	show_board();
	while ((++i * COL_IN_LIN) < MEM_SIZE)
	{
		move(++lin, COL_STEP);
		j = -1;
		while(++j < COL_IN_LIN - 1)
			printw("%02x ", mngr->arena[j + COL_IN_LIN * i]);
		printw("%02x", mngr->arena[j + COL_IN_LIN * i]);
	}
	refresh();
	getchar();
}

void	show_pos_in_arena(t_mngr *mngr, int pos)
{
	int col;
	int lin;

	//move(0, 0);
	//printw("pos=%d", pos);
	lin = pos / COL_IN_LIN + LIN_STEP;
	col = (pos % COL_IN_LIN) * 3 + COL_STEP;
	move(lin, col);
	printw("%02x", mngr->arena[pos]);
}

void	refresh_mem(t_mngr *mngr, int start, int size, int color)
{
	size += start;
	attron_ply_clr(color);
	while (start < size)
	{
		show_pos_in_arena(mngr, start);
		start += 1;
	}
	curs_set(0);
	refresh();
	getchar();
}
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
#define	SHIFT_SCD_PANEL 10

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

void	show_pos_in_arena(t_mngr *mngr, int pos, int id_ply)
{
	int col;
	int lin;

    attron(COLOR_PAIR(id_ply));
	lin = pos / COL_IN_LIN + LIN_STEP;
	col = (pos % COL_IN_LIN) * 3 + COL_STEP;
	move(lin, col);
	printw("%02x", mngr->arena[pos]);
	attron(COLOR_PAIR(DEF));
}

void	show_champ_mem_init(t_mngr *mngr, int start, int size, int idx)
{
    t_stats *st;

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
	curs_set(0);
	refresh();
	getchar();
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

void	show_scnd_panel(t_mngr *mngr)
{
	t_stats *st;
	int lin;
	int col;

	st = get_stats();
	lin = LIN_STEP;
	col = COL_IN_LIN * 3 + COL_STEP * 2 + SHIFT_SCD_PANEL;
	move(lin++, col);
	printw("rate  =%d", st->rate);
	move(lin++, col);
	move(lin++, col);
	printw("cycle =%d", mngr->cycle);
	move(lin++, col);
	printw("cars  =%d", mngr->num_cars);
}

void	rate_control(t_stats *st)
{
	int 	cmd;

	cbreak();
	nodelay(stdscr, TRUE);
	cmd = getch();
	if (cmd == 'p')
		st->rate -= 1000;
	else if (cmd == 'o')
		st->rate += 1000;
	if (st->rate < 0)
		st->rate = 1;
	nodelay(stdscr, FALSE);
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
		usleep(st->rate);
		//getchar();
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
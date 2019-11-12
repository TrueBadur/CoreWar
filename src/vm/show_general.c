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

void	init_visu()
{
	initscr();
	keypad(stdscr, TRUE);
	noecho();

	start_color();
	init_pair(P1, COLOR_CYAN, COLOR_BLACK);
	init_pair(P2, COLOR_GREEN, COLOR_BLACK);
	init_pair(P3, COLOR_MAGENTA, COLOR_BLACK);
	init_pair(P4, COLOR_YELLOW, COLOR_BLACK);
	//init_pair(PU, COLOR_BLUE, COLOR_BLACK);
	init_pair(PU, COLOR_RED, COLOR_BLACK);
	init_pair(DEF, COLOR_WHITE, COLOR_BLACK);
	init_pair(BLOOD, COLOR_RED, COLOR_BLACK);
	init_pair(BRUTAL, COLOR_BLACK, COLOR_RED);
	init_pair(RIP, COLOR_WHITE, COLOR_BLACK);
	init_pair(DOOM, COLOR_BLACK, COLOR_WHITE);

    init_pair(P1H, COLOR_BLACK, COLOR_CYAN);
    init_pair(P2H, COLOR_BLACK, COLOR_GREEN);
    init_pair(P3H, COLOR_BLACK, COLOR_MAGENTA);
    init_pair(P4H, COLOR_BLACK, COLOR_YELLOW);
    init_pair(PUH, COLOR_BLACK, COLOR_RED);
	refresh();
}

void	attron_ply_clr(int i)
{
	attron(COLOR_PAIR(i + 1));
}

void	clear_window(int id_win)
{
	WINDOW	*win;

	win = get_win(id_win);
	werase(win);
	wrefresh(win);
}

void	clear_init_screen()
{
	clear_window(WIN_CNTR_BORDER);
	clear_window(WIN_CNTR);
	clear_window(WIN_PLY_BORDER);
	clear_window(WIN_PLY);
}

void	clear_mem_trig_screen()
{
	clear_window(WIN_MAIN_BORDER);
	clear_window(WIN_MAIN);
	clear_window(WIN_G_CNTR_BORDER);
	clear_window(WIN_G_CNTR);
	clear_window(WIN_G_PLY_BORDER);
	clear_window(WIN_G_PLY);
}

void	clear_time_to_die_screen()
{
	clear_window(WIN_D_IMG);
	clear_window(WIN_D_BAN);
	clear_window(WIN_D_STA);
}

void	clear_time_end_screen()
{
	clear_window(WIN_END_MAIN);
	clear_window(WIN_END_LEFT);
	clear_window(WIN_END_RIGHT);
}
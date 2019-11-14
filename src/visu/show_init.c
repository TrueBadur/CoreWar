/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 18:38:24 by wgorold           #+#    #+#             */
/*   Updated: 2019/11/14 13:42:43 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	init_visu(void)
{
	initscr();
	keypad(stdscr, TRUE);
	noecho();
	start_color();
	init_pair(P1, COLOR_CYAN, COLOR_BLACK);
	init_pair(P2, COLOR_GREEN, COLOR_BLACK);
	init_pair(P3, COLOR_MAGENTA, COLOR_BLACK);
	init_pair(P4, COLOR_YELLOW, COLOR_BLACK);
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

void	start_visu(t_mngr *mngr)
{
	if (!(mngr->flags & FLAG_S))
		return ;
	signal(SIGWINCH, resize_handler);
	init_visu();
	set_right_size();
}

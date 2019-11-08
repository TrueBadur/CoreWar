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

    init_pair(P1H, COLOR_WHITE, COLOR_CYAN);
    init_pair(P2H, COLOR_WHITE, COLOR_GREEN);
    init_pair(P3H, COLOR_WHITE, COLOR_MAGENTA);
    init_pair(P4H, COLOR_WHITE, COLOR_YELLOW);
    init_pair(PUH, COLOR_WHITE, COLOR_RED);


	border(0, 0, 0, 0, 0, 0, 0, 0);
	refresh();
}

void	attron_ply_clr(int i)
{
	attron(COLOR_PAIR(i + 1));
}
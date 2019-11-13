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

int		checkSize()
{
	int		nh;
	int		nw;

	getmaxyx(stdscr, nh, nw);
	erase();
	if (nh < WIN_SIZE_LIN || nw < WIN_SIZE_COL)
	{
		border(0, 1, 0, 1, 1, 1, 1, 1);
		move(0, 2);
		printw("col = %d", nw);
		move(4, 0);
		printw("lin = %d", nh);
		move(2, 2);
		printw("Place size window. col > %d and lin > %d",
				WIN_SIZE_COL, WIN_SIZE_LIN);
		refresh();
		return (1);
	}
	else
	{
		move(2, 2);
		printw(">>>> PRESS ANY KEY <<<<");
		refresh();
	}
	return (0);
}

void	set_right_size()
{
	while (checkSize())
		getchar();
}

void	resizeHandler(int sig)
{
	endwin();
	initscr();
	checkSize();
}
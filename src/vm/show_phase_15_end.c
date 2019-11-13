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

void	win_banner(WINDOW *win)
{
	wprintw(win, " __      __                                                       \n"
				 "/\\ \\  __/\\ \\  __                                     __           \n"
				 "\\ \\ \\/\\ \\ \\ \\/\\_\\    ___     ___      __   _ __     /\\_\\    ____  \n"
				 " \\ \\ \\ \\ \\ \\ \\/\\ \\ /' _ `\\ /' _ `\\  /'__`\\/\\`'__\\   \\/\\ \\  /',__\\ \n"
				 "  \\ \\ \\_/ \\_\\ \\ \\ \\/\\ \\/\\ \\/\\ \\/\\ \\/\\  __/\\ \\ \\/     \\ \\ \\/\\__, `\\\n"
				 "   \\ `\\___x___/\\ \\_\\ \\_\\ \\_\\ \\_\\ \\_\\ \\____\\\\ \\_\\      \\ \\_\\/\\____/\n"
				 "    '\\/__//__/  \\/_/\\/_/\\/_/\\/_/\\/_/\\/____/ \\/_/       \\/_/\\/___/ \n"
				 "                                                                  \n");
}

void	show_banner_winner()
{
	WINDOW *win;

	clear_mem_trig_screen();
	clear_time_to_die_screen();
	win = get_win(WIN_END_LEFT);
	//wborder(win, '#', '#', '#', '#', '#', '#', '#', '#');
	show_nuke(win);
	wrefresh(win);
	win = get_win(WIN_END_RIGHT);
	//wborder(win, '#', '#', '#', '#', '#', '#', '#', '#');
	show_nuke(win);
	wrefresh(win);
	win = get_win(WIN_END_MAIN);
	//wborder(win, '#', '#', '#', '#', '#', '#', '#', '#');
	win_banner(win);
}

void	show_winner(t_mngr *mngr)
{
	WINDOW	*win;
	t_stats	*st;
	int 	len;
	char	*name;

	if (!(mngr->flags & FLAG_S))
		return ;
	st = get_stats();
	st->phase_game = G_PHASE_END;
	show_banner_winner();
	name = mngr->chmps[mngr->winner]->name;
	len = (70 - (int)ft_strlen(name)) / 2;
	if(len < 0)
		len = 70;
	else
		len += (int)ft_strlen(name);
	win = get_win(WIN_END_MAIN);
	wattron(win, COLOR_PAIR(mngr->winner + 1));
	wprintw(win, "\n\n%*.70s\n", len, mngr->chmps[mngr->winner]->name);
	wrefresh(win);
	getchar();
	clear_time_end_screen();
}
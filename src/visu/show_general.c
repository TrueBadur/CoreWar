/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_general.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 18:38:24 by wgorold           #+#    #+#             */
/*   Updated: 2019/11/14 13:42:43 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

void	clear_window(int id_win)
{
	t_nwin	win;

	win.w = get_win(id_win);
	werase(win.w);
	wrefresh(win.w);
}

void	clear_init_screen(void)
{
	clear_window(WIN_CNTR_BORDER);
	clear_window(WIN_CNTR);
	clear_window(WIN_PLY_BORDER);
	clear_window(WIN_PLY);
}

void	clear_mem_trig_screen(void)
{
	clear_window(WIN_MAIN_BORDER);
	clear_window(WIN_MAIN);
	clear_window(WIN_G_CNTR_BORDER);
	clear_window(WIN_G_CNTR);
	clear_window(WIN_G_PLY_BORDER);
	clear_window(WIN_G_PLY);
}

void	clear_time_to_die_screen(void)
{
	clear_window(WIN_D_IMG);
	clear_window(WIN_D_BAN);
	clear_window(WIN_D_STA);
}

void	clean_all_win(void)
{
	t_nwin_tab	all_wins;
	t_nwin		win;
	int			idx;

	all_wins.ws = get_windows();
	idx = -1;
	while ((win.w = all_wins.ws[++idx]))
	{
		werase(win.w);
		wrefresh(win.w);
	}
	endwin();
}

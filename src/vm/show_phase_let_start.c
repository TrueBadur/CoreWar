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

void	update_side_cntr(mngr)
{
	WINDOW *win;
	t_stats *st;

	st = get_stats();
	win = get_win(WIN_G_CNTR);
	werase(win);
	//wborder(win, '+', '+', '+', '+', '+', '+', '+', '+');
	if (st->game_mod == G_MOD_PAUSE_ALL)
		wprintw(win, "\t[x] [ ] [ ] ");
	else if (st->game_mod == G_MOD_PAUSE_SELECT)
		wprintw(win, "\t[ ] [x] [ ] ");
	else if (st->game_mod == G_MOD_NO_PAUSE)
		wprintw(win, "\t[ ] [ ] [x] ");
	wprintw(win, " ms=%d\n\n", st->rate / 1000);
	/*
	wprintw(win, "  keys:  q   w   e   r   f\n\n");
	wprintw(win, "         |   |   |   |   |\n");
	wprintw(win, "         |   |   |   |   pause time (-)\n");
	wprintw(win, "         |   |   |   pause time (+)\n");
	wprintw(win, "         |   |   mode: no pause\n");
	wprintw(win, "         |   mode: die pause\n");
	wprintw(win, "         mode: all pause\n");
	 */
	wprintw(win, "  keys:  q   w   e   r   f\n\n");
	wprintw(win, "         |   |   |   |   |\n");
	wprintw(win, "         |   |   |   |   +- pause time (-)\n");
	wprintw(win, "         |   |   |   +----- pause time (+)\n");
	wprintw(win, "         |   |   +--------- mode: no pause\n");
	wprintw(win, "         |   +------------- mode: die pause\n");
	wprintw(win, "         +----------------- mode: all pause\n");
	wrefresh(win);
}

void	show_side_cntr(mngr)
{
	WINDOW *win;

	win = get_win(WIN_G_CNTR_BORDER);
	wborder(win, '#', '#', '#', '#', '#', '#', '#', '#');
	wrefresh(win);
	update_side_cntr(mngr);
}

void	erase_init_side_panel(mngr)
{
	WINDOW *win;

	win = get_win(WIN_CNTR_BORDER);
	werase(win);
	wrefresh(win);
	win = get_win(WIN_CNTR);
	werase(win);
	wrefresh(win);
	win = get_win(WIN_PLY_BORDER);
	werase(win);
	wrefresh(win);
	win = get_win(WIN_PLY);
	werase(win);
	wrefresh(win);
}

void	show_let_start(WINDOW	*win)
{
	/*
	wprintw(win, "\t        /                             \n"
			 "\t /  _ _/   _   __/_ __/  _     _ _    \n"
			 "\t(__(- /  _)  _) /(// /  (/ ((/(//     \n"
			 "\t                                      \n"
			 "\t  __                                  \n"
			 "\t ( _/_ __/  _      _ /_ _ _     _ _ | \n"
			 "\t__)/(// /  (/ /)(/( ((-(//  ((/(//  . \n"
			 "\t                                      \n");
	*/
	wprintw(win, "  _          _   _             _             _    \n"
				 " | |        | | ( )           | |           | |   \n"
				 " | |     ___| |_|/ ___     ___| |_ __ _ _ __| |_  \n"
				 " | |    / _ \\ __| / __|   / __| __/ _` | '__| __| \n"
				 " | |___|  __/ |_  \\__ \\   \\__ \\ || (_| | |  | |_  \n"
				 " |______\\___|\\__| |___/   |___/\\__\\__,_|_|   \\__| \n");
	wprintw(win, "\t\t   __ _  __      ____ _ _ __ \n"
				 "\t\t  / _` | \\ \\ /\\ / / _` | '__|\n"
				 "\t\t | (_| |  \\ V  V / (_| | |   \n"
				 "\t\t  \\__,_|   \\_/\\_/ \\__,_|_|   \n"
				 "\t\t                             \n");
	wprintw(win, "   _____ _             _   \n"
				 "  / ____| |           | |  \n"
				 " | (___ | |_ __ _ _ __| |_ \n"
				 "  \\___ \\| __/ _` | '__| __|\n"
				 "  ____) | || (_| | |  | |_ \n"
				 " |_____/ \\__\\__,_|_|   \\__|                       _ \n");
	wprintw(win, "                                                 | |\n"
				 "   __ _    ___ ___  _ __ _____      ____ _ _ __  | |\n"
				 "  / _` |  / __/ _ \\| '__/ _ \\ \\ /\\ / / _` | '__| | |\n"
				 " | (_| | | (_| (_) | | |  __/\\ V  V / (_| | |    |_|\n"
				 "  \\__,_|  \\___\\___/|_|  \\___| \\_/\\_/ \\__,_|_|    (_)\n");
}

void	show_champ_let_start(mngr)
{
	WINDOW	*win;
	int		from_user;

	erase_init_side_panel(mngr);
	show_side_cntr(mngr);
	win = get_win(WIN_G_PLY_BORDER);
	wborder(win, '#', '#', '#', '#', '#', '#', '#', '#');
	wrefresh(win);
	win = get_win(WIN_G_PLY);
	wattron(win, COLOR_PAIR(BLOOD));
	show_let_start(win);
	wattron(win, COLOR_PAIR(DEF));
	wprintw(win, "\n\n\t  For start a war : PRESS ANY KEY\n");
	wrefresh(win);
	from_user = getchar();
	while (g_set_param(from_user))
	{
		update_side_cntr(mngr);
		from_user = getchar();
	}
}
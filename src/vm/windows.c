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

WINDOW	**get_windows()
{
	static WINDOW *wins[6];
	static int is_set;

	if (is_set == 0)
	{
		int lin;
		int col;
		int spac;

		lin = 20;
		col = 40;
		spac = 10;
		wins[0] = newwin(lin, col, spac, spac);
		wins[1] = newwin(lin, col, spac, col + spac);
		wins[2] = newwin(lin, col, lin + spac, spac);
		wins[3] = newwin(lin, col, lin + spac, col + spac);
		wins[4] = newwin(lin, col, 2 * lin + spac, spac);
		wins[5] = newwin(lin, col, 2 * lin + spac, col + spac);
		wattron(wins[0], COLOR_PAIR(1));
		wattron(wins[1], COLOR_PAIR(2));
		wattron(wins[2], COLOR_PAIR(3));
		wattron(wins[3], COLOR_PAIR(4));
		wattron(wins[4], COLOR_PAIR(5));
		wattron(wins[5], COLOR_PAIR(6));
		is_set = 1;
	}

	return wins;
}

WINDOW	*get_win(int id)
{
	WINDOW	**tmp;

	tmp = get_windows();
	return tmp[id];
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_windows.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 18:38:24 by wgorold           #+#    #+#             */
/*   Updated: 2019/11/14 13:42:54 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

WINDOW	**get_windows(void)
{
	static WINDOW	*wins[17];
	static int		is_set;

	if (is_set == 0)
	{
		wins[0] = newwin(68, 197, 0, 0);
		wins[1] = newwin(64, 191, 2, 3);
		wins[2] = newwin(5, 64, 0, 197);
		wins[3] = newwin(1, 64 - 9, 2, 197 + 8);
		wins[4] = newwin(63, 64, 5, 197);
		wins[5] = newwin(63 - 4, 64 - 4, 5 + 2, 197 + 2);
		wins[6] = newwin(14, 64, 0, 197);
		wins[7] = newwin(14 - 4, 64 - 4, 2, 197 + 2);
		wins[8] = newwin(54, 64, 14, 197);
		wins[9] = newwin(54 - 4, 64 - 4, 14 + 2, 197 + 2);
		wins[10] = newwin(50, 100, 8, 15);
		wins[11] = newwin(10, 140, 4, 115);
		wins[12] = newwin(50, 140, 18, 115);
		wins[13] = newwin(80, 70, 10, 80);
		wins[14] = newwin(80, 140, 0, 0);
		wins[15] = newwin(80, 140, 0, 160);
		wins[16] = NULL;
		is_set = 1;
	}
	return (wins);
}

WINDOW	*get_win(int id)
{
	WINDOW	**tmp;

	tmp = get_windows();
	return (tmp[id]);
}

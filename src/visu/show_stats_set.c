/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_stats.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 18:38:24 by wgorold           #+#    #+#             */
/*   Updated: 2019/11/14 13:42:58 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	set_cycles_die(t_mngr *mngr)
{
	t_stats *st;

	st = get_stats();
	st->cycles_to_die = mngr->cycles_delta;
}

void	set_cycles_die_new(t_mngr *mngr)
{
	t_stats *st;

	if (!(mngr->flags & FLAG_S))
		return ;
	st = get_stats();
	st->cycles_to_die_new = mngr->cycles_to_die;
}

void	set_cycle(t_mngr *mngr)
{
	t_stats *st;

	if (!(mngr->flags & FLAG_S))
		return ;
	st = get_stats();
	st->cycle = mngr->cycle;
}

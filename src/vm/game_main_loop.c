/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_main_loop.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehugh-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 16:26:51 by ehugh-be          #+#    #+#             */
/*   Updated: 2019/10/15 17:03:54 by ehugh-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	check_cars(t_mngr *mngr)
{

}

void	dump_arena(t_mngr *mngr)
{

}

void	game_main(t_mngr *mngr)
{
	while (mngr->num_cars)
	{
		if (mngr->cycle >= mngr->cycles_to_die || mngr->cycles_to_die <= 0)
			check_cars(mngr);
		make_one_turn(mngr);
		if (mngr->flags & DUMP)
			dump_arena(mngr);
		mngr->cycle++;
	}
}
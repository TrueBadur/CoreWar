/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_main_loop.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blomo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 16:26:51 by ehugh-be          #+#    #+#             */
/*   Updated: 2019/11/14 18:00:23 by blomo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "visu.h"

void			game_main(t_mngr *mngr)
{
	while (mngr->num_cars)
	{
		if (mngr->flags & FLAG_DUMP && mngr->cycle - 1 == mngr->dump_nbr)
			dump_arena(mngr);
		if (mngr->flags & FLAG_V)
			ft_printf("It is now cycle %d\n", mngr->cycle);
		make_one_turn(mngr);
		show_area(mngr);
		if (mngr->cycle >= mngr->cycles_to_die || mngr->cycles_delta <= 0)
			check_cars(mngr);
		mngr->cycle++;
	}
}

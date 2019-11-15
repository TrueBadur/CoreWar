/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dump_arena.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blomo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 17:58:27 by blomo             #+#    #+#             */
/*   Updated: 2019/11/14 17:59:38 by blomo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void			dump_arena(t_mngr *mngr)
{
	int			i;
	int			j;

	i = -1;
	while (++i < 64)
	{
		if (i == 0)
			ft_printf("0x0000 : ");
		else
			ft_printf("%#.4x : ", i * 64);
		j = -1;
		while (++j < 64)
		{
			if (mngr->arena[j + 64 * i] <= 9 && mngr->arena[j + 64 * i] > 0)
				ft_printf("0%x ", mngr->arena[j + 64 * i]);
			else if (mngr->arena[j + 64 * i] == 0)
				ft_printf("0%x ", mngr->arena[j + 64 * i]);
			else if (mngr->arena[j + 64 * i] < 16)
				ft_printf("0%x ", mngr->arena[j + 64 * i]);
			else
				ft_printf("%x ", mngr->arena[j + 64 * i]);
		}
		ft_printf("\n");
	}
	safe_exit(mngr, CALL_DUMP, NULL);
}

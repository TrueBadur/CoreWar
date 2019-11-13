/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_flag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blomo <blomo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 15:05:59 by blomo             #+#    #+#             */
/*   Updated: 2019/11/13 19:13:10 by blomo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "checkop.h"
#include <limits.h>

void		print_addr(t_mngr *mngr, int pos, int adv)
{
	int		i;

	i = -1;
	if (!pos)
		ft_printf("ADV %d (0x%#.4x -> %#.4x) ", adv, pos,
		(pos + adv) % MEM_SIZE);
	else
		ft_printf("ADV %d (%#.4x -> %#.4x) ", adv, pos, (pos + adv) % MEM_SIZE);
	while (++i < adv)
	{
		if (mngr->arena[(pos + i) % MEM_SIZE] < 16)
			ft_printf("0%x ", mngr->arena[(pos + i) % MEM_SIZE]);
		else
			ft_printf("%x ", mngr->arena[(pos + i) % MEM_SIZE]);
	}
	ft_printf("\n");
}

void		print_live(t_mngr *mngr, t_car *car, int say, int arg)
{
	int		mod_arg;

	mod_arg = ft_abs(arg) - 1;
	ft_printf("P %4d | live %d\n", car->id + 1, arg);
	if (say)
		ft_printf("Player %d (%s) is said to be alive\n", mod_arg + 1,
		mngr->chmps[mod_arg]->name);
}

void		print_st(t_car *car, int reg1, int reg2, t_t_op *op)
{
	if (op->a2 == REG_CODE)
		ft_printf("P %4d | %s r%d %d\n", car->id + 1, "st", reg1 + 1, reg2 + 1);
	else
		ft_printf("P %4d | %s r%d %d\n", car->id + 1, "st", reg1 + 1, reg2);
}

void		print_sti(t_car *car, int arg1, int arg2, int arg3)
{
	ft_printf("P %4d | %s r%d %d %d\n", car->id + 1, "sti", arg1 + 1, arg2,
	arg3);
	ft_printf("       | -> store to %d + %d = %d (with pc and mod %d)\n", arg2,
	arg3, arg2 + arg3, ((arg2 + arg3) % IDX_MOD + car->pos) % MEM_SIZE);
}

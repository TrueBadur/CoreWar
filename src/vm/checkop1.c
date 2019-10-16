/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkop1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehugh-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 13:53:59 by ehugh-be          #+#    #+#             */
/*   Updated: 2019/10/16 14:52:01 by ehugh-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "checkop.h"

int		is_live(t_op op, short *ret)
{
	if (op.op == OP_live && ARG1(op.a_code) == DIR_CODE)
	{
		make_live();
		*ret = OP_SIZE + OP_CODE_SIZE + DIR_SIZE;
		return (1);
	}
	else
		return (0);
}
int		is_ld(t_op op, short *ret)
{

}
int		is_st(t_op op, short *ret)
{}
int		is_add_sub(t_op op, short *ret)
{}
int		is_and_or_xor(t_op op, short *ret)
{}
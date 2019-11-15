/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_op_func.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehugh-be <ehugh-be@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 23:40:44 by ehugh-be          #+#    #+#             */
/*   Updated: 2019/11/13 16:56:51 by blomo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "checkop.h"

t_fptr	get_op_func(int id)
{
	static t_fptr op_handlers[17] = {
		make_live,
		make_ld_lld,
		make_st,
		make_add_sub,
		make_add_sub,
		make_and_or_xor,
		make_and_or_xor,
		make_and_or_xor,
		make_zjmp,
		make_ldi_lldi,
		make_sti,
		make_fork_lfork,
		make_ld_lld,
		make_ldi_lldi,
		make_fork_lfork,
		make_aff
	};

	return (op_handlers[id - 1]);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_op_func.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehugh-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 23:40:44 by ehugh-be          #+#    #+#             */
/*   Updated: 2019/10/16 23:41:30 by ehugh-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "checkop.h"



fptr	get_op_func(int id)
{
	static fptr op_handlers[17] = {
			_live,
			_ld,
			_st,
			_add,
			_sub,
			_and,
			_or,
			_xor,
			_zjmp,
			_ldi,
			_sti,
			_fork,
			_lld,
			_lldi,
			_lfork,
			_aff
	};

	return (op_handlers[id - 1]);
}

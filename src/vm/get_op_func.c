/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_op_func.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blomo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 23:40:44 by ehugh-be          #+#    #+#             */
/*   Updated: 2019/10/17 22:33:57 by blomo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "checkop.h"



fptr	get_op_func(int id)
{
	static fptr op_handlers[17] = {
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
            make_fork,
            make_ld_lld,
            make_ldi_lldi,
            make_lfork,
            make_aff
	};

	return (op_handlers[id - 1]);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_flag1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blomo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 20:29:36 by blomo             #+#    #+#             */
/*   Updated: 2019/11/14 20:38:07 by blomo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "checkop.h"

void	print_ldi_lldi(t_int3 *args, int id, int pos, t_t_op *op)
{
	ft_printf("P %4d | %s %d %d r%d\n", id + 1, op->op == OP_ldi ?
	"ldi" : "lldi", args->x, args->y, args->z + 1);
	if (op->op == OP_ldi)
		ft_printf("       | -> load from %d + %d = %d (with pc and mod %d)\n",
				args->x, args->y, args->x + args->y, (pos +
				(args->x + args->y) % IDX_MOD));
	else
		ft_printf("       | -> load from %d + %d = %d (with pc %d)\n", args->x,
				args->y, args->x + args->y, (pos + (args->x + args->y)));
}

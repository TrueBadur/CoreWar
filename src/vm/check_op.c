/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_op.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehugh-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 23:15:01 by ehugh-be          #+#    #+#             */
/*   Updated: 2019/10/22 15:43:57 by ehugh-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "checkop.h"

static short single_arg_check(t_op *tmp, t_t_op *op)
{
	char arg_type;

	arg_type = (char)(((tmp->prm_tp[0] & T_REG) == T_REG) * 1 +
					  ((tmp->prm_tp[0] & T_DIR) == T_DIR) * 2 +
					  ((tmp->prm_tp[0] & T_IND) == T_IND) * 3);
	*op = (t_t_op){op->op, arg_type, 0,0};
	if (arg_type == T_REG)
		return (OP_SIZE + 1);
	else if (arg_type == T_IND)
		return (OP_SIZE + IND_SIZE);
	else
		return ((short)(OP_SIZE + DIR_SIZE - tmp->t_dir_size * 2));
}

static short	check_params(t_t_op *c_op, t_op *smp, char *size)
{
	static char szs[3] = {1, 4, 2};

	*size = OP_BASE +
			(szs[c_op->a1 - 1] - smp->t_dir_size * 2 * (c_op->a1 == DIR_CODE)) +
			(szs[c_op->a2 - 1] - smp->t_dir_size * 2 * (c_op->a2 == DIR_CODE)) +
			(szs[c_op->a3 - 1] - smp->t_dir_size * 2 * (c_op->a3 == DIR_CODE));
	if (((1u << (unsigned)(c_op->a1 - 1)) & smp->prm_tp[0]) && (!smp->prm_tp[1]
	|| ((1u << (unsigned)(c_op->a2 - 1)) & smp->prm_tp[1])) && (!smp->prm_tp[2]
	|| ((1u << (unsigned)(c_op->a3 - 1)) & smp->prm_tp[2])))
		return (1);
	else
		return (0);
}

short	check_op(t_t_op *op)
{
	t_op *tmp;
	char ret;

	if (op->op >= OP_live && op->op <= OP_aff)
		tmp = get_op_info(op->op);
	else
		return (-1);
	if (tmp->is_param_b)
		return ((short)(check_params(op, tmp, &ret) ? ret : -ret));
	else
		return (single_arg_check(tmp, op));
}

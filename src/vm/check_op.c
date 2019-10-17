/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_op.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehugh-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 23:15:01 by ehugh-be          #+#    #+#             */
/*   Updated: 2019/10/16 23:15:30 by ehugh-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "checkop.h"

static short	single_arg_check(t_op *tmp)
{
	char arg_type;

	arg_type = (char)(((tmp->paramtypes[0] & T_REG) == T_REG) * 1 +
					  ((tmp->paramtypes[0] & T_DIR) == T_DIR) * 2 +
					  ((tmp->paramtypes[0] & T_IND) == T_IND) * 3);
	if (arg_type == T_REG)
		return (OP_SIZE + 1);
	else if (arg_type == T_IND)
		return (OP_SIZE + IND_SIZE);
	else
		return ((short)(OP_SIZE + DIR_SIZE - tmp->t_dir_size * 2));
}

static short	check_params(t_t_op *c_op, t_op *smpl, char *size)
{
	static char szs[3] = {1, 4, 2};

	*size = OP_BASE +
			(szs[c_op->a1] - smpl->t_dir_size * 2 * (c_op->a1 == DIR_CODE)) +
			(szs[c_op->a2] - smpl->t_dir_size * 2 * (c_op->a2 == DIR_CODE)) +
			(szs[c_op->a3] - smpl->t_dir_size * 2 * (c_op->a3 == DIR_CODE));
	if (((1u << c_op->a1) & smpl->paramtypes[0]) &&
		((1u << c_op->a2) & smpl->paramtypes[1]) &&
		((1u << c_op->a3) & smpl->paramtypes[2]))
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
		return (1);
	if (tmp->is_param_b)
		return ((short)(check_params(op, tmp, &ret) ? ret : -ret));
	else
		return (single_arg_check(tmp));
}

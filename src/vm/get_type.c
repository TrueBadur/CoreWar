/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_type.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blomo <blomo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 17:50:39 by blomo             #+#    #+#             */
/*   Updated: 2019/11/13 17:56:10 by blomo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "checkop.h"
#include <limits.h>

int					get_reg(t_mngr *mngr, int *step)
{
	int				reg;

	reg = mngr->arena[get_addr_arena(*step)] - 1;
	*step += 1;
	return (reg);
}

int					get_indir(t_mngr *mngr, t_car *car, int *step, int mod)
{
	int				reg;
	int				in_dir;
	int				pos_indir;

	in_dir = get_dir(mngr, step, IND_SIZE) % mod;
	pos_indir = car->pos + in_dir;
	reg = get_dir(mngr, &pos_indir, 4);
	return (reg);
}

int					get_indir_pos(t_mngr *mngr, t_car *car, int *step, int mod)
{
	int				in_dir;

	in_dir = get_dir(mngr, step, 2);
	return (in_dir);
}

int					get_args(t_mngr *mngr, t_car *car, t_t_op *op, t_int3 *arg)
{
	int				i;
	t_op			*op_inf;
	int				step;
	int				mod;
	char			flag;
	unsigned char	arg_type;

	i = -1;
	op_inf = get_op_info(op->op);
	if (op->op == OP_lld)
		mod = INT_MAX;
	else
		mod = IDX_MOD;
	step = car->pos + ((op_inf->is_param_b == 1) ? (int)OP_BASE : (int)OP_SIZE);
	while (++i < op_inf->params_num)
	{
		arg_type = ((unsigned char*)op)[i + 1];
		if (arg_type == REG_CODE)
		{
			flag = ((int*)arg)[i];
			if (!check_reg(((int *)arg)[i] = get_reg(mngr, &step)))
				return (0);
			if (!flag)
				((int*)arg)[i] = *(int*)car->regs[((int*)arg)[i]].reg;
		}
		else if (arg_type == IND_CODE)
		{
			if (op->op == OP_st)
				((int*)arg)[i] = get_indir_pos(mngr, car, &step, mod);
			else
				((int*)arg)[i] = get_indir(mngr, car, &step, mod);
		}
		else
			((int*)arg)[i] = get_dir(mngr, &step, DIR_SIZE - op_inf->t_dir_size * 2);
	}
	return (1);
}

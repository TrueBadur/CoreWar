/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_type.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blomo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 17:50:39 by blomo             #+#    #+#             */
/*   Updated: 2019/11/14 14:51:00 by blomo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "checkop.h"

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

void				get_args_init(t_int4 *r, t_op **op_inf, t_t_op *op)
{
	r->x = -1;
	*op_inf = get_op_info(op->op);
	r->z = (op->op == OP_lld) ? INT_MAX : IDX_MOD;
}

int					get_args(t_mngr *mngr, t_car *car, t_t_op *op, t_int3 *arg)
{
	t_int4			r;
	t_op			*op_inf;
	unsigned char	arg_type;

	get_args_init(&r, &op_inf, op);
	r.y = car->pos + ((op_inf->is_param_b == 1) ? (int)OP_BASE : (int)OP_SIZE);
	while (++r.x < op_inf->params_num)
	{
		arg_type = ((unsigned char*)op)[r.x + 1];
		if (arg_type == REG_CODE)
		{
			r.w = ((int*)arg)[r.x];
			if (!check_reg(((int *)arg)[r.x] = get_reg(mngr, &r.y)))
				return (0);
			if (!r.w)
				((int*)arg)[r.x] = *(int*)car->regs[((int*)arg)[r.x]].reg;
		}
		else if (arg_type == IND_CODE)
			((int*)arg)[r.x] = (op->op == OP_st) ? get_indir_pos(mngr, car,
					&r.y, r.z) : get_indir(mngr, car, &r.y, r.z);
		else
			((int*)arg)[r.x] = get_dir(mngr, &r.y,
					DIR_SIZE - op_inf->t_dir_size * 2);
	}
	return (1);
}

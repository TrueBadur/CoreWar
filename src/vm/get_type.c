/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_type.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blomo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 17:14:19 by blomo             #+#    #+#             */
/*   Updated: 2019/10/31 19:28:34 by blomo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "checkop.h"
#include <limits.h>

int get_dir(t_mngr *mngr, int *pos, int size)
{
    char buffer[size];
    int c;

    c = -1;
    while (++c < size)
        buffer[size - c - 1] = (char)mngr->arena[(*pos + c) % MEM_SIZE];
    *pos += size;
    return (size == 2 ? *(short*)buffer : *(int*)buffer);
}

inline char check_reg(int reg)
{
    return ((char)(reg >= 0 && reg <= 15 ? 1 : 0));
}

void copy_reg_to_arena(t_mngr *mngr, t_car *car, int reg1, int reg2)
{
	int c;

	c = -1;
	while (++c < REG_SIZE)
		mngr->arena[(reg2 + OP_BASE + ARG_REG_S - c + MEM_SIZE) % MEM_SIZE] =
				car->regs[reg1].reg[c];
}

int		get_reg(t_mngr *mngr, int *step)
{
	int reg;

	reg = mngr->arena[*step % MEM_SIZE] - 1;
	*step += 1;
	return (reg);
}

int get_indir(t_mngr *mngr, t_car *car, int *step, int mod)
{
	int reg;
	int in_dir;
	int pos_indir;

	in_dir = get_dir(mngr, step ,2) % mod;
	pos_indir = car->pos + in_dir;
	reg = get_dir(mngr, &pos_indir, 4);
	return(reg);
}

int get_indir_pos(t_mngr *mngr, t_car *car, int *step, int mod)
{
	int in_dir;

	in_dir = get_dir(mngr, step ,2) % mod;

	return(in_dir);
}

int  get_args(t_mngr *mngr, t_car *car, t_t_op *op, t_int3 *arg)
{
	int i;
	t_op *op_inf;
	int step;
	int mod;

	i = -1;
	op_inf = get_op_info(op->op);
	if(op->op == 13)
		mod = INT_MAX;
	else
		mod = IDX_MOD;
	step = car->pos + ((op_inf->is_param_b == 1) ? (int)OP_BASE : (int)OP_SIZE);
	while (++i < op_inf->params_num)
	{
		unsigned char arg_type = ((unsigned char *) op)[i + 1];
		if (arg_type == REG_CODE)
		{
			if (!check_reg(((int *) arg)[i] = get_reg(mngr, &step)))
				return (0);
			((int *) arg)[i] = *(int *) car->regs[((int *) arg)[i]].reg;
		}
		else if (arg_type == IND_CODE)
		{
			if(op->op == 3)
				((int *) arg)[i] = get_indir_pos(mngr, car, &step, mod);
			else
				((int *) arg)[i] = get_indir(mngr, car, &step, mod);
		}
		else
			((int *) arg)[i] = get_dir(mngr, &step, DIR_SIZE - op_inf->t_dir_size * 2);
	}
	return (1);
}
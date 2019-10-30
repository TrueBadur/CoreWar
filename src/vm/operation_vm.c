/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_vm.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blomo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 15:41:07 by blomo             #+#    #+#             */
/*   Updated: 2019/10/30 16:32:45 by blomo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "corewar.h"
#include "checkop.h"

void	make_live(t_mngr *mngr, t_car *car, t_t_op *op)
{
	int arg;
	int mod_arg;
	int i;

	i = 0;
	(void)op;
	arg = get_dir(mngr, car->pos + (int)OP_SIZE, DIR_SIZE);
	mod_arg = ft_abs(arg) - 1;
	if (arg < 0 && mod_arg < MAX_PLAYERS && mngr->chmps[mod_arg])
	{
		mngr->winner = mod_arg;
		i = 1;
	}
	car->live_cycle = mngr->cycle;
	mngr->live_num++;
	if (mngr->flags & FLAG_V)
		print_live(mngr, car, i, arg);
}

void	make_ld_lld(t_mngr *mngr, t_car *car, t_t_op *op)
{
	int dir;
	int reg;
	int indir;

	reg = mngr->arena[(car->pos + OP_BASE + IND_SIZE + (op->a1 == DIR_CODE) * 2)
				   % MEM_SIZE] - 1;
	indir = IND_SIZE;
	if (op->a1 == IND_CODE)
		indir = get_dir(mngr, car->pos + (int)OP_BASE, IND_SIZE) %
				(op->op == OP_ld ? IDX_MOD : INT_MAX);
	dir = get_dir(mngr, car->pos + indir, DIR_SIZE);
	if (check_reg(reg))
		*(int *) car->regs[reg].reg = dir;
	car->carry = (char)(dir == 0);
	if (mngr->flags & FLAG_V)
		ft_printf("P    %d | {Blue}%s{eof} %d r%d\n", car->id + 1,
				op->op == OP_ld ? "ld" : "lld", dir, reg + 1);
}

void	make_st(t_mngr *mngr, t_car *car, t_t_op *op)
{
	int reg1;
	int reg2;

	reg1 = mngr->arena[(car->pos + OP_BASE) % MEM_SIZE] - 1;
	if (check_reg(reg1))
	{
		if (op->a2 == REG_CODE)
		{
			reg2 = mngr->arena[(car->pos + OP_BASE + ARG_REG_S) % MEM_SIZE] - 1;
			if (check_reg(reg2))
				ft_memcpy(car->regs + reg2, car->regs + reg1,
                		sizeof(char) * REG_SIZE);
		}
		else
		{
			reg2 = (get_dir(mngr, car->pos + (int)OP_BASE +
			ARG_REG_S, IND_SIZE) % IDX_MOD) + car->pos;
			copy_reg_to_arena(mngr, car, reg1, reg2);
		}
		if (mngr->flags & FLAG_V)
			print_st(car, reg1, reg2, op);
    }
}

void	make_add_sub(t_mngr *mngr, t_car *car, t_t_op *op)
{
	t_int3 arg;
	int res;

	arg.x = mngr->arena[(car->pos + OP_BASE) % MEM_SIZE] - 1;
	arg.y = mngr->arena[(car->pos + OP_BASE + ARG_REG_S) % MEM_SIZE] - 1;
	arg.z = mngr->arena[(car->pos + OP_BASE + ARG_REG_S * 2) % MEM_SIZE] - 1;
	if (check_reg(arg.x) && check_reg(arg.y) && check_reg(arg.z))
	{
        if (op->op == OP_add)
        	res = *(int *) car->regs[arg.x].reg + *(int *) car->regs[arg.y].reg;
        else
        	res = *(int *) car->regs[arg.x].reg - *(int *) car->regs[arg.y].reg;
        *(int *)car->regs[arg.z].reg = res;
        car->carry = (char)(*(int *)car->regs[arg.z].reg == 0);
	}
	if (mngr->flags & FLAG_V)
		ft_printf("P    %d | {Blue}%s{eof} r%d r%d r%d\n", car->id + 1,
				op->op == OP_add ? "add" : "sub", arg.x + 1, arg.y + 1, arg.z + 1);
}

void	make_zjmp(t_mngr *mngr, t_car *car, t_t_op *op)
{
	int arg;

	(void)op;
	arg = get_dir(mngr, car->pos + (int)OP_SIZE, IND_SIZE) % IDX_MOD;
	if (mngr->flags & FLAG_V)
		ft_printf("P    %d | {Blue}%s{eof} %d %s\n", car->id + 1,"zjmp",
				arg, car->carry == 1 ? "OK" : "FAILED");
	if (car->carry == 1)
		car->pos = (car->pos + arg - 3) % MEM_SIZE;
}
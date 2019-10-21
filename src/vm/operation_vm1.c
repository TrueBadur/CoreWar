/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_vm1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehugh-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 16:23:13 by blomo             #+#    #+#             */
/*   Updated: 2019/10/21 13:42:34 by ehugh-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "checkop.h"

int get_arg(t_mngr *mngr, t_car *car, int *step, int type)
{
    int reg;
    int in_dir;

    if (type == REG_CODE)
    {
        reg = mngr->arena[(car->pos + *step) % MEM_SIZE];
        if (check_reg(reg))
            reg = *(int *) car->regs[reg].reg;
        else
            reg = 0;
        *step += 1;
    }
    else if (type == DIR_CODE)
    {
        reg = get_dir(mngr, car->pos + *step, 4);
        *step += 4;
    }
    else
    {
        in_dir = get_dir(mngr, car->pos + *step,2) % IDX_MOD;
        reg = get_dir(mngr, car->pos + in_dir, 4);
        *step += 2;
    }
    return(reg);
}

void make_and_or_xor(t_mngr *mngr, t_car *car, t_t_op *op)
{
    unsigned arg1;
	unsigned arg2;
    int arg3;
    static char step[3] = {1, 4, 2};

	arg3 = mngr->arena[(car->pos + step[op->a1] + step[op->a2] + 1) % MEM_SIZE];
	if (check_reg(arg3))
	{
		arg1 = get_arg(mngr, car, &step, op->a1);
		arg2 = get_arg(mngr, car, &step, op->a2);
		if(op->op == OP_and)
			*(int *)car->regs[arg3].reg = (int)(arg1 & arg2);
		else if (op->op == OP_or)
			*(int *)car->regs[arg3].reg = (int)(arg1 | arg2);
		else if (op->op == OP_xor)
			*(int *)car->regs[arg3].reg = (int)(arg1 ^ arg2);
		car->carry = (char)(*(int *)car->regs[arg3].reg == 0);
	}
}

void make_aff(t_mngr *mngr, t_car *car,t_t_op *op)
{
    int arg1;

    (void)op;
    arg1 = mngr->arena[(car->pos + 2) % MEM_SIZE];
    if (check_reg(arg1))
        write(STDOUT_FILENO, car->regs[arg1].reg, REG_SIZE);
}
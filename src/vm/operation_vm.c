/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_vm.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blomo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 15:41:07 by blomo             #+#    #+#             */
/*   Updated: 2019/10/24 16:55:41 by blomo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "corewar.h"
#include "checkop.h"

void make_live(t_mngr *mngr, t_car *car, t_t_op *op)
{
    int arg1;

    (void)op;
    arg1 = get_dir(mngr, car->pos + 1, 4) + 1;
    if(ft_abs(arg1) < MAX_PLAYERS && mngr->chmps[arg1])
    {
        mngr->winner = arg1;
        ft_printf("this player {\\76}\"%s\"{eof} say allive \n", mngr->chmps[arg1]->name);
    }
    car->live_cycle = mngr->cycle;
    mngr->live_num++;
}

void make_ld_lld(t_mngr *mngr, t_car *car, t_t_op *op)
{
    int dir;
    int reg;
    int indir;

    reg = mngr->arena[(car->pos + 4 + (op->a1 == DIR_CODE) * 2) % MEM_SIZE] - 1;
    indir = 2;
    if (op->a1 == IND_CODE)
    	indir = get_dir(mngr, car->pos + 2, 2) % op->op == OP_ld ? IDX_MOD : INT_MAX;
    dir = get_dir(mngr, car->pos + indir, 4);
    if(check_reg(reg))
        *(int *) car->regs[reg].reg = dir;
    car->carry = (char)(dir == 0);
}

void make_st(t_mngr *mngr, t_car *car, t_t_op *op)
{
    int reg1;
    int reg2;
    int c;

    reg1 = mngr->arena[(car->pos + 2) % MEM_SIZE] - 1;
    if (check_reg(reg1))
    {
        if (op->a2 == REG_CODE)
        {
            reg2 = mngr->arena[(car->pos + 3) % MEM_SIZE] - 1;
            if (check_reg(reg2))
                *(int *) car->regs[reg2].reg = *(int *) car->regs[reg1].reg;
        }
        else
        {
            reg2 = (get_dir(mngr, car->pos + 3, 2) % IDX_MOD) + car->pos;
            c = -1;
            while (++c < REG_SIZE)
                mngr->arena[(reg2 + c  + MEM_SIZE) % MEM_SIZE] = car->regs[reg1].reg[c];
        }
    }
}

void make_add_sub(t_mngr *mngr, t_car *car, t_t_op *op)
{
    int reg1;
    int reg2;
    int reg3;

    reg1 = mngr->arena[(car->pos + 2) % MEM_SIZE] - 1;
    reg2 = mngr->arena[(car->pos + 3) % MEM_SIZE] - 1;
    reg3 = mngr->arena[(car->pos + 4) % MEM_SIZE] - 1;
    if(check_reg(reg1) && check_reg(reg2) && check_reg(reg3))
    {
        if(op->op == OP_add)
            *(int *) car->regs[reg3].reg = *(int *) car->regs[reg1].reg + *(int *) car->regs[reg2].reg;
        else
            *(int *) car->regs[reg3].reg = *(int *) car->regs[reg1].reg - *(int *) car->regs[reg2].reg;
        car->carry = (char)(*(int *)car->regs[reg3].reg == 0);
    }
}

void make_zjmp(t_mngr *mngr, t_car *car, t_t_op *op)
{
    int arg1;

    (void)op;
    arg1 = get_dir(mngr, car->pos + 1, 2) % IDX_MOD;
    if(car->carry == 1)
        car->pos += arg1;
}
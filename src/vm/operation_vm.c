/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_vm.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blomo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 15:41:07 by blomo             #+#    #+#             */
/*   Updated: 2019/10/18 15:53:08 by blomo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "checkop.h"

void make_live(t_mngr *mngr, t_car *car, t_t_op *op)
{
    int arg1;

    arg1 = get_dir(mngr, car->pos + 1, 4);
    if(ft_abs(arg1) < MAX_PLAYERS && mngr->chmps[arg1])
        mngr->winer = arg1;
    car->live_cycle = mngr->cycle;
    mngr->live_num++;
}

void make_ld_lld(t_mngr *mngr, t_car *car, t_t_op *op)
{
    int dir;
    int reg;
    int indir;

    reg = mngr->arena[(car->pos + 4 + (op->a1 == DIR_CODE) * 2) % MEM_SIZE];
    if(op->op == 2)
        indir = (op->a1 == IND_CODE) ? get_dir(mngr, car->pos + 2, 2) % IDX_MOD : 2;
    else
        indir = (op->a1 == IND_CODE) ? get_dir(mngr, car->pos + 2, 2) : 2;
    dir = get_dir(mngr, car->pos + indir, 4);
    if(check_reg(reg))
        *(int *) car->regs[reg].reg = dir;
    car->carry = (char)(dir == 0);
}

void make_st(t_mngr *mngr, t_car *car, t_t_op *op)
{
    int reg1;
    int reg2;

    reg1 = mngr->arena[(car->pos + 2) % MEM_SIZE];
    if (op->a1 == IND_CODE)
        reg2 = mngr->arena[(car->pos + (get_dir(mngr, car->pos + 3, 2) % IDX_MOD)) % MEM_SIZE];
    else
        reg2 = mngr->arena[(car->pos + 3) % MEM_SIZE];
    if (check_reg(reg1) && check_reg(reg2))
        *(int*)car->regs[reg2].reg = *(int*)car->regs[reg1].reg;
}

void make_add_sub(t_mngr *mngr, t_car *car, t_t_op *op)
{
    int reg1;
    int reg2;
    int reg3;

    reg1 = mngr->arena[(car->pos + 2) % MEM_SIZE];
    reg2 = mngr->arena[(car->pos + 3) % MEM_SIZE];
    reg3 = mngr->arena[(car->pos + 4) % MEM_SIZE];
    if(check_reg(reg1) && check_reg(reg2) && check_reg(reg3))
    {
        if(op->op == 4)
            *(int *) car->regs[reg3].reg = *(int *) car->regs[reg1].reg + *(int *) car->regs[reg2].reg;
        else
            *(int *) car->regs[reg3].reg = *(int *) car->regs[reg1].reg - *(int *) car->regs[reg2].reg;
        car->carry = (char)(*(int *)car->regs[reg3].reg == 0);
    }
}

void make_zjmp(t_mngr *mngr, t_car *car, t_t_op *op)
{
    int arg1;

    arg1 = get_dir(mngr, car->pos + 1, 2) % IDX_MOD;
    if(car->carry == 1)
        car->pos = arg1;
}
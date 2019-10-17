/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blomo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 15:05:59 by blomo             #+#    #+#             */
/*   Updated: 2019/10/17 22:36:47 by blomo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "checkop.h"

void make_live(t_mngr *mngr, t_car *car, t_t_op *op)
{
    int dir;

    dir = get_dir(mngr, car->pos + 1, 4);
    if(ft_abs(dir) < MAX_PLAYERS && mngr->chmps[dir])
        mngr->winer = dir;
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
        reg2 =  mngr->arena[(car->pos + (get_dir(mngr, car->pos + 3, 2) % IDX_MOD)) % MEM_SIZE];
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

void make_and_or_xor(t_mngr *mngr, t_car *car, t_t_op *op)
{
    int arg1;
    int arg2;
    int arg3;
    int step;
    int in_dir;

    step = 2;
    if(op->a1 == REG_CODE)
    {
        arg1 = mngr->arena[(car->pos + step) % MEM_SIZE];
        if (check_reg(arg1))
            arg1 = *(int *)car->regs[arg1].reg;
        step += 1;
    }
    else if(op->a1 == DIR_CODE)
    {
        arg1 = get_dir(mngr, car->pos + step, 4);
        step += 4;
    }
    else
    {
        in_dir = get_dir(mngr, car->pos + step,2) % IDX_MOD;
        arg1 = get_dir(mngr, car->pos + in_dir, 4);
        step += 2;
    }

    if(op->a2 == REG_CODE)
    {
        arg2 = mngr->arena[(car->pos + step) % MEM_SIZE];
        if (check_reg(arg2))
            arg2 = *(int *)car->regs[arg2].reg;
        step += 1;
    }
    else if(op->a2 == DIR_CODE)
    {
        arg2 = get_dir(mngr, car->pos + step, 4);
        step += 4;
    }
    else
    {
        in_dir = get_dir(mngr, car->pos + step,2) % IDX_MOD;
        arg2 = get_dir(mngr, car->pos + in_dir, 4);
        step += 2;
    }
    arg3 = mngr->arena[(car->pos + step) % MEM_SIZE];
    if(check_reg(arg3) && op->op == 6)
        *(int *)car->regs[arg3].reg = arg1 & arg2; // TODO i do know why
    else if (check_reg(arg3) && op->op == 7)
        *(int *)car->regs[arg3].reg = arg1 | arg2;
    else if (check_reg(arg3) && op->op == 8)
        *(int *)car->regs[arg3].reg = arg1 ^ arg2;
}

void make_zjmp(t_mngr *mngr, t_car *car, t_t_op *op)
{
    int arg1;

    arg1 = get_dir(mngr, car->pos + 1, 2) % IDX_MOD;
    if(car->carry == 1)
        car->pos = arg1;
}

void make_ldi_lldi(t_mngr *mngr, t_car *car, t_t_op *op)
{
    int arg1;
    int arg2;
    int arg3;
    int step;
    int in_dir;

    step = 2;
    if(op->a1 == REG_CODE)
    {
        arg1 = mngr->arena[(car->pos + step) % MEM_SIZE];
        if (check_reg(arg1))
            arg1 = *(int *)car->regs[arg1].reg;
        step += 1;
    }
    else if(op->a1 == DIR_CODE)
    {
        arg1 = get_dir(mngr, car->pos + step, 4);
        step += 4;
    }
    else
    {
        in_dir = get_dir(mngr, car->pos + step,2) % IDX_MOD;
        arg1 = get_dir(mngr, car->pos + in_dir, 4);
        step += 2;
    }

    if(op->a2 == REG_CODE)
    {
        arg2 = mngr->arena[(car->pos + step) % MEM_SIZE];
        if (check_reg(arg2))
            arg2 = *(int *)car->regs[arg2].reg;
        step += 1;
    }
    else
    {
        arg2 = get_dir(mngr, car->pos + step, 4);
        step += 4;
    }
    arg3 = mngr->arena[(car->pos + step) % MEM_SIZE];
    if(check_reg(arg3) && op->op == 10)
        *(int *)car->regs[arg3].reg = (car->pos + arg1 + arg2) % IDX_MOD;
    else
        *(int *)car->regs[arg3].reg = (car->pos + arg1 + arg2);
}

void make_sti(t_mngr *mngr, t_car *car, t_t_op *op)
{
    int arg1;
    int arg2;
    int arg3;
    int step;
    int in_dir;

    step = 1;
    arg1 = mngr->arena[(car->pos + step) % MEM_SIZE];
    if(op->a2 == REG_CODE)
    {
        arg2 = mngr->arena[(car->pos + step) % MEM_SIZE];
        if (check_reg(arg2))
            arg2 = *(int *)car->regs[arg2].reg;
        step += 1;
    }
    else if(op->a2 == DIR_CODE)
    {
        arg1 = get_dir(mngr, car->pos + step, 4);
        step += 4;
    }
    else
    {
        in_dir = get_dir(mngr, car->pos + step,2) % IDX_MOD;
        arg1 = get_dir(mngr, car->pos + in_dir, 4);
        step += 2;
    }

    if(op->a3 == REG_CODE)
    {
        arg3 = mngr->arena[(car->pos + step) % MEM_SIZE];
        if (check_reg(arg3))
            arg2 = *(int *)car->regs[arg3].reg;
    }
    else
        arg3 = get_dir(mngr, car->pos + step, 4);
    if(check_reg(arg1))
        *(int *)car->regs[arg1].reg = (car->pos + arg2 + arg3) % IDX_MOD;
}

void make_fork(t_mngr *mngr, t_car *car, t_t_op *op)
{

}

void make_lfork(t_mngr *mngr, t_car *car, t_t_op *op)
{

}
void make_aff(t_mngr *mngr, t_car *car,t_t_op *op)
{

}
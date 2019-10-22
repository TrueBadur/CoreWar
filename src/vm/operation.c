/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blomo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 15:05:59 by blomo             #+#    #+#             */
/*   Updated: 2019/10/21 17:55:15 by blomo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "checkop.h"

void make_ldi_lldi(t_mngr *mngr, t_car *car, t_t_op *op)
{
    int arg1;
    int arg2;
    int arg3;
    static char step[3] = {1, 4, 2};

    arg3 = mngr->arena[(car->pos + 2 + step[op->a1] + step[op->a2]) % MEM_SIZE];
    if (check_reg(arg3))
    {
        if (op->a1 == DIR_CODE)
            arg1 = get_dir(mngr, car->pos + 2, 2);
        else
            arg1 = (op->a1 == REG_CODE) ? get_reg(mngr, car, 2) : get_indir(mngr, car, 2);
        arg2 = (op->a2 == REG_CODE) ? get_reg(mngr, car, 2 + step[op->a1]) : get_dir(mngr, car->pos + 2 + step[op->a1], 2);
        if(op->op == OP_ldi)
            *(int *)car->regs[arg3].reg = (car->pos + arg1 + arg2) % IDX_MOD;
        else
            *(int *)car->regs[arg3].reg = (car->pos + arg1 + arg2);
    }
}

void make_sti(t_mngr *mngr, t_car *car, t_t_op *op)
{
    int arg1;
    int arg2;
    int arg3;
    int pos;
    static char step[3] = {1, 4, 2};

    arg1 = mngr->arena[(car->pos + 2) % MEM_SIZE];
    if (check_reg(arg1))
    {
        if (op->a2 == DIR_CODE)
            arg2 = get_dir(mngr, car->pos + 3, 2);
        else
            arg2 = (op->a2 == REG_CODE) ? get_reg(mngr, car, 3) : get_indir(mngr, car, 3);
        arg3 = (op->a3 == REG_CODE) ? get_reg(mngr, car, 3 + step[op->a2]) : get_dir(mngr, car->pos + 3 + step[op->a2], 2);
        pos = (arg2 + arg3) % IDX_MOD + car->pos;
        mngr->arena[pos % MEM_SIZE] = car->regs[arg1].reg[0];
        mngr->arena[(pos + 1) % MEM_SIZE] = car->regs[arg1].reg[1];
        mngr->arena[(pos + 2) % MEM_SIZE] = car->regs[arg1].reg[2];
        mngr->arena[(pos + 3) % MEM_SIZE] = car->regs[arg1].reg[3];
    }
}

void make_fork_lfork(t_mngr *mngr, t_car *car, t_t_op *op)
{
    t_car *newcar;
    int arg1;

    if(!(newcar = (t_car*)malloc(sizeof(t_car))))
        safe_exit(mngr, MALLOC_ERROR);
    ft_memcpy(newcar, car, sizeof(t_car));
    if (op->op == 12)
        arg1 = (get_dir(mngr, car->pos + 1, 2)) % IDX_MOD;
    else
        arg1 = get_dir(mngr, car->pos + 1, 2);
    mngr->num_cars++;
    if(newcar)
        newcar->pos = arg1;
    //TODO нужно добавить каретку newcar к списку кареток
}

void make_and_or_xor(t_mngr *mngr, t_car *car, t_t_op *op)
{
    unsigned arg1;
    unsigned arg2;
    int arg3;
    static char step[3] = {1, 4, 2};

    arg3 = mngr->arena[(car->pos + 2 + step[op->a1] + step[op->a2]) % MEM_SIZE];
    if (check_reg(arg3))
    {
        if (op->a1 == DIR_CODE)
            arg1 = get_dir(mngr, car->pos + 2, 4);
        else
            arg1 = (op->a1 == REG_CODE) ? get_reg(mngr, car, 2) : get_indir(mngr, car, 2);
        if (op->a2 == DIR_CODE)
            arg2 = get_dir(mngr, car->pos + 2 + step[op->a1], 4);
        else
            arg2 = (op->a1 == REG_CODE) ? get_reg(mngr, car, 2 + step[op->a1]) : get_indir(mngr, car, 2 + step[op->a1]);
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

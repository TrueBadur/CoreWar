/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blomo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 15:05:59 by blomo             #+#    #+#             */
/*   Updated: 2019/10/18 16:58:50 by blomo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "checkop.h"

int get_arg1(t_mngr *mngr, t_car *car, int *step, int type)
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
        reg = get_dir(mngr, car->pos + *step, 2);
        *step += 2;
    }
    else
    {
        in_dir = get_dir(mngr, car->pos + *step,2) % IDX_MOD;
        reg = get_dir(mngr, car->pos + in_dir, 4);
        *step += 2;
    }
    return(reg);
}

void make_ldi_lldi(t_mngr *mngr, t_car *car, t_t_op *op)
{
    int arg1;
    int arg2;
    int arg3;
    int step;

    step = 2;
    arg1 = get_arg1(mngr, car, &step, op->a1);
    arg2 = get_arg1(mngr, car, &step, op->a2);
    arg3 = mngr->arena[(car->pos + step) % MEM_SIZE];
    if(check_reg(arg3) && op->op == 10)
        *(int *)car->regs[arg3].reg = (car->pos + arg1 + arg2) % IDX_MOD;
    else if(check_reg(arg3) && op->op == 14)
        *(int *)car->regs[arg3].reg = (car->pos + arg1 + arg2);
}

void make_sti(t_mngr *mngr, t_car *car, t_t_op *op)
{
    int arg1;
    int arg2;
    int arg3;
    int step;

    step = 3;
    arg1 = mngr->arena[(car->pos + 2) % MEM_SIZE];
    arg2 = get_arg1(mngr, car, &step, op->a1);
    arg3 = get_arg1(mngr, car, &step, op->a2);
    if(check_reg(arg1))
        *(int *)car->regs[arg1].reg = (car->pos + arg2 + arg3) % IDX_MOD;
}

void    copy_car(t_car *car,t_car *newcar, int pos)
{
    int i;

    i = REG_NUMBER;
    while(i < REG_NUMBER)
    {
        ft_strcpy(newcar->regs[i],car->regs[i];
        i--;
    }
    newcar->id = car->id;
    newcar->pos = pos;
    newcar->carry = car->carry;
    newcar->eval_in = car->eval_in;
    newcar->byte_next_op = car->byte_next_op;
    newcar->live_cycle = car->live_cycle;
    newcar->op_code = car->op_code;
}

void make_fork_lfork(t_mngr *mngr, t_car *car, t_t_op *op)
{
    t_car *newcar;
    int arg1;

    if(!(newcar = (t_car*)malloc(sizeof(t_car))))
        safe_exit(mngr, MALLOC_ERROR);
    if (op->op == 12)
        arg1 = (get_dir(mngr, car->pos + 1, 2)) % IDX_MOD;
    else
        arg1 = get_dir(mngr, car->pos + 1, 2);
    mngr->num_cars++;
    copy_car(car, newcar, arg1);
}

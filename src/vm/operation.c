/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blomo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 15:05:59 by blomo             #+#    #+#             */
/*   Updated: 2019/10/25 19:29:48 by blomo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "checkop.h"
#include <limits.h>


void make_ldi_lldi(t_mngr *mngr, t_car *car, t_t_op *op)
{
    int arg1;
    int arg2;
    int arg3;
    int res;
    static char step[4] = {1, 2, 2};

    arg3 = mngr->arena[(car->pos + 2 + step[op->a1 - 1] + step[op->a2 - 1]) % MEM_SIZE] - 1;
    if (check_reg(arg3))
    {
        if (op->a1 == DIR_CODE)
            arg1 = get_dir(mngr, car->pos + 2, 2);
        else
            arg1 = (op->a1 == REG_CODE) ? get_reg(mngr, car, 2) : get_indir(mngr, car, 2);
        arg2 = (op->a2 == REG_CODE) ? get_reg(mngr, car, 2 + step[op->a1 - 1]) : get_dir(mngr, car->pos + 2 + step[op->a1 - 1], 2);
        res = (car->pos + arg1 + arg2) % (op->op == OP_ldi ? IDX_MOD : INT_MAX);
        res = get_dir(mngr, res,4);
        ft_printf("CAR {Red}%d{eof} doing %s  arg1 = %d arg2 = %d r%d \n load from %d + %d = %d  nbr = %d\n",car->id, op->op == OP_ldi ? "ldi" : "lldi", arg1,arg2,arg3+1,arg1,arg2,arg1+arg2,res);
        *(int*)car->regs[arg3].reg = res;
    }
}

void make_sti(t_mngr *mngr, t_car *car, t_t_op *op)
{
    int arg1;
    int arg2;
    int arg3;
    int pos;
    static char step[4] = {1, 2, 2};

    arg1 = mngr->arena[(car->pos + 2) % MEM_SIZE] - 1;
    if (check_reg(arg1))
    {
        if (op->a2 == DIR_CODE)
            arg2 = get_dir(mngr, car->pos + 3, 2);
        else
            arg2 = (op->a2 == REG_CODE) ? get_reg(mngr, car, 3) : get_indir(mngr, car, 3);
        arg3 = (op->a3 == REG_CODE) ? get_reg(mngr, car, 3 + step[op->a2 - 1]) : get_dir(mngr, car->pos + 3 + step[op->a2 - 1], 2);
        pos = (arg2 + arg3) % IDX_MOD + car->pos;
        ft_printf("CAR {Red}%d{eof} doing %s r%d arg2 = %d arg3 = %d \n store to %d + %d = %d  value = %d \n",car->id, "sti" , arg1 + 1, arg2 , arg3,arg2,arg3,arg2+arg3,pos);
        arg2 = -1;
        while (++arg2 < REG_SIZE)
            mngr->arena[(pos + 3 - arg2  + MEM_SIZE) % MEM_SIZE] = car->regs[arg1].reg[arg2];
//        mngr->arena[pos % MEM_SIZE] = car->regs[arg1].reg[0];
//        mngr->arena[(pos + 1) % MEM_SIZE] = car->regs[arg1].reg[1];
//        mngr->arena[(pos + 2) % MEM_SIZE] = car->regs[arg1].reg[2];
//        mngr->arena[(pos + 3) % MEM_SIZE] = car->regs[arg1].reg[3];
    }
}

void make_fork_lfork(t_mngr *mngr, t_car *car, t_t_op *op)
{
    t_car *newcar;
    int arg1;

    newcar = resurect_car(mngr);
    if (newcar == NULL)
    {
        if(!(newcar = (t_car*)malloc(sizeof(t_car))))
            safe_exit(mngr, MALLOC_ERROR);

    }
    ft_memcpy(newcar, car, sizeof(t_car));
    ft_vecpush(mngr->cars, &newcar, sizeof(newcar));
    if (op->op == 12)
        arg1 = (get_dir(mngr, car->pos + 1, 2)) % IDX_MOD;
    else
        arg1 = get_dir(mngr, car->pos + 1, 2);
    mngr->num_cars++;
    ft_printf("CAR {Red}%d{eof} doing %s arg = %d (%d) \n",car->id, op->op == OP_fork ? "fork" : "lfork", arg1 , (arg1 + car->pos) % MEM_SIZE);
    newcar->pos = (arg1 + car->pos) % MEM_SIZE;
    newcar->just_forked = 1;
    newcar->id = mngr->num_cars - 1;
    tl_put(mngr, (short) (mngr->cycle % (MAX_OP_TIME + 1)), ft_lstnew_noc(newcar, sizeof(newcar)), 0);
    //TODO нужно добавить каретку newcar к списку кареток
}

void make_and_or_xor(t_mngr *mngr, t_car *car, t_t_op *op)
{
    unsigned arg1;
    unsigned arg2;
    int arg3;
    int res;
    static char step[3] = {1, 4, 2};

    res = 0;
    arg3 = mngr->arena[(car->pos + 2 + step[op->a1 - 1] + step[op->a2 - 1]) % MEM_SIZE] - 1;
    if (check_reg(arg3))
    {
        if (op->a1 == DIR_CODE)
            arg1 = get_dir(mngr, car->pos + 2, 4);
        else
            arg1 = (op->a1 == REG_CODE) ? get_reg(mngr, car, 2) : get_indir(mngr, car, 2);
        if (op->a2 == DIR_CODE)
            arg2 = get_dir(mngr, car->pos + 2 + step[op->a1 - 1], 4);
        else
            arg2 = (op->a1 == REG_CODE) ? get_reg(mngr, car, 2 + step[op->a1 - 1]) : get_indir(mngr, car, 2 + step[op->a1 - 1]);
        ft_printf("CAR {Red}%d{eof} doing %s r1 = %d r2 = %d r3 = %d\n", car->id, op->op == OP_and ? "and" : op->op == OP_or ? "or" : "xor", arg1, arg2 , arg3);
        if(op->op == OP_and)
            res = (int)(arg1 & arg2);
        else if (op->op == OP_or)
            res = (int)(arg1 | arg2);
        else if (op->op == OP_xor)
            res = (int)(arg1 ^ arg2);
       *(int*)car->regs[arg3].reg = res;
        car->carry = (char)(*(int *)car->regs[arg3].reg == 0);
    }
}

void make_aff(t_mngr *mngr, t_car *car,t_t_op *op)
{
    int arg1;

    (void)op;
    arg1 = mngr->arena[(car->pos + 2) % MEM_SIZE] - 1;
    if (check_reg(arg1))
        write(STDOUT_FILENO, car->regs[arg1].reg, REG_SIZE);
}

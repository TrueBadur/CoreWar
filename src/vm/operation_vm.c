/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_vm.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blomo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 15:41:07 by blomo             #+#    #+#             */
/*   Updated: 2019/10/25 17:22:00 by blomo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "corewar.h"
#include "checkop.h"

void make_live(t_mngr *mngr, t_car *car, t_t_op *op)
{
    int arg;
    int mod_arg;
    int i;

    i = 0;
    (void)op;
    arg = get_dir(mngr, car->pos + 1, 4);
    mod_arg = ft_abs(arg) - 1;
    if (arg < 0 && mod_arg < MAX_PLAYERS && mngr->chmps[mod_arg])
    {
        mngr->winner = mod_arg;
        i = 1;
    }
    car->live_cycle = mngr->cycle;
    mngr->live_num++;
    if(mngr->flags & V)
        print_live(mngr, car, i, arg);
}

void make_ld_lld(t_mngr *mngr, t_car *car, t_t_op *op)
{
    int dir;
    int reg;
    int indir;

    reg = mngr->arena[(car->pos + 4 + (op->a1 == DIR_CODE) * 2) % MEM_SIZE] - 1;
    indir = 2;
    if (op->a1 == IND_CODE)
        indir = get_dir(mngr, car->pos + 2, 2) % (op->op == OP_ld ? IDX_MOD : INT_MAX);
    dir = get_dir(mngr, car->pos + indir, 4);
    if(check_reg(reg))
        *(int *) car->regs[reg].reg = dir;
    car->carry = (char)(dir == 0);
    if(mngr->flags & V)
    {
        ft_printf("P    %d  |  %s %d r%d\n", car->id + 1, op->op == OP_ld ? "ld" : "lld", dir, reg + 1);
        print_addr(mngr, car->pos,op->a1 == IND_CODE ? 5 : 7);
    }
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
                ft_memcpy(car->regs + reg2, car->regs + reg1, sizeof(char) * REG_SIZE);
        }
        else
        {
            reg2 = (get_dir(mngr, car->pos + 3, 2) % IDX_MOD) + car->pos;
            c = -1;
            while (++c < REG_SIZE)
                mngr->arena[(reg2 + 3 - c  + MEM_SIZE) % MEM_SIZE] = car->regs[reg1].reg[c];
        }
        if (mngr->flags & V)
        {
            print_st(car, reg1, reg2, op);
            print_addr(mngr, car->pos,op->a2 == REG_CODE ? 4 : 5);
        }
    }
}

void make_add_sub(t_mngr *mngr, t_car *car, t_t_op *op)
{
    int reg1;
    int reg2;
    int reg3;
    int res;

    reg1 = mngr->arena[(car->pos + 2) % MEM_SIZE] - 1;
    reg2 = mngr->arena[(car->pos + 3) % MEM_SIZE] - 1;
    reg3 = mngr->arena[(car->pos + 4) % MEM_SIZE] - 1;
    if(check_reg(reg1) && check_reg(reg2) && check_reg(reg3))
    {
        if(op->op == OP_add)
            res = *(int *) car->regs[reg1].reg + *(int *) car->regs[reg2].reg;
        else
            res = *(int *) car->regs[reg1].reg - *(int *) car->regs[reg2].reg;
        *(int *)car->regs[reg3].reg = res;
        car->carry = (char)(*(int *)car->regs[reg3].reg == 0);
    }
    if (mngr->flags & V)
    {
        ft_printf("P    %d  |  %s r%d r%d r%d\n", car->id + 1, op->op == OP_add ? "add" : "sub", reg1 + 1, reg2 + 1, reg3 + 1);
        print_addr(mngr, car->pos, 5);
    }
}

void make_zjmp(t_mngr *mngr, t_car *car, t_t_op *op)
{
    int arg;

    (void)op;
    arg = get_dir(mngr, car->pos + 1, 2) % IDX_MOD;
    if(car->carry == 1)
        car->pos = (car->pos + arg - 3) % MEM_SIZE;
    if (mngr->flags & V)
    {
        ft_printf("P    %d  |  %s %d %s\n", car->id + 1,"zjmp", arg, car->carry == 1 ? "OK" : "FAILED");
        print_addr(mngr, car->pos, 5);
    }
}
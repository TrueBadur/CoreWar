/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_vm.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blomo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 15:41:07 by blomo             #+#    #+#             */
/*   Updated: 2019/10/24 21:52:29 by blomo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "corewar.h"
#include "checkop.h"

void make_live(t_mngr *mngr, t_car *car, t_t_op *op)
{
    int arg1;

    (void)op;
    arg1 = ft_abs(get_dir(mngr, car->pos + 1, 4));
    ft_printf("CAR {Red}%d{eof} doing \"live\" %d\n", car->id, -arg1); //TODO move under if with flag check
    if(arg1 - 1 < MAX_PLAYERS && mngr->chmps[arg1 - 1])
    {
        mngr->winner = arg1 - 1;
        ft_printf("this player {\\76}\"%s\"{eof} say alive \n", mngr->chmps[arg1 - 1]->name);
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
    ft_printf("CAR {Red}%d{eof} doing \"%s\" {\\200}%d {Green}%d{eof}\n", car->id, op->op == OP_ld ? "ld" : "lld", dir, reg);
    if(check_reg(reg))
        *(int *) car->regs[reg].reg = dir;
    ft_printf("|||%d|||\n", *(int *) car->regs[reg].reg);
    car->carry = (char)(dir == 0);
}

void make_st(t_mngr *mngr, t_car *car, t_t_op *op)
{
    int reg1;
    int reg2;
    int c;

    reg1 = mngr->arena[(car->pos + 2) % MEM_SIZE] - 1;
    ft_printf("CAR {Red}%d{eof} doing \"st\" {Green}r%d{eof} ", car->id, reg1 + 1);
    if (check_reg(reg1))
    {
        if (op->a2 == REG_CODE)
        {
            reg2 = mngr->arena[(car->pos + 3) % MEM_SIZE] - 1;
            if (check_reg(reg2))
                ft_memcpy(car->regs + reg2, car->regs + reg1, sizeof(char) * REG_SIZE);
            ft_printf("from {Green}r%d{eof}", reg2 + 1);
            ft_printf(" r%d = %d\n", reg2, car->regs[reg2]);

        }
        else
        {
            reg2 = (get_dir(mngr, car->pos + 3, 2) % IDX_MOD) + car->pos;
            c = -1;
            ft_printf("{\\200}%d{eof}\n", reg2 - car->pos);
            while (++c < REG_SIZE)
                mngr->arena[(reg2 + 3 - c  + MEM_SIZE) % MEM_SIZE] = car->regs[reg1].reg[c];
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
    ft_printf("make %d r1 = %d r2 = %d r3 = %d\n",op->op, reg1, reg2 , reg3);
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
    ft_printf("make %d dir = %d\n",op->op, arg1);
    if(car->carry == 1)
        car->pos += arg1;
}
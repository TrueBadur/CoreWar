/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blomo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 15:05:59 by blomo             #+#    #+#             */
/*   Updated: 2019/10/30 19:01:50 by blomo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "checkop.h"
#include <limits.h>


void make_ldi_lldi(t_mngr *mngr, t_car *car, t_t_op *op)
{
	t_int3 arg;
    int res;
    static char step[3] = {ARG_REG_S, IND_SIZE, IND_SIZE};

    res = OP_BASE + step[op->a1 - 1] + step[op->a2 - 1];
    arg.z = mngr->arena[(car->pos + res) % MEM_SIZE] - 1;
    if (check_reg(arg.z))
    {
		arg.x = get_arg_indir(mngr, car, op->a1, OP_BASE);
		arg.y = get_arg_indir(mngr, car, op->a1, OP_BASE + step[op->a1 - 1]);
        res = (car->pos + arg.x + arg.y) % (op->op == OP_ldi ? IDX_MOD : INT_MAX);
        res = get_dir(mngr, res, DIR_SIZE);
        *(int*)car->regs[arg.z].reg = res;
        if (mngr->flags & FLAG_V)
        {
            ft_printf("P    %d | {Blue}%s{eof} %d %d r%d\n", car->id + 1,
            		op->op == OP_ldi ? "ldi" :"lldi", arg.x, arg.y, arg.z + 1);
            ft_printf("       | -> load from %d + %d = %d "
					  "(with pc and mod %d)\n", arg.x, arg.y, arg.x + arg.y,
					  (car->pos + arg.x + arg.y) % MEM_SIZE);
        }
    }
}

void make_sti(t_mngr *mngr, t_car *car, t_t_op *op)
{
	t_int3 arg;
    int pos;
    static char step[3] = {ARG_REG_S, IND_SIZE, IND_SIZE};

    arg.x = mngr->arena[(car->pos + OP_BASE) % MEM_SIZE] - 1;
    if (check_reg(arg.x))
    {
    	pos = OP_BASE + ARG_REG_S;
        if (op->a2 == DIR_CODE)
            arg.y = get_dir(mngr, car->pos + pos, IND_SIZE);
        else
            arg.y = (op->a2 == REG_CODE) ? get_arg_reg(mngr, car, pos) :
				   get_indir(mngr, car, pos);
        pos += step[op->a2 - 1];
        arg.z = (op->a3 == REG_CODE) ? get_arg_reg(mngr, car, pos) :
			   get_dir(mngr, car->pos + pos, IND_SIZE);
        pos = (arg.y + arg.z) % IDX_MOD + car->pos;
        if (mngr->flags & FLAG_V)
			print_sti(car, arg.x, arg.y, arg.z);
		copy_reg_to_arena(mngr, car, arg.x, pos);
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
        arg1 = (get_dir(mngr, car->pos + (int)OP_SIZE, IND_SIZE)) % IDX_MOD;
    else
        arg1 = get_dir(mngr, car->pos + (int)OP_SIZE, IND_SIZE);
    mngr->num_cars++;
    newcar->pos = (arg1 + car->pos) % MEM_SIZE;
    newcar->id = mngr->num_cars - 1;
    tl_put(mngr, (short) (mngr->cycle % (MAX_OP_TIME + 1)),
    		ft_lstnew_noc(newcar, sizeof(newcar)), 0);
    if (mngr->flags & FLAG_V)
        ft_printf("P    %d | {Blue}%s{eof} %d (%d)\n", car->id + 1,
        		op->op == OP_fork ? "fork" : "lfork", arg1,newcar->pos);
}

void make_and_or_xor(t_mngr *mngr, t_car *car, t_t_op *op)
{
    unsigned arg1;
    unsigned arg2;
    int arg3;
    int res;
    static char step[3] = {ARG_REG_S, DIR_SIZE, IND_SIZE};

    res = OP_BASE + step[op->a1 - 1] + step[op->a2 - 1];
    arg3 = mngr->arena[(car->pos + res) % MEM_SIZE] - 1;
    if (check_reg(arg3))
    {
        arg1 = get_arg(mngr, car, op->a1, OP_BASE);
		arg2 = get_arg(mngr, car, op->a2, OP_BASE + step[op->a1 - 1]);
        if(op->op == OP_and)
			*(int*)car->regs[arg3].reg = (int)(arg1 & arg2);
        else if (op->op == OP_or)
			*(int*)car->regs[arg3].reg = (int)(arg1 | arg2);
        else if (op->op == OP_xor)
			*(int*)car->regs[arg3].reg = (int)(arg1 ^ arg2);
        car->carry = (char)(*(int *)car->regs[arg3].reg == 0);
        if (mngr->flags & FLAG_V)
            ft_printf("P    %d | {Blue}%s{eof} %d %d r%d\n", car->id + 1,
            		op->op == OP_and ? "and" : op->op == OP_or ? "or" : "xor",
            		arg1, arg2, arg3 + 1);
    }
}

void make_aff(t_mngr *mngr, t_car *car,t_t_op *op)
{
    int arg1;

    (void)op;
    arg1 = mngr->arena[(car->pos + OP_BASE) % MEM_SIZE] - 1;
    if (mngr->flags & FLAG_V)
    {
        ft_printf("P    %d | {Blue}%s{eof} %d\n", car->id + 1, "aff",
        		arg1 + 1);
    }
    if (check_reg(arg1))
        write(STDOUT_FILENO, (char*)car->regs[arg1].reg, ARG_REG_S);
}

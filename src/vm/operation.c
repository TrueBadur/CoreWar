/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehugh-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 15:05:59 by blomo             #+#    #+#             */
/*   Updated: 2019/11/10 12:37:25 by ehugh-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "checkop.h"
#include <limits.h>


void make_ldi_lldi(t_mngr *mngr, t_car *car, t_t_op *op)
{
	t_int3	args;
	int res;
	static char step[3] = {ARG_REG_S, IND_SIZE, IND_SIZE};

	res = OP_BASE + step[op->a1 - 1] + step[op->a2 - 1];
	ft_bzero(&args, sizeof(t_int3));
	args.z = 1;
	if (get_args(mngr, car, op, &args))
	{
//		args.z = mngr->arena[get_addr_arena(car->pos + res)] - 1;
		res = car->pos + ((args.x + args.y) % (op->op == OP_ldi ? IDX_MOD : INT_MAX));
		res = get_dir(mngr, &res, DIR_SIZE);
		*(int*)car->regs[args.z].reg = res;
		if (mngr->flags & FLAG_V)
		{
//			ft_printf("P    %d | {Blue}%s{eof} %d %d r%d\n", car->id + 1,
//					  op->op == OP_ldi ? "ldi" :"lldi", args.x, args.y, args.z + 1);
//			ft_printf("       | -> load from %d + %d = %d "
//					  "(with pc and mod %d)\n", args.x, args.y, args.x + args.y,
//					  (car->pos + args.x + args.y) % MEM_SIZE);
//			ft_printf("test otkyda schitivali %d, reg  = %d\n",car->pos + ((args.x + args.y) % (op->op == OP_ldi ? IDX_MOD : INT_MAX)), *(int*)car->regs[args.z].reg); // test

			ft_printf("P %4d | %s %d %d r%d\n", car->id + 1,
					  op->op == OP_ldi ? "ldi" :"lldi", args.x, args.y, args.z + 1);
			ft_printf("       | -> load from %d + %d = %d "
					  "(with pc and mod %d)\n", args.x, args.y, args.x + args.y,
					  (car->pos + args.x + args.y) % MEM_SIZE);
		}
	}
}

void make_sti(t_mngr *mngr, t_car *car, t_t_op *op)
{
	t_int3	args;
	int res;

	ft_bzero(&args, sizeof(t_int3));
	args.x = 1;
	if (get_args(mngr, car, op, &args))
	{
		res = car->pos + ((args.y + args.z) % IDX_MOD);
		args.x = mngr->arena[get_addr_arena(car->pos + OP_BASE)] - 1;
		copy_reg_to_arena(mngr, car, args.x, res);
		if (mngr->flags & FLAG_V)
			print_sti(car, args.x, args.y, args.z);
	}
}
//todo move to lib
//int ft_mod(int a, int b)
//{
//	int r = a % b;
//	return r < 0 ? r + b : r;
//}

void make_fork_lfork(t_mngr *mngr, t_car *car, t_t_op *op)
{
	t_int3	args;
	t_car *newcar;

	ft_bzero(&args, sizeof(t_int3));
	get_args(mngr, car, op, &args);
    newcar = resurect_car(mngr);
    if (newcar == NULL)
    {
        if(!(newcar = (t_car*)malloc(sizeof(t_car))))
            safe_exit(mngr, MALLOC_ERROR);
    }
    ft_memcpy(newcar, car, sizeof(t_car));
    if (!ft_vecpush(mngr->cars, &newcar, sizeof(newcar)))
    	safe_exit(mngr, MALLOC_ERROR);
    if (op->op == 12)
        args.x = args.x % IDX_MOD;
    mngr->num_cars++;
    newcar->pos = get_addr_arena(car->pos + args.x);
    newcar->id = mngr->next_id++;
    newcar->eval_in = (short)(mngr->cycle % (MAX_OP_TIME + 1));
	tl_put(mngr, (short)(mngr->cycle % (MAX_OP_TIME + 1)), newcar);
	mngr->timeline[newcar->eval_in]->offset = FT_SIGN(mngr->timeline[newcar->eval_in]->offset)
	* newcar->id;
    if (mngr->flags & FLAG_V)
//		ft_printf("P    %d | {Blue}%s{eof} %d (%d)\n", car->id + 1, op->op
//	== OP_fork ? "fork" : "lfork", args.x,newcar->pos);
		ft_printf("P %4d | %s %d (%d)\n", car->id + 1,
			op->op == OP_fork ? "fork" : "lfork", args.x,newcar->pos);
}


void make_and_or_xor(t_mngr *mngr, t_car *car, t_t_op *op)
{
	t_int3	args;

	ft_bzero(&args, sizeof(t_int3));
	args.z = 1;
	if (get_args(mngr, car, op, &args))
	{
		if(op->op == OP_and)
			*(int*)car->regs[args.z].reg = (int)((unsigned int)args.x & (unsigned int)args.y);
		else if (op->op == OP_or)
			*(int*)car->regs[args.z].reg = (int)((unsigned int)args.x | (unsigned int)args.y);
		else if (op->op == OP_xor)
			*(int*)car->regs[args.z].reg = (int)((unsigned int)args.x ^ (unsigned int)args.y);
		car->carry = (char)(*(int *)car->regs[args.z].reg == 0);
		if (mngr->flags & FLAG_V)
        {
//			ft_printf("P    %d | {Blue}%s{eof} %d %d r%d\n", car->id + 1,
//					  op->op == OP_and ? "and" : op->op == OP_or ? "or" : "xor",
//					  args.x, args.y, args.z + 1);
//            ft_printf("test r1 = %d r2 = %d  res = %d \n",*(int*)car->regs[args.x].reg,*(int*)car->regs[args.y].reg,*(int*)car->regs[args.z].reg ); // test
			ft_printf("P %4d | %s %d %d r%d\n", car->id + 1,
					  op->op == OP_and ? "and" : op->op == OP_or ? "or" : "xor",
					  args.x, args.y, args.z + 1);
        }

	}
}

void make_aff(t_mngr *mngr, t_car *car,t_t_op *op)
{
    int arg1;

    (void)op;
    arg1 = mngr->arena[get_addr_arena(car->pos + (int)OP_BASE)] - 1;
    if (mngr->flags & FLAG_V)
    {
        ft_printf("P %4d | %s %d\n", car->id + 1, "aff",
        		arg1 + 1);
    }
    if (check_reg(arg1))
        write(STDOUT_FILENO, (char*)car->regs[arg1].reg, ARG_REG_S);
}

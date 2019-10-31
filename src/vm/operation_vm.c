/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_vm.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blomo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 15:41:07 by blomo             #+#    #+#             */
/*   Updated: 2019/10/31 21:20:54 by blomo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "corewar.h"
#include "checkop.h"

void	make_live(t_mngr *mngr, t_car *car, t_t_op *op)
{
	t_int3	args;
	int i;
	int mod_arg;

	i = 0;
	get_args(mngr, car, op, &args);
	mod_arg = ft_abs(args.x) - 1;
	if (args.x < 0 && mod_arg < MAX_PLAYERS && mngr->chmps[mod_arg])
	{
		mngr->winner = mod_arg;
		i = 1;
	}
	car->live_cycle = mngr->cycle;
	mngr->live_num++;
	if (mngr->flags & FLAG_V)
		print_live(mngr, car, i, args.x);
}

void	make_ld_lld(t_mngr *mngr, t_car *car, t_t_op *op)
{
	t_int3	args;
	int step;

	if (get_args(mngr, car, op, &args))
	{
		step = car->pos + (int)OP_BASE + IND_SIZE + (op->a1 == DIR_CODE) * 2;
		args.y = get_reg(mngr, &step);
		*(int *) car->regs[args.y].reg = args.x;
		car->carry = (char) (args.x == 0);
		if (mngr->flags & FLAG_V)
		{
            ft_printf("P    %d | {Blue}%s{eof} %d r%d\n", car->id + 1,
                      op->op == OP_ld ? "ld" : "lld", args.x, args.y + 1);
            ft_printf("for test reg %d =  %d\n",args.y + 1, *(int *) car->regs[args.y].reg); // proverka pravilno li zapisali znachenie v registr
        }
	}
}

void	make_st(t_mngr *mngr, t_car *car, t_t_op *op)
{
	t_int3 args;
	int step;

	step = car->pos + (int)OP_BASE;
	if (get_args(mngr, car, op, &args))
	{
		args.x = get_reg(mngr, &step);
		if (op->a2 == REG_CODE)
		{
			args.y = get_reg(mngr, &step);
			ft_memcpy(car->regs + args.y, car->regs + args.x,
					  sizeof(char) * REG_SIZE);
		}
		else
		{
			step = car->pos + args.y;
			copy_reg_to_arena(mngr, car, args.x, step);
		}
		if (mngr->flags & FLAG_V)
			print_st(car, args.x, args.y, op);
	}
}

void	make_add_sub(t_mngr *mngr, t_car *car, t_t_op *op)
{
	t_int3 arg;
	int res;
    int step;

    step = car->pos + (int)OP_BASE;
	arg.x = mngr->arena[get_addr_arena(step)] - 1;
    arg.y = mngr->arena[get_addr_arena(step + ARG_REG_S)] - 1;
    arg.z = mngr->arena[get_addr_arena(step + ARG_REG_S * 2)] - 1;
	if (check_reg(arg.x) && check_reg(arg.y) && check_reg(arg.z))
	{
		if (op->op == OP_add)
			res = *(int *)car->regs[arg.x].reg + *(int *)car->regs[arg.y].reg;
		else
			res = *(int *)car->regs[arg.x].reg - *(int *)car->regs[arg.y].reg;
		*(int *)car->regs[arg.z].reg = res;
		car->carry = (char)(res == 0);
        if (mngr->flags & FLAG_V)
        {
            ft_printf("P    %d | {Blue}%s{eof} r%d r%d r%d\n", car->id + 1,
                      op->op == OP_add ? "add" : "sub", arg.x + 1, arg.y + 1, arg.z + 1);
            ft_printf("test znacheniy r1 = %d, r2 = %d, res = %d i v r3 = %",*(int *)car->regs[arg.x].reg,*(int *)car->regs[arg.y].reg, res, *(int *)car->regs[arg.z].reg ); // test
        }
	}


}

void	make_zjmp(t_mngr *mngr, t_car *car, t_t_op *op)
{
	t_int3 args;
	get_args(mngr, car, op, &args);

	int l;    // test
	l = car->pos; // test
	args.x = args.x % IDX_MOD;
	if (car->carry == 1)
		car->pos = get_addr_arena(car->pos + args.x - 3);
    if (mngr->flags & FLAG_V)
    {
        ft_printf("P    %d | {Blue}%s{eof} %d %s\n", car->id + 1,"zjmp",
                  args.x, car->carry == 1 ? "OK" : "FAILED");
        ft_printf("test tek poz = %d i kyda pos = %d   +3 eto y tebya potom carpoz dobavit\n",l, car->pos ); // test kyda prygnyla
    }

}
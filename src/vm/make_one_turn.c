/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_one_turn.c                     +               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehugh-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 17:06:37 by ehugh-be          #+#    #+#             */
/*   Updated: 2019/11/06 18:38:08 by ehugh-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "checkop.h"

#define BYTE_OP (unsigned char)(mngr->arena[car->pos])
#define BYTE_CODE (unsigned char)(mngr->arena[(car->pos + 1) % MEM_SIZE])

void	handle_op(t_mngr *mngr, t_car *car, short cur_time)
{
	short ret;
	t_t_op	op;

	//if car moved previous turn aka op_code is 0
	// than read op and set corresponding values
	// and put in corresponding time
	// else
	// try to evaluate op, set op to 0 and move to next time frame
	op = (t_t_op){car->op_code, ARG1(BYTE_CODE), ARG2(BYTE_CODE), ARG3(BYTE_CODE)};
	if ((ret = check_op(&op)) > 0) //assuming that in case of invalid args car moves more than 1
	{
		get_op_func(op.op)(mngr, car, &op);
//		car->op_code = 0;
	}
	if (ret != -1 && mngr->flags & FLAG_V && (car->op_code != OP_zjmp || car->carry != 1))
		print_addr(mngr, car->pos, FT_ABS(ret));
	proceed_car(mngr, car, cur_time, ret);
}

static void set_max_id(t_vector *vec, int id)
{
	if (vec->offset < 0)
		vec->offset = id > -vec->offset ? -id : vec->offset;
	else if (id < vec->offset)
		vec->offset *= -1;
	else
		vec->offset = id;
}

#define TL_TO_PUT (mngr->timeline[time_to_put])
void proceed_car(t_mngr *mngr, t_car *car, short cur_time, int offset)
{
	short	time_to_put;

	time_to_put = (short)((cur_time + 1) % (MAX_OP_TIME + 1));
	if (offset == -1)
	{
		car->op_code = (char)mngr->arena[car->pos];
		if (car->op_code <= OP_aff && car->op_code >= OP_live)
			time_to_put = (short)((cur_time +
				get_op_info(car->op_code)->num_of_ticks - 1) % (MAX_OP_TIME + 1));
		else
			car->pos = (car->pos + 1) % MEM_SIZE;
	}
	else
	{
		car->op_code = 0;
		car->pos = (car->pos + ft_abs(offset)) % MEM_SIZE;
	}
	car->eval_in = time_to_put;
	tl_put(mngr, time_to_put, car);
	set_max_id(mngr->timeline[time_to_put], car->id);
}

void	make_one_turn(t_mngr *mngr)
{
	short	cur_time;

	cur_time = (short)(mngr->cycle % (MAX_OP_TIME + 1));
	if (!mngr->timeline[cur_time] || !mngr->timeline[cur_time]->len)
		return ;
	t_car **tmp = mngr->timeline[cur_time]->data;
	t_vector *tmp1 = mngr->timeline[cur_time];
	if ((int)mngr->timeline[cur_time]->offset < 0)
		mngr->timeline[cur_time] = vm_radixsort(mngr->timeline[cur_time], mngr->timeline[cur_time]->len /
			sizeof(void*), mngr);
	tl_car_iter(mngr, handle_op);
//	proceed_cars(mngr, cur_time);
}


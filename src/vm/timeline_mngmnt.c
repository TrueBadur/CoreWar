/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   timeline_mngmnt.c								  :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: blomo <marvin@42.fr>					   +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2019/10/14 21:42:20 by ehugh-be		  #+#	#+#			 */
/*   Updated: 2019/10/25 19:34:42 by blomo			###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "corewar.h"

void tl_put(t_mngr *mngr, short time, t_car *car)
{
	if (!mngr->timeline[time])
		if (!(mngr->timeline[time] = ft_vecinit(sizeof(void*) * CAR_ST_S)))
			safe_exit(mngr, MALLOC_ERROR);
	if(!(mngr->timeline[time] = ft_vecpush(mngr->timeline[time], &car,
			sizeof(void*))))
		safe_exit(mngr, MALLOC_ERROR);
}

void	tl_car_iter(t_mngr *mngr, void (*f)(t_mngr*, t_car*))
{
	t_car	**cars;
	int		i;
	int		cur_time;
	t_car	*tmp;

	cur_time = mngr->cycle % (MAX_OP_TIME + 1);
	t_vector *vec = mngr->timeline[cur_time];
	i = -1;
	while (++i < mngr->timeline[cur_time]->len / sizeof(void*))
	{
		cars = (t_car**)mngr->timeline[cur_time]->data;
		tmp = cars[i];
		if (cars[i]->eval_in > -1)
			f(mngr, cars[i]);
	}
}

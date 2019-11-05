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

void tl_put(t_mngr *mngr, short time, t_list_node *lst, int addlast)
{
	if (!mngr->timeline[time])
		if (!(mngr->timeline[time] = ft_lstinit()))
			safe_exit(mngr, MALLOC_ERROR);
	addlast ? ft_lstaddend(mngr->timeline[time], lst) : ft_lstadd(mngr->timeline[time], lst);
	if (mngr->timeline[time]->len && !mngr->timeline[time]->end)
		safe_exit(mngr, MALLOC_ERROR);
}

void	tl_car_iter(t_mngr *mngr, void (*f)(t_mngr*, t_car*))
{
	t_list_node *lst;
	t_car	   *car;

	lst = mngr->timeline[mngr->cycle % (MAX_OP_TIME + 1)]->begin;
	while (lst)
	{
		f(mngr, (t_car*)lst->content);
		lst = lst->next;
	}
}

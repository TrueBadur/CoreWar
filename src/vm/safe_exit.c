/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehugh-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 16:21:57 by ehugh-be          #+#    #+#             */
/*   Updated: 2019/10/14 22:47:35 by ehugh-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	del_time(t_list *lst)
{
	t_list_node	*cur;
	t_list_node	*tmp;

	if (!lst)
		return ;
	cur = lst->begin;
	while(cur)
	{
		tmp = cur->next;
		free(cur);
		cur = tmp;
	}
	free(lst);
}

static void	cleanup(t_mngr *mngr)
{
	int		i;

	i = -1;
	free(mngr->arena);
	if (mngr->cars)
		while (++i < mngr->cars->len / sizeof(void*))
			free(((t_car**)mngr->cars->data)[i]);
	ft_vecdel((void**)&mngr->cars);
	i = -1;
	while (++i < MAX_OP_TIME + 1)
		del_time(mngr->timeline[i]);
	//TODO free chmps
	free(mngr);
}

void		safe_exit(t_mngr *mngr, t_eexcode exit_code)
{
	if (mngr)
		cleanup(mngr);
	if (exit_code == MALLOC_ERROR)
		ft_printf(MALLOC_ERROR_MSG);
	exit(exit_code);
}

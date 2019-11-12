/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehugh-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 16:21:57 by ehugh-be          #+#    #+#             */
/*   Updated: 2019/11/11 17:03:29 by ehugh-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "error_msgs.h"

void		rm_chmp(t_chmp *chmp)
{
	if (!chmp)
		return ;
	if (chmp->name)
		free(chmp->name);
	if (chmp->moto)
		free(chmp->moto);
	if (chmp->code)
		free(chmp->code);
	free(chmp);
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
	if (mngr->dead_cars)
		while (++i < mngr->dead_cars->len / sizeof(void*))
			free(((t_car**)mngr->dead_cars->data)[i]);
	ft_vecdel((void**)&mngr->dead_cars);
	i = -1;
	while (++i < MAX_OP_TIME + 1)
		ft_vecdel((void**)&mngr->timeline[i]);
	i = -1;
	while (++i < MAX_PLAYERS)
		rm_chmp(mngr->chmps[i]);
	ft_vecdel((void**)&mngr->rxsort_out);
	free(mngr);
}

void		safe_exit(t_mngr *mngr, t_eexcode exit_code)
{
	if (mngr)
		cleanup(mngr);
	if (exit_code == MALLOC_ERROR)
		ft_printf(MALLOC_ERROR_MSG);
	else if (exit_code == TOO_MANY_CHMPS)
		ft_printf(TOO_MANY_CHAMPIONS_MSG);
	else if (exit_code == INVALID_N)
		ft_printf(INVALID_N_MSG);
	else if (exit_code == FEW_ARGUMENTS)
		ft_printf(FEW_ARGUMENTS_MSG);
	else if (exit_code == FEW_BYTE)
		ft_printf(FEW_BYTE_MSG);
	else if (exit_code == READ_ERROR)
		ft_printf(READ_ERROR_MSG);
	else if (exit_code == OPEN_ERROR)
		ft_printf(OPEN_ERROR_MSG);
	else if (exit_code == INVALID_EXEC_MAGIC)
		ft_printf(INVALID_EXEC_MAGIC_MSG);
	else if (exit_code == NO_ZERO_BYTE)
		ft_printf(NO_ZERO_BYTE_MSG);
	else if (exit_code == INVALID_SIZE_BYTE_CHAMPION)
		ft_printf(INVALID_SIZE_BYTE_CHAMPION_MSG);
	else if (exit_code == INVALID_FILE_EXTENSION)
		ft_printf(INVALID_FILE_EXTENSION_MSG);
	else if (exit_code == INVALID_ARRAY_CHAMPION)
		ft_printf(INVALID_ARRAY_CHAMPION_MSG);
	else if (exit_code == INVALID_ARGUMENT_NAME)
		ft_printf(INVALID_ARGUMENT_NAME_MSG);
	exit(exit_code);
}

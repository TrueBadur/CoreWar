/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blomo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 15:03:55 by blomo             #+#    #+#             */
/*   Updated: 2019/11/14 15:06:38 by blomo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		parse_dump(t_mngr *mngr, char **argv, int i)
{
	int		nbr;

	nbr = 0;
	argv[i][0] = '\0';
	if (!(argv[i + 1] != NULL && !ft_atoi_safe(argv[i + 1], &nbr) &&
	!(mngr->flags & FLAG_DUMP)))
		safe_exit(mngr, INVALID_N, NULL);
	mngr->flags = mngr->flags | FLAG_DUMP;
	mngr->dump_nbr = nbr;
	argv[i + 1][0] = '\0';
}

void		parse_v(t_mngr *mngr, char **argv, int i)
{
	argv[i][0] = '\0';
	if (!(mngr->flags & FLAG_V))
		mngr->flags = mngr->flags | FLAG_V;
	else
		safe_exit(mngr, INVALID_N, NULL);
}

void		parse_a(t_mngr *mngr, char **argv, int i)
{
	argv[i][0] = '\0';
	if (!(mngr->flags & FLAG_A))
		mngr->flags = mngr->flags | FLAG_A;
	else
		safe_exit(mngr, INVALID_N, NULL);
}

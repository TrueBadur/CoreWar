/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehugh-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 16:24:31 by ehugh-be          #+#    #+#             */
/*   Updated: 2019/10/11 16:39:57 by ehugh-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"
#include "corewar.h"

static t_mngr *init_mngr(void)
{
	t_mngr *mngr;

	if (!(mngr = ft_memalloc(sizeof(t_mngr))))
		safe_exit(mngr, MALLOC_ERROR);
	return (mngr);
}

static void	champion_introduce(t_mngr *mngr)
{
	ft_printf("Champ!\n");
}

static void	winer_anounce(t_mngr *mngr)
{
	ft_printf("Friendship wins!\n");
}

int main(int argc, char **argv)
{
	t_mngr *mngr;

	ft_printf("Hello");
	mngr = init_mngr();
	validate_input(mngr, argc, argv);
	init_arena(mngr);
	champion_introduce(mngr);
	game_main(mngr);
	winer_anounce(mngr);
	safe_exit(mngr, SUCCESS);
    return (0);
}
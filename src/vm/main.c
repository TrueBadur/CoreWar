/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blomo <blomo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 16:24:31 by ehugh-be          #+#    #+#             */
/*   Updated: 2019/10/14 10:04:41 by blomo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "corewar.h"


// static t_mngr *init_mngr(void)
// {
// 	t_mngr *mngr;

// 	if (!(mngr = ft_memalloc(sizeof(t_mngr))))
// 		safe_exit(mngr, MALLOC_ERROR);
// 	return (mngr);
// }




int main(int argc, char **argv)
{
	t_mngr *mngr;

	mngr = (t_mngr*)malloc(sizeof(t_mngr));
	mngr->chmps = (t_chmp*)malloc(sizeof(t_chmp));
	//mngr = init_mngr();

	validate_input(mngr, argc, argv);
	printf("%s\n",mngr->chmps->name);
	printf("%s\n",mngr->chmps->comment);
	//printf("%s\n",mngr->chmps->code);
	// init_arena(mngr);
	// champion_introduce(mngr);
	// game_main(mngr);
	// winer_anounce(mngr);
	// safe_exit(mngr, SUCCESS);
    return (0);
}

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

	mngr = (t_mngr*)malloc(sizeof(t_mngr));
	mngr->chmps[0] = NULL;
    mngr->chmps[1] = NULL;
    mngr->chmps[2] = NULL;
    mngr->chmps[3] = NULL;
	//mngr = init_mngr();
	validate_input(mngr, argc, argv);
	printf("%s\n",mngr->chmps[0]->name);
    printf("%s\n",mngr->chmps[1]->name);
    printf("%s\n",mngr->chmps[2]->name);
    printf("%s\n",mngr->chmps[3]->name);
//	printf("%s\n",mngr->chmps[0]->moto);
	//printf("%s\n",mngr->chmps->code);
	// init_arena(mngr);
	// champion_introduce(mngr);
	// game_main(mngr);
	// winer_anounce(mngr);
	// safe_exit(mngr, SUCCESS);
    return (0);
}

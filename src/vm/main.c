/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blomo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 16:24:31 by ehugh-be          #+#    #+#             */
/*   Updated: 2019/10/28 14:05:26 by blomo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "corewar.h"


 static t_mngr *init_mngr(void)
 {
 	t_mngr *mngr;

	if (!(mngr = ft_memalloc(sizeof(t_mngr))))
		safe_exit(mngr, MALLOC_ERROR);
	ft_bzero(mngr->timeline, (MAX_OP_TIME + 1) * sizeof(void*));
	return (mngr);
}

static void	champion_introduce(t_mngr *mngr)
{
 	int i;

 	i = -1;
	if (mngr->flags & FLAG_S)
		return ;
 	ft_printf("Introducing contestants...\n");
	while (++i < 4)
	{
		if (mngr->chmps[i])
			ft_printf("* Player %d, weighing %d bytes, \"%s\" (\"%s\") !\n", i + 1,
					mngr->chmps[i]->size, mngr->chmps[i]->name,mngr->chmps[i]->moto);
	}
}

static void	winer_anounce(t_mngr *mngr)
{
	if (!(mngr->flags & FLAG_S))
		ft_printf("Contestant %d. \"%s\", has won !\n", mngr->winner + 1, mngr->chmps[mngr->winner]->name);
}

#include <ncurses.h>
void	init_visu()
{
	initscr();
	keypad(stdscr, TRUE);
	noecho();
	start_color();
	init_pair(1, COLOR_WHITE, COLOR_BLACK);
	init_pair(2, COLOR_CYAN, COLOR_BLACK);
	init_pair(3, COLOR_GREEN, COLOR_BLACK);
	init_pair(4, COLOR_BLUE, COLOR_BLACK);
	init_pair(5, COLOR_RED, COLOR_BLACK);
	init_pair(6, COLOR_MAGENTA, COLOR_BLACK);
	border(0, 0, 0, 0, 0, 0, 0, 0);
	refresh();
}

int main(int argc, char **argv)
{
	t_mngr *mngr;

	init_visu();
	mngr = init_mngr();
	validate_input(mngr, argc, argv);
	init_arena(mngr);
	champion_introduce(mngr);
	game_main(mngr);
	winer_anounce(mngr);
	safe_exit(mngr, SUCCESS);
	endwin();
    return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blomo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 16:21:57 by ehugh-be          #+#    #+#             */
/*   Updated: 2019/11/15 18:04:17 by blomo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	rm_chmp(t_chmp *chmp)
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
	unsigned long	i;

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

void		print_help(void)
{
	ft_printf("Usage: ./corewar [-d N] [-v] [-g] [-n N  <champion1.cor>]"
	"[-a] <champion1.cor> <...>\n");
	ft_printf("    -a        : Prints output from \"aff\""
	"(Default is to hide it)\n");
	ft_printf("    -dump N      : Dumps memory after N cycles then exits\n");
	ft_printf("    -n N      : Set champion on Nth place\n");
	ft_printf("    -v        : Verbose output\n");
	ft_printf("    -s        : Ncurses output mode\n");
	ft_printf("   -h / --help: Print this message\n");
}

char		*get_err_str(t_eexcode code)
{
	static char *strs[] = {
			"",
			"{Red}Error: \n Memory allocation failed{eof}\n",
			"{Red}Error: \n Few arguments {eof}\n",
			"{Red}Error: \n Invalid flag: %s {eof}\n",
			"{Red}Error: \n Invalid n {eof}\n",
			"{Red}Error: \n Too many champions given. Make your choice!{eof}\n",
			"{Red}Error: \n Few byte in magic number {eof}\n",
			"{Red}Error: \n Read error {eof}\n",
			"{Red}Error: \n Open error {eof}\n",
			"{Red}Error: \n Invalid exec magic {eof}\n",
			"{Red}Error: \n No zero byte {eof}\n",
			"{Red}Error: \n Invalid size byte champion {eof}\n",
			"{Red}Error: \n Invalid file extension {eof}\n",
			"{Red}Error: \n Invalid array champion {eof}\n",
			"{Red}Error: \n Invalid argument name {eof}\n",
			"",
			""
	};

	return (strs[code]);
}

void		safe_exit(t_mngr *mngr, t_eexcode exit_code, const char *err_arg)
{
	if (mngr)
		cleanup(mngr);
	ft_printf(get_err_str(exit_code), err_arg);
	exit(exit_code);
}

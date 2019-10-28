/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blomo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 16:39:49 by ehugh-be          #+#    #+#             */
/*   Updated: 2019/10/23 19:26:54 by blomo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "limits.h"

int handle_n(t_mngr *mngr, char **argv, int i)
{
    int nbr;

    nbr = 0;
    argv[i][0] = '\0';

    if (argv[i + 1] != NULL && !ft_atoi_safe(argv[i + 1], &nbr))
    {
        if (!(nbr >= 1 && nbr <= MAX_PLAYERS))
            safe_exit(mngr, INVALID_N);
        nbr--;
    }
    else
        safe_exit(mngr, INVALID_N);
    if(argv[i + 2] != NULL)
        parse_file(argv[i + 2], mngr, nbr);
    else
        safe_exit(mngr, FEW_ARGUMENTS);
    argv[i + 1][0] = '\0';
    argv[i + 2][0] = '\0';
    return (2);
}

void parse_dump(t_mngr *mngr, char **argv, int i)
{
    int nbr;

    nbr = 0;
    argv[i][0] = '\0';
    if (argv[i + 1] != NULL && !ft_atoi_safe(argv[i + 1], &nbr) && !(mngr->flags & DUMP))
    {
        if (!(nbr >= 0 && nbr < INT_MAX))
            safe_exit(mngr, INVALID_N);
    }
    else
        safe_exit(mngr, INVALID_N);
    mngr->flags = mngr->flags | DUMP;
    mngr->dump_nbr = nbr;
    argv[i + 1][0] = '\0';
}

void parse_v(t_mngr *mngr, char **argv, int i)
{
    argv[i][0] = '\0';
    if (!(mngr->flags & V))
        mngr->flags = mngr->flags | V;
    else
        safe_exit(mngr, INVALID_N);
}

void parse_visu(t_mngr *mngr, char **argv, int i)
{
	argv[i][0] = '\0';
	if (!(mngr->flags & VIS))
		mngr->flags = mngr->flags | VIS;
	else
		safe_exit(mngr, INVALID_N);
}

void parse_flags(t_mngr *mngr, char **argv)
{
    int i;

    i = 0;
    while(argv[++i])
    {
        if (!ft_strcmp(argv[i], "-n"))
			i += handle_n(mngr, argv, i);
        if (!ft_strcmp(argv[i], "-dump"))
            parse_dump(mngr, argv, i);
        if (!(ft_strcmp(argv[i], "-v")))
            parse_v(mngr, argv ,i);
		if (!(ft_strcmp(argv[i], "-visu")))
			parse_visu(mngr, argv ,i);
    }
}
void check_players(t_mngr *mngr, char **argv, int argc)
{
    int i;
    int c;

    c = 0;
    i = 0;
    while(argc > ++i)
    {
        if(argv[i][0])
        {
            while(mngr->chmps[c] && c < MAX_PLAYERS)
                c++;
            if(c == MAX_PLAYERS)
                safe_exit(mngr, TOO_MANY_CHMPS);
			parse_file(argv[i], mngr, c);
        }
    }
}

void validate_input(t_mngr *mngr, int argc, char **argv)
{

    if(argc == 1)
        safe_exit(mngr, FEW_ARGUMENTS);
	parse_flags(mngr, argv);
    check_players(mngr,argv,argc);
}

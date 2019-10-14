/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehugh-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 16:39:49 by ehugh-be          #+#    #+#             */
/*   Updated: 2019/10/14 16:40:39 by ehugh-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void check_param_n(t_mngr *mngr, char **argv,int i)
{
    int nbr;

    nbr = 0;
    argv[i][0] = '\0';
    i++;
    if( argv[i] != NULL && (argv[i][0] >= '1' && argv[i][0] <= '4'))
    {
        nbr = ft_atoi(argv[i]) - 1;
        argv[i][0] = '\0';
    }
    else
        safe_exit(mngr, NOTVALIDN);
    if(argv[i+1] != NULL)
    {
        pars_file(argv[i+1], mngr, nbr);
        argv[i+1][0] = '\0';
    }
    else
        safe_exit(mngr, FEW_PARAMETR);
}

void check_pars(t_mngr *mngr, char **argv)
{
    int i;

    i = 1;
    while(argv[i])
    {
        if(!ft_strcmp(argv[i], "-n"))
           check_param_n(mngr,argv,i);
        i++;
    }
}
void check_players(t_mngr *mngr, char **argv, int argc)
{
    int i;
    int c;

    c = 0;
    i = 1;
    while(argc > i)
    {
        if(argv[i][0] != '\0')
        {
            while(mngr->chmps[c] != NULL && c < 4)
                c++;
            if(c == 4)
                safe_exit(mngr, FEW_PARAMETR);
            pars_file(argv[i], mngr, c);
        }
        i++;
    }
}

void validate_input(t_mngr *mngr, int argc, char **argv)
{
    int i;
    char **str;

    i = 1;
    if(argc == 1)
        safe_exit(mngr, FEW_PARAMETR);
    check_pars(mngr, argv);
    check_players(mngr,argv,argc);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehugh-be <ehugh-be@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 16:39:49 by ehugh-be          #+#    #+#             */
/*   Updated: 2019/11/13 20:34:21 by blomo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int			handle_n(t_mngr *mngr, char **argv, int i)
{
	int		nbr;

	nbr = 0;
	argv[i][0] = '\0';
	if (argv[i + 1] != NULL && !ft_atoi_safe(argv[i + 1], &nbr))
	{
		if (!(nbr >= 1 && nbr <= MAX_PLAYERS))
			safe_exit(mngr, INVALID_N, NULL);
		nbr--;
	}
	else
		safe_exit(mngr, INVALID_N, NULL);
	if (argv[i + 2] != NULL)
		parse_file(argv[i + 2], mngr, nbr);
	else
		safe_exit(mngr, FEW_ARGUMENTS, NULL);
	argv[i + 1][0] = '\0';
	argv[i + 2][0] = '\0';
	return (2);
}

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

void		parse_flags(t_mngr *mngr, char **argv)
{
	int		i;
	char	*cur;

	i = 0;
	while (argv[++i])
	{
		cur = argv[i];
		if (cur[0] == '-')
		{
			cur++;
			if (!ft_strcmp(cur, "n"))
				i += handle_n(mngr, argv, i);
			else if (!ft_strcmp(cur, "dump"))
				parse_dump(mngr, argv, i);
			else if (!(ft_strcmp(cur, "v")))
				parse_v(mngr, argv, i);
			else if (!(ft_strcmp(cur, "a")))
				parse_a(mngr, argv, i);
			else if (!(ft_strcmp(cur, "h")) ||
			!(ft_strcmp(cur, "-help")))
				safe_exit(mngr, HELP, cur);
			else
				safe_exit(mngr, INVALID_FLAG, cur);
		}
	}
}

void		check_players(t_mngr *mngr, char **argv, int argc)
{
	int		i;
	int		c;

	c = 0;
	i = 0;
	while (argc > ++i)
	{
		if (argv[i][0])
		{
			while (mngr->chmps[c] && c < MAX_PLAYERS)
				c++;
			if (c == MAX_PLAYERS)
				safe_exit(mngr, TOO_MANY_CHMPS, NULL);
			parse_file(argv[i], mngr, c);
		}
	}
}

void		validate_input(t_mngr *mngr, int argc, char **argv)
{
	if (argc == 1)
		safe_exit(mngr, HELP, NULL);
	parse_flags(mngr, argv);
	check_players(mngr, argv, argc);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_ofname.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleann <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 15:53:54 by jleann            #+#    #+#             */
/*   Updated: 2019/10/28 15:53:57 by jleann           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "read_args.h"
#include <stdlib.h>
#include "libstd.h"

char	*assemble_case(char *str)
{
	char	*res;
	size_t	size;

	size = ft_strlen(str) + 3;
	res = ft_memalloc(size);
	ft_strcat(res, str);
	res[size - 4] = 'c';
	res[size - 3] = 'o';
	res[size - 2] = 'r';
	return (res);
}

char	*disassemble_case(char *str)
{
	char	*res;
	size_t	size;

	size = ft_strlen(str) - 1;
	res = ft_memalloc(size);
	ft_strncat(res, str, size);
	res[size - 2] = 's';
	return (res);
}

void	create_ofname(t_argdata *args)
{
	if (!args->ofname)
	{
		if (args->flags.fassemble)
			args->ofname = (ft_strjoin(args->fname, ".cor"));
		else if (args->flags.fdisassemble)
			args->ofname = (ft_strjoin(args->fname, ".s"));
		else if (args->flags.ftype == 0)
			args->ofname = assemble_case(args->fname);
		else if (args->flags.ftype == 1)
			args->ofname = disassemble_case(args->fname);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleann <jleann@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 17:39:02 by jleann            #+#    #+#             */
/*   Updated: 2019/06/19 20:08:25 by jleann           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "read_args.h"
#include "assembler.h"
#include "disassembler.h"
#include <stdlib.h>

void	free_argdata(t_argdata *res)
{
	if (res->fname)
		free(res->fname);
	if (res->ofname)
		free(res->ofname);
	free(res);
}

int	main(int argc, char **argv)
{
	t_argdata	*args;

	args = read_args(argc, argv);
	if ((args->flags.ftype == 0 || args->flags.fassemble) && !args->flags.fdisassemble)
		assemble(args);
	else
		disassemble(args);
	free_argdata(args);
    return (0);
}

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

#include "arg_reader.h"
#include "assembler.h"
#include "disassembler.h"

int	main(int argc, char **argv)
{
	t_argdata	*args;

	args = read_args(argc, argv);
	if (args->flags.is_src)
		assemble(args);
	else
		disassemble(args);
	free_argdata(args);
    return (0);
}

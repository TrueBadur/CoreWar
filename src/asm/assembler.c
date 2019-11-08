/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assembler.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleann <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 18:24:50 by jleann            #+#    #+#             */
/*   Updated: 2019/10/26 18:24:50 by jleann           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "read_args.h"
#include "lexer.h"
#include "champ_generator.h"
#include "writer.h"

void	assemble(t_argdata *args)
{
	int			err;
	t_lexdata	*lexdata;
	t_champdata	*champdata;

	if ((err = run_lexer(args->fname, &lexdata)))
		exit(err);
	if (lexdata->debug_done)
	{
		ft_printf("run_lexer - ok\n");
		exit(0);
	}
	champdata = run_champgenerator(lexdata);
	write_champ(champdata, args);
	ft_printf("Writing output program to %s", args->ofname);
	free_lexdata(lexdata);
	free_champdata(champdata);
}

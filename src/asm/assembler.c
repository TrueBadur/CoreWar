//
// Created by Jasper Leann on 11/10/2019.
//

#include "ft_printf.h"
#include "read_args.h"
#include "lexer.h"
#include "champ_generator.h"
#include "writer.h"

void 	assemble(t_argdata *args)
{
	t_lexdata	*lexdata;
	t_champdata	*champdata;

	lexdata = run_lexer(args->fname);
	champdata = run_champgenerator(lexdata);
	write_champ(champdata, args);
	free_lexdata(lexdata);
	free_champdata(champdata);
}

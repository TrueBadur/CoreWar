/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleann <jleann@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 17:39:02 by jleann            #+#    #+#             */
/*   Updated: 2019/06/19 20:08:25 by jleann           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "read_args.h"
#include "ft_printf.h"

static void		raise_error(const char *str)
{
	ft_fdprintf(2, "asm: %s\n", str);
	ft_fdprintf(2, "%s", USAGE);
	exit(1);
}

static void		read_flags(t_argdata *args, char **argv,
							int *cur_arg, int arg_num)
{
	if (argv[*cur_arg][1] == 'd')
		args->flags.fdisassemble = 1;
	else if (argv[*cur_arg][1] == 'a')
		args->flags.fassemble = 1;
	else if (argv[*cur_arg][1] == 'o')
	{
		*cur_arg += 1;
		if (*cur_arg >= arg_num)
			raise_error(OUTPUT_FNAME_EXPECTED_ERR);
		args->ofname = ft_strdup(argv[*cur_arg]);
	}
	else
		raise_error(OUTPUT_FNAME_EXPECTED_ERR);
}

static void		check_for_conflict(t_argdata *args)
{
	if (args->flags.fassemble && args->flags.fdisassemble)
		raise_error(INCOMPATIBLE_ARG_COMB_ERR);
	if (args->fname == NULL)
		raise_error(NO_FILE_PROVIDED_ERR);
}

static void		check_extension(t_argdata *args)
{
	size_t ext_len;

	ext_len = ft_strlen(args->fname);
	if (ext_len > 4 && ft_strcmp(args->fname + ext_len - 4, ".cor") == 0)
		args->flags.ftype = 1;
	else if (ext_len > 2 && ft_strcmp(args->fname + ext_len - 2, ".s") == 0)
		args->flags.ftype = 0;
	else
		raise_error(INVALID_FILE_EXT_ERR);
}

t_argdata		*read_args(int argc, char **argv)
{
	t_argdata	*res;
	int			cur_arg;

	res = ft_memalloc(sizeof(t_argdata));
	cur_arg = 1;
	while (cur_arg < argc)
	{
		if (argv[cur_arg][0] == '-' && argv[cur_arg][1] != 0)
			read_flags(res, argv, &cur_arg, argc);
		else
			res->fname = ft_strdup(argv[cur_arg]);
		cur_arg++;
	}
	check_for_conflict(res);
	if (!res->flags.fdisassemble && !res->flags.fassemble)
		check_extension(res);
	create_ofname(res);
	return (res);
}

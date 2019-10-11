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

#include "ft_string.h"
#include "read_args.h"

t_argdata	*read_args(int argc, char **argv)
{
	t_argdata	*res;
	int 		cur_arg;

	res = ft_memalloc(sizeof(t_argdata));
	cur_arg = 1;
	while (cur_arg < argc)
	{
		if (argv[cur_arg][0] == '-')
			read_flags(res, argv[cur_arg] + 1);
		else
			read_file(res, argv[cur_arg] + 1);
		cur_arg++;
	}
	check_for_conflict(res);
}
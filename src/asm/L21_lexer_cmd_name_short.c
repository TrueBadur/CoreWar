/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   L21_lexer_cmd_name_short.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 17:39:02 by jleann            #+#    #+#             */
/*   Updated: 2019/10/15 19:28:34 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

int		short_name(t_lexdata *dat, char *start)
{
	int		idx;
	int		end;
	char	*out;

	ft_printf(">>>>>>>> num_node = %d\n", 0);
	end = -1;
	idx = 0;
	while (start[++idx] && end == -1)
	{
		if (end == -1 && start[idx] == ARG_CMD_START)
			end = idx;
	}
	//ft_printf("\tstart= %d\tend= %d\n", start, end);
	out = ft_strnew(end - 1);
	if (!out)
		return (ERROR_LEX_MALLOC_STR);
	ft_strncpy(out, start + 1, end - 1);
	dat->champ_name = out;
	debug_cmd_name(dat);
	return (0);
}
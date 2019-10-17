/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   L21_lexer_cmd_name_short.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 17:39:02 by jleann            #+#    #+#             */
/*   Updated: 2019/10/15 23:16:57 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

int		short_name(char *start, char **to_set)
{
	int		idx;
	int		end;
	char	*out;

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
	*to_set = out;
	return (0);
}
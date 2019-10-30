/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   n21_lexer_cmd_short.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 17:39:02 by wgorold           #+#    #+#             */
/*   Updated: 2019/10/30 18:21:47 by wgorold          ###   ########.fr       */
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
		if (start[idx] == ARG_CMD_START)
			end = idx;
	}
	out = ft_strnew(end - 1);
	if (!out)
		return (ERR_LEX__ID_MALLOC_STR);
	ft_strncpy(out, start + 1, end - 1);
	*to_set = out;
	return (0);
}

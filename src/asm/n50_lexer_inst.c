/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   n50_lexer_inst.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 17:39:02 by wgorold           #+#    #+#             */
/*   Updated: 2019/10/30 18:21:54 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

int		add_inst(t_lexdata *dat)
{
	t_op	*tab;
	int		idx;
	char	*line;
	int		tmp;

	idx = 0;
	line = dat->cur_line + dat->srt;
	tmp = dat->end - dat->srt;
	while ((tab = get_op_info(++idx)) && tab->name != NULL)
	{
		if (ft_strncmp(line, tab->name, tmp) == 0)
		{
			if ((tmp = add_token_data(dat, TOKEN_TYPE_INST, idx)))
				return (tmp);
			return (0);
		}
	}
	return (ERR_LEX__ID_INST_NOT_FOUND);
}

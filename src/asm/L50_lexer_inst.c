/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   L50_lexer_inst.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: PhilippNox <PhilippNox@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 17:39:02 by jleann            #+#    #+#             */
/*   Updated: 2019/10/17 10:51:07 by PhilippNox       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

int		set_data_inst(t_lexdata *dat, int id_inst)
{
	int				*data;

	data = (int *)malloc(sizeof(int));
	if (!data)
		return (ERROR_LEX_MALLOC);
	*data = id_inst;
	((t_token *)(dat->token_list.end->content))->data = data;
	return (0);
}

int		add_inst(t_lexdata *dat)
{
	int		idx;
	t_op 	*tab;
	char	*line;
	int		tmp;

	idx = 0;
	line = dat->cur_line + dat->srt;
	tmp = dat->end - dat->srt;
	while ((tab = get_op_info(++idx)))
	{
		if (ft_strncmp(line, tab->name, tmp) == 0)
		{
			//if ((tmp = add_token_inst(dat, idx)))
			//	return (tmp);
			if ((tmp = add_token(dat, INST_ID, 0, 0)))
				return (tmp);
			if ((tmp = set_data_inst(dat, idx)))
				return (tmp);
			return (0);
		}
	}
	return (ERROR_LEX_INST_NOT_FOUND);
}

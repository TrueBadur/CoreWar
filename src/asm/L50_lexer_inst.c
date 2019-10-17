/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   L50_lexer_inst.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: PhilippNox <PhilippNox@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 17:39:02 by jleann            #+#    #+#             */
/*   Updated: 2019/10/17 10:29:40 by PhilippNox       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

int		add_token_inst(t_lexdata *dat, int id_inst)
{
	t_token			to_add;
	t_list_node		*node;
	int				*data;

	data = (int *)malloc(sizeof(int));
	if (!data)
		return (ERROR_LEX_MALLOC);
	*data = id_inst;
	to_add.data = data;
	to_add.type = INST_ID;
	to_add.subtype = 0;
	to_add.line_num = (int)(dat->lines.len);
	to_add.pos_num = dat->srt;
	node = ft_lstnew_node(&to_add, sizeof(t_token));
	if (!node)
		return (ERROR_LEX_NULL_NODE);
	ft_lstaddend(&(dat->token_list), node);
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
			if ((tmp = add_token_inst(dat, idx)))
				return (tmp);
			return (0);
		}
	}
	return (ERROR_LEX_INST_NOT_FOUND);
}

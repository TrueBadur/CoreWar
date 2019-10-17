/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   L60_lexer_parm.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: PhilippNox <PhilippNox@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 17:39:02 by jleann            #+#    #+#             */
/*   Updated: 2019/10/17 10:29:38 by PhilippNox       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

int		add_token_parm_r(t_lexdata *dat, int id_r)
{
	t_token			to_add;
	t_list_node		*node;
	int				*data;

	data = (int *)malloc(sizeof(int));
	if (!data)
		return (ERROR_LEX_MALLOC);
	*data = id_r;
	to_add.data = data;
	to_add.type = PARAM_ID;
	to_add.subtype = PARAM_REG_ID;
	to_add.line_num = (int)(dat->lines.len);
	to_add.pos_num = dat->srt;
	node = ft_lstnew_node(&to_add, sizeof(t_token));
	if (!node)
		return (ERROR_LEX_NULL_NODE);
	ft_lstaddend(&(dat->token_list), node);
	return (0);
}

int		add_parm(t_lexdata *dat)
{
	char	*line;
	int		num;
	int		tmp;

	line = dat->cur_line + dat->srt;
	if (*line == 'r')
	{
		num = ft_atoi(line);
		if ((tmp = add_token_parm_r(dat, num)))
			return (tmp);
	}
	return (0);
}

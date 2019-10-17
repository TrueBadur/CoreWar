/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   L30_lexer_token.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: PhilippNox <PhilippNox@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 17:39:02 by jleann            #+#    #+#             */
/*   Updated: 2019/10/17 10:35:50 by PhilippNox       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

int		add_token(t_lexdata *dat, char type, char subtype)
{
	t_token			to_add;
	t_list_node		*node;

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
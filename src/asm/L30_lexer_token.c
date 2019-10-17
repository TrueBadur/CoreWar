/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   L30_lexer_token.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 17:39:02 by jleann            #+#    #+#             */
/*   Updated: 2019/10/17 15:06:35 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

int		add_token(t_lexdata *dat, char type, char sub_type, char val_type)
{
	t_token			to_add;
	t_list_node		*node;

	to_add.type = type;
	to_add.sub_type = sub_type;
	to_add.val_type = val_type;
	to_add.line_num = (int)(dat->lines.len);
	to_add.pos_num = dat->srt;
	node = ft_lstnew_node(&to_add, sizeof(t_token));
	if (!node)
		return (ERROR_LEX_NULL_NODE);
	ft_lstaddend(&(dat->token_list), node);
	return (0);
}

int		add_token_sep(t_lexdata *dat)
{
	t_token			to_add;
	t_list_node		*node;

	to_add.type = DELIM_ID;
	to_add.sub_type = 0;
	to_add.val_type = 0;
	to_add.line_num = (int)(dat->lines.len);
	to_add.pos_num = dat->srt;
	node = ft_lstnew_node(&to_add, sizeof(t_token));
	if (!node)
		return (ERROR_LEX_NULL_NODE);
	ft_lstaddend(&(dat->token_list), node);
	return (0);
}

int		add_token_endline(t_lexdata *dat)
{
	t_token			to_add;
	t_list_node		*node;

	to_add.type = END_ID;
	to_add.sub_type = 0;
	to_add.val_type = 0;
	to_add.line_num = (int)(dat->lines.len);
	to_add.pos_num = dat->srt;
	node = ft_lstnew_node(&to_add, sizeof(t_token));
	if (!node)
		return (ERROR_LEX_NULL_NODE);
	ft_lstaddend(&(dat->token_list), node);
	return (0);
}
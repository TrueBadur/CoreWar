/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   n30_lexer_token.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 17:39:02 by wgorold           #+#    #+#             */
/*   Updated: 2019/10/30 18:21:50 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

int		get_label_idx(void)
{
	static	int label_idx;

	label_idx += 1;
	return (label_idx - 1);
}

int		add_token(t_lexdata *dat, char token_type, int data, char *label)
{
	t_token			to_add;
	t_list_node		*node;

	to_add.token_type = token_type;
	to_add.type = 0;
	to_add.sub_type = 0;
	to_add.val_type = 0;
	process_token_type(token_type,
			&to_add.type, &to_add.sub_type, &to_add.val_type);
	to_add.line_num = (int)(dat->lines.len);
	to_add.pos_num = dat->srt;
	to_add.data = data;
	to_add.label = label;
	node = ft_lstnew_node(&to_add, sizeof(t_token));
	if (!node)
		return (ERR_LEX__ID_NULL_NODE);
	ft_lstaddend(&(dat->token_list), node);
	return (0);
}

int		add_token_nodata(t_lexdata *dat, char token_type)
{
	int	err;

	if ((err = add_token(dat, token_type, 0, NULL)))
		return (err);
	return (0);
}

int		add_token_data(t_lexdata *dat, char token_type, int data)
{
	int	err;

	if ((err = add_token(dat, token_type, data, NULL)))
		return (err);
	return (0);
}

int		add_token_str(t_lexdata *dat, char token_type, char *label)
{
	int			err;
	t_list_node	*node;

	if (token_type == TOKEN_TYPE_LABEL)
	{
		if ((err = add_token(dat, token_type, get_label_idx(), label)))
			return (err);
		node = ft_lstnew_node(NULL, 0);
		if (!node)
			return (ERR_LEX__ID_NULL_NODE);
		node->content = dat->token_list.end->content;
		ft_lstaddend(&(dat->label_list), node);
	}
	else
	{
		if ((err = add_token(dat, token_type, -1, label)))
			return (err);
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   n70_lexer_clear.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 17:39:02 by wgorold           #+#    #+#             */
/*   Updated: 2019/10/30 18:21:56 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

/*
**	to_clean
**		champ_name
**		champ_comment
**		label_list (only_nodes)
**		token_list
**		lines
**		t_lexdata *dat
*/

void	clear_token(t_lexdata *dat)
{
	t_list_node	*node;
	t_list_node	*node_nxt;
	t_token		*tkn;

	node = dat->label_list.begin;
	while (node)
	{
		node_nxt = node->next;
		free(node);
		node = node_nxt;
	}
	node = dat->token_list.begin;
	while (node)
	{
		node_nxt = node->next;
		tkn = (t_token *)(node->content);
		if (tkn->label)
			free(tkn->label);
		free(node->content);
		free(node);
		node = node_nxt;
	}
}

int		clean_n_exit(t_lexdata *dat, int err)
{
	t_list_node	*node;
	t_list_node	*node_nxt;

	if (err)
		print_error(dat, err);
	if (dat->champ_name)
		free(dat->champ_name);
	if (dat->champ_comment)
		free(dat->champ_comment);
	clear_token(dat);
	node = dat->lines.begin;
	while (node)
	{
		node_nxt = node->next;
		free(node->content);
		free(node);
		node = node_nxt;
	}
	free(dat);
	return (err);
}

void	free_lexdata(t_lexdata *data)
{
	clean_n_exit(data, 0);
}

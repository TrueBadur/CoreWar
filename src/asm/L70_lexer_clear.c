/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   L70_lexer_clear.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 17:39:02 by jleann            #+#    #+#             */
/*   Updated: 2019/10/17 16:30:17 by wgorold          ###   ########.fr       */
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

void		print_error(t_lexdata *dat, int err)
{
	if (err == ERR_LEX__ID_NOT_LABEL_CHAR)
		ft_printf(LEX_ERR_MSG_NOT_LABEL_CHAR, dat->end - dat->srt,
				  dat->cur_line + dat->srt, dat->cur_line[dat->cur_idx]);
}

int 	clean_n_exit(t_lexdata *dat, int err)
{
	t_list_node *node;
	t_list_node *node_nxt;
	t_token		*tkn;

	print_error(dat, err);
	if (dat->champ_name)
		free(dat->champ_name);
	if (dat->champ_comment)
		free(dat->champ_comment);

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

void		free_lexdata(t_lexdata *data)
{
	(void)data;
}

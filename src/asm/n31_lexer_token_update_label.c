/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   L30_lexer_token.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 17:39:02 by wgorold           #+#    #+#             */
/*   Updated: 2019/10/30 13:50:28 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

void	clean_all_label(t_lexdata *dat)
{
	t_list_node *node;
	t_list_node pseudo_srt;
	t_token		*tkn;

	pseudo_srt.next = dat->token_list.begin;
	if (pseudo_srt.next == NULL)
		return ;
	node = &pseudo_srt;
	while ((node = node->next))
	{
		tkn = (t_token *)(node->content);
		if (tkn->token_type == TOKEN_TYPE_P_D_L
			|| tkn->token_type == TOKEN_TYPE_P_I_L
			|| tkn->token_type == TOKEN_TYPE_LABEL)
		{
			free(tkn->label);
			tkn->label = NULL;
		}
	}
}

int		get_idx_label(t_lexdata *dat, char *label)
{
	t_list_node *node;
	t_list_node pseudo_srt;
	char		*ref;

	pseudo_srt.next = dat->label_list.begin;
	if (pseudo_srt.next == NULL)
		return (-1);
	node = &pseudo_srt;
	while ((node = node->next))
	{
		ref = ((t_token *)(node->content))->label;
		if (ft_strcmp(label, ref) == 0)
			return (((t_token *)(node->content))->data);
	}
	return (-1);
}

int		update_label(t_lexdata *dat)
{
	t_list_node *node;
	t_list_node pseudo_srt;
	t_token		*tkn;
	int			tmp;

	pseudo_srt.next = dat->token_list.begin;
	node = &pseudo_srt;
	while ((node = node->next))
	{
		tkn = (t_token *)(node->content);
		if (tkn->token_type == TOKEN_TYPE_P_D_L
			|| tkn->token_type == TOKEN_TYPE_P_I_L)
		{
			dat->cur_line = tkn->label;
			dat->err_line = tkn->line_num;
			dat->srt = tkn->pos_num;
			tmp = get_idx_label(dat, tkn->label);
			if (tmp < 0)
				return (ERR_LEX__ID_LABEL_UPDATE);
			tkn->data = tmp;
		}
	}
	dat->labels_num = dat->label_list.len;
	return (0);
}

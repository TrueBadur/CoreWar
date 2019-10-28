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

int		get_label_idx()
{
	static	int label_idx;

	label_idx += 1;
	return (label_idx - 1);
}

void	process_token_type(char tkn_typ, char *type, char *sub, char *val)
{
	if (tkn_typ == 		TOKEN_TYPE_INST)
		*type = INST_ID;
	else if (tkn_typ == TOKEN_TYPE_DELIM)
		*type = DELIM_ID;
	else if (tkn_typ == TOKEN_TYPE_END)
		*type = ENDL_ID;
	else if (tkn_typ == TOKEN_TYPE_LABEL)
		*type = LABEL_ID;
	else if (tkn_typ == TOKEN_TYPE_P_R)
	{
		*type = PARAM_ID;
		*sub = PARAM_REG_ID;
	}
	else if (tkn_typ == TOKEN_TYPE_P_D_I)
	{
		*type = PARAM_ID;
		*sub = PARAM_DIR_ID;
		*val = PARAM_INT;
	}
	else if (tkn_typ == TOKEN_TYPE_P_I_I)
	{
		*type = PARAM_ID;
		*sub = PARAM_IND_ID;
		*val = PARAM_INT;
	}
	else if (tkn_typ == TOKEN_TYPE_P_D_L)
	{
		*type = PARAM_ID;
		*sub = PARAM_DIR_ID;
		*val = PARAM_LABEL;
	}
	else if (tkn_typ == TOKEN_TYPE_P_I_L)
	{
		*type = PARAM_ID;
		*sub = PARAM_IND_ID;
		*val = PARAM_LABEL;
	}
	else
		ft_printf("process_token_type failed: token_type=%d\n", tkn_typ);
}

int		add_token(t_lexdata *dat, char token_type, int data, char *label)
{
	t_token			to_add;
	t_list_node		*node;
	(void) label;

	to_add.token_type = token_type;
	to_add.type = 0;
	to_add.sub_type = 0;
	to_add.val_type = 0;
	process_token_type(token_type,
			&to_add.type,&to_add.sub_type, &to_add.val_type);

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
		// for label idx. Check func update_label
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
	char 		*ref;

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

int     update_label(t_lexdata *dat)
{
	t_list_node *node;
	t_list_node pseudo_srt;
	t_token		*tkn;
	int 		tmp;

	pseudo_srt.next = dat->token_list.begin;
	if (pseudo_srt.next == NULL)
		return (0);

	node = &pseudo_srt;
	while ((node = node->next))
	{
		tkn = (t_token *)(node->content);
		if (tkn->token_type == TOKEN_TYPE_P_D_L || tkn->token_type == TOKEN_TYPE_P_I_L)
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
	//clean_all_label(dat);
	return (0);
}

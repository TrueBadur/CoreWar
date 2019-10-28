/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   L11_lexer_debug_token.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 17:39:02 by jleann            #+#    #+#             */
/*   Updated: 2019/10/17 16:36:57 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

char*	back_str_type(int id_label)
{
	if (id_label == LABEL_ID)
		return "LABEL_ID";
	if (id_label == INST_ID)
		return "INST_ID";
	if (id_label == PARAM_ID)
		return "PARAM_ID";
	if (id_label == DELIM_ID)
		return "DELIM_ID";
	if (id_label == ENDL_ID)
		return "ENDL_ID";
	return (NULL);
}

char*	back_str_sub_type(int id_label)
{
	if (id_label == PARAM_REG_ID)
		return "PARAM_REG_ID";
	if (id_label == PARAM_DIR_ID)
		return "PARAM_DIR_ID";
	if (id_label == PARAM_IND_ID)
		return "PARAM_IND_ID";
	return (NULL);
}

char*	back_str_val_type(int id_label)
{
	if (id_label == PARAM_LABEL)
		return "PARAM_LABEL";
	if (id_label == PARAM_INT)
		return "PARAM_INT";
	return (NULL);
}

void	print_data(void *data, int type, int val_type)
{
	if (val_type == PARAM_LABEL)
		ft_printf("\t\t\t\t\tdata=      %s\n", (char *)(data));
	else if (val_type == PARAM_INT)
		ft_printf("\t\t\t\t\tdata=      %d\n", *(int *)(data));
	else if (type == LABEL_ID)
		ft_printf("\t\t\t\t\tdata=      %s\n", (char *)(data));
	else if (type == INST_ID)
		ft_printf("\t\t\t\t\tdata=      %s %d\n",
			get_op_info(*((int *)(data)))->name, *(int *)(data));
	else if (type == PARAM_ID)
		ft_printf("\t\t\t\t\tdata=      %d\n", *(int *)(data));
}

void	debug_token(t_token *tkn, int idx)
{
	ft_printf("node=%2d\n", idx);
	ft_printf("\ttype=     %2d %s\n",  tkn->type, back_str_type(tkn->type));
	ft_printf("\tsub_type= %2d %s\n", tkn->sub_type, back_str_sub_type(tkn->sub_type));
	ft_printf("\tval_type= %2d %s\n", tkn->val_type, back_str_val_type(tkn->val_type));
	ft_printf("\t[%2d, %2d]\n", tkn->line_num, tkn->pos_num);
	ft_printf("\tdata   =  %2d\n", tkn->data);
	ft_printf("\tlabel  =  %s\n", tkn->label);
	ft_printf("\n");
}

void	debug_token_list(t_lexdata *dat)
{
	t_list_node *node;
	t_token		*tkn;
	int idx;

	idx = 0;
	node = dat->token_list.begin;
	while (node)
	{
		tkn = (t_token *)(node->content);
		debug_token(tkn, idx);
		node = node->next;
		idx += 1;
	}
}

void	debug_label_list(t_lexdata *dat)
{
	t_list_node *node;
	t_token		*tkn;
	int idx;

	idx = 0;
	node = dat->label_list.begin;
	while (node)
	{
		tkn = (t_token *)(node->content);
		debug_token(tkn, idx);
		node = node->next;
		idx += 1;
	}
}

//void	print_error(int err_id, char *str, ...)
//{
//	ft_printf(str, ...);
//	return (err_id);
//}
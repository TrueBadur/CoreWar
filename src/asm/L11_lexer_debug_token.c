/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   L11_lexer_debug_token.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: PhilippNox <PhilippNox@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 17:39:02 by jleann            #+#    #+#             */
/*   Updated: 2019/10/17 10:51:39 by PhilippNox       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

char*	back_to_str_label(int id_label)
{
	if (id_label == LABEL_ID)
		return "LABEL_ID";
	if (id_label == INST_ID)
		return "INST_ID";
	if (id_label == PARAM_ID)
		return "PARAM_ID";
	return (NULL);
}

void	print_data(void *data, int type)
{
	if (type == LABEL_ID)
		ft_printf("\tdata=      %s\n", (char *)(data));
	if (type == INST_ID)
		ft_printf("\tdata=      %s %d\n",
			get_op_info(*((int *)(data)))->name, *(int *)(data));
	if (type == PARAM_ID)
		ft_printf("\tdata=      %d\n", *(int *)(data));
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
		ft_printf("node=%2d\n", idx);
		ft_printf("\ttype=      %s %2d\n", back_to_str_label(tkn->type), tkn->type);
		ft_printf("\tsub_type= %2d\n", tkn->sub_type);
		ft_printf("\tline_num= %2d\n", tkn->line_num);
		ft_printf("\tpos_num=  %2d\n", tkn->pos_num);
		print_data(tkn->data, tkn->type);
		ft_printf("\n");
		node = node->next;
		idx += 1;
	}
}
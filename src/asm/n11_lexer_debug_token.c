/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   n11_lexer_debug_token.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 17:39:02 by wgorold           #+#    #+#             */
/*   Updated: 2019/10/30 18:21:43 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

void	debug_token(t_token *tkn, int idx)
{
	ft_printf("node=%2d\n", idx);
	ft_printf("\ttype=     %2d %s\n", tkn->type, back_str_type(tkn->type));
	ft_printf("\tsub_type= %2d %s\n", tkn->sub_type,
			back_str_sub_type(tkn->sub_type));
	ft_printf("\tval_type= %2d %s\n", tkn->val_type,
			back_str_val_type(tkn->val_type));
	ft_printf("\t[%2d, %2d]\n", tkn->line_num, tkn->pos_num);
	ft_printf("\tdata   =  %2d\n", tkn->data);
	ft_printf("\tlabel  =  %s\n", tkn->label);
	ft_printf("\n");
}

void	debug_token_list(t_lexdata *dat)
{
	t_list_node *node;
	t_token		*tkn;
	int			idx;

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
	int			idx;

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

void	debug_rest(t_lexdata *dat, char *line, int idx)
{
	if (dat->debug_happend)
		ft_printf("rest=%s\n", line + idx);
}

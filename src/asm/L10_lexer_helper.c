/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   L10_lexer_helper.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 17:39:02 by jleann            #+#    #+#             */
/*   Updated: 2019/10/16 18:22:51 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

int		add_line(t_lexdata *dat, char *line)
{
	t_list_node	*node;

	if (dat->debug_gnl)
		ft_printf("gnl = %s\n", line);
	node = ft_lstnew_node(NULL, 0);
	if (!node)
		return (ERROR_LEX_NULL_NODE);
	node->content = line;
	ft_lstaddend(&(dat->lines), node);
	return (0);
}

int		error_case(t_lexdata *dat, int error_case)
{
	(void)dat;
	return (error_case);
}

int		allowed_char(char cur)
{
	if (cur == ' ')
		return (1);
	if (cur == '\t')
		return (1);
	return (0);
}

int		not_skip_char(char cur)
{
	if (cur == ' ')
		return (0);
	if (cur == '\t')
		return (0);
	return (1);
}

int		end_line(char cur)
{
	if (cur == '\0')
		return (1);
	return (0);
}

int		check_comment(t_lexdata *dat, char *cur)
{
	if (*cur == COMMENT_CHAR)
	{
		if (dat->debug_comment)
			ft_printf("\t ✂️  ✂️  ✂️  ✂️  COMMENT_CHAR=%s\n", cur);
		return (1);
	}
	return (0);
}

void	debug_cmd_name(t_lexdata *dat, int id_cmd)
{
	if (dat->debug_name == 0)
		return ;
	if (id_cmd == 1)
		ft_printf("\t 🗣  🗣️  🗣️  🗣️  NAME=\n\"%s\"\n",
			dat->champ_name, ft_strlen(dat->champ_name));
	if (id_cmd == 2)
		ft_printf("\t 🗣  🗣️  🗣️  🗣️  COMM=\n\"%s\"\n",
			dat->champ_comment, ft_strlen(dat->champ_comment));
}

void	free_list(t_list *lst)
{
	t_list_node *node;
	t_list_node *to_free;

	node = lst->begin;
	while (node)
	{
		to_free = node;
		node = node->next;
		free(to_free);
	}
}

char*	back_to_str_label(int id_label)
{
	if (id_label == LABEL_ID)
		return "LABEL_ID";
	return (NULL);
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
		ft_printf("\tsubtype=  %2d\n", tkn->subtype);
		ft_printf("\tline_num= %2d\n", tkn->line_num);
		ft_printf("\tpos_num=  %2d\n", tkn->pos_num);
		if (tkn->type == LABEL_ID)
			ft_printf("\tdata=      %s\n", (char *)(tkn->data));
		ft_printf("\n");
		node = node->next;
		idx += 1;
	}
}
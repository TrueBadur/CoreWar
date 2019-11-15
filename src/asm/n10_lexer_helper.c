/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   n10_lexer_helper.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 17:39:02 by wgorold           #+#    #+#             */
/*   Updated: 2019/10/30 18:21:42 by wgorold          ###   ########.fr       */
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
		return (ERR_LEX__ID_NULL_NODE);
	node->content = line;
	ft_lstaddend(&(dat->lines), node);
	dat->cur_line = line;
	return (0);
}

int		check_comment(t_lexdata *dat, char *cur)
{
	if (*cur == COMMENT_CHAR || *cur == COMMENT_CHAR_ADV)
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

void	free_nodes_list(t_list *lst)
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

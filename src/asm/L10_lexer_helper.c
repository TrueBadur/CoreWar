/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   L10_lexer_helper.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 17:39:02 by jleann            #+#    #+#             */
/*   Updated: 2019/10/15 21:27:35 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <libstd.h>
#include "lexer.h"

int		get_fd(char *fname)
{
	int fd;

	if (fname && (fd = open(fname, O_RDONLY)) > 0)
		return (fd);
	return (0);
}

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

void	debug_cmd_name(t_lexdata *dat)
{
	if (dat->debug_name)
		ft_printf("\t 🗣  🗣️  🗣️  🗣️  NAME=\n\"%s\"\n",
			dat->champ_name, ft_strlen(dat->champ_name));
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
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   L30_lexer_label.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 17:39:02 by jleann            #+#    #+#             */
/*   Updated: 2019/10/16 15:12:02 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <libstd.h>
#include "lexer.h"

// TO_THINK maybe convert array to digits interval
int		not_label_char(char to_test)
{
	char *start;

	start = LABEL_CHARS;
	while (*start)
	{
		if (to_test == *start)
			return (0);
		start += 1;
	}
	return (1);
}

int		add_label(t_lexdata *dat)
{
	int				idx;
	t_token			to_add;
	t_list_node		*node;
	char			*data;

	idx = dat->end;
	while (--idx >= dat->srt)
	{
		if (not_label_char(dat->cur_line[idx]))
			return (ERROR_LEX_NOT_LABEL_CHAR);
	}
	
	data = ft_strnew(dat->end - dat->srt);
	if (!data)
		return (ERROR_LEX_MALLOC_STR);
	ft_strncpy(data, dat->cur_line + dat->srt, dat->end - dat->srt);
	to_add.data = data;
	to_add.type = LABEL_ID;
	to_add.subtype = 0;
	to_add.line_num = dat->lines.end->content_size;
	to_add.pos_num = dat->srt;
	node = ft_lstnew_node(&to_add, sizeof(t_token *));
	if (!node)
		return (ERROR_LEX_NULL_NODE);
	ft_lstaddend(&(dat->token_list), node);
	return (0);
}

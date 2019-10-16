/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   L30_lexer_label.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 17:39:02 by jleann            #+#    #+#             */
/*   Updated: 2019/10/16 17:08:00 by wgorold          ###   ########.fr       */
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

void	debug_add_label(t_token *tkn)
{
	ft_printf("node_ADD\n");
	ft_printf("\ttype= %2d\n", tkn->type );
	ft_printf("\tsubtype= %2d\n", tkn->subtype);
	ft_printf("\tline_num= %2d\n", tkn->line_num);
	ft_printf("\tpos_num= %2d\n", tkn->pos_num);
	ft_printf("\tdata= %s\n", tkn->data);
}

//TO_DO check len. must be len > 0
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
	//ft_printf("\tft_strnew: start= %d \t end= %d\n", dat->srt, dat->end );
	data = ft_strnew(dat->end - dat->srt);
	if (!data)
		return (ERROR_LEX_MALLOC_STR);
	ft_strncpy(data, dat->cur_line + dat->srt, dat->end - dat->srt);
	to_add.data = data;
	to_add.type = LABEL_ID;
	to_add.subtype = 0;
	to_add.line_num = (int)(dat->lines.end->content_size);
	to_add.pos_num = dat->srt;
	//debug_add_label(&to_add);
	node = ft_lstnew_node(&to_add, sizeof(t_token));
	if (!node)
		return (ERROR_LEX_NULL_NODE);
	ft_lstaddend(&(dat->token_list), node);
	return (0);
}

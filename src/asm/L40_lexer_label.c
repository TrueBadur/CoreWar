/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   L40_lexer_label.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: PhilippNox <PhilippNox@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 17:39:02 by jleann            #+#    #+#             */
/*   Updated: 2019/10/17 10:51:17 by PhilippNox       ###   ########.fr       */
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
	ft_printf("\tsub_type= %2d\n", tkn->sub_type);
	ft_printf("\tline_num= %2d\n", tkn->line_num);
	ft_printf("\tpos_num= %2d\n", tkn->pos_num);
	ft_printf("\tdata= %s\n", tkn->data);
}

//TO_DO check len. must be len > 0
int		add_label(t_lexdata *dat)
{
	int		idx;
	int		tmp;
	char	*data;

	if (dat->srt == dat->end)
		return (ERR_LEX__ID_LABEL_EMPTY);

	idx = dat->end;
	while (--idx >= dat->srt)
	{
		dat->cur_idx = idx;
		if (not_label_char(dat->cur_line[idx]))
			return (ERR_LEX__ID_NOT_LABEL_CHAR);
	}

	data = ft_strnew(dat->end - dat->srt);
	if (!data)
		return (ERR_LEX__ID_MALLOC_STR);
	ft_strncpy(data, dat->cur_line + dat->srt, dat->end - dat->srt);

	if ((tmp = add_token_str(dat, TOKEN_TYPE_LABEL, data)))
		return (tmp);
	return (0);
}
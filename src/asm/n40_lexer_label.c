/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   n40_lexer_label.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 17:39:02 by wgorold           #+#    #+#             */
/*   Updated: 2019/10/30 18:21:53 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

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
			return (ERR_LEX__ID_NO_LAB_CHAR);
	}
	data = ft_strnew(dat->end - dat->srt);
	if (!data)
		return (ERR_LEX__ID_MALLOC_STR);
	ft_strncpy(data, dat->cur_line + dat->srt, dat->end - dat->srt);
	if ((tmp = add_token_str(dat, TOKEN_TYPE_LABEL, data)))
		return (tmp);
	return (0);
}

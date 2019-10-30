/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   L80_lexer_check_line_job.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 17:39:02 by wgorold           #+#    #+#             */
/*   Updated: 2019/10/30 13:50:50 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

int		choice_cmd(t_lexdata *dat, char *line)
{
	char	*cur;
	int		rls;

	rls = ERR_LEX__ID_UNDEFINE_CMD;
	if ((cur = ft_strstr(line, NAME_CMD_STRING)))
		rls = process_cmd(dat, cur + ft_strlen(NAME_CMD_STRING), CMD_ID_NAME);
	else if ((cur = ft_strstr(line, COMMENT_CMD_STRING)))
		rls = process_cmd(dat, cur + ft_strlen(COMMENT_CMD_STRING),
		CMD_ID_COMMENT);
	return (rls);
}

int		do_comment(t_lexdata *dat)
{
	int err;

	if (dat->debug_happend)
		ft_printf("\t\t\t\t\t\t\t\thappend= comment\n");
	if ((err = add_token_nodata(dat, TOKEN_TYPE_END)))
		return (err);
	if (dat->debug_happend)
		ft_printf("\t\t\t\t\t\t\t\thappend= %s\n", "endline_token");
	return (0);
}

int		do_sepr(t_lexdata *dat, int idx)
{
	int err;

	dat->srt = idx;
	if ((err = add_token_nodata(dat, TOKEN_TYPE_DELIM)))
		return (err);
	if (dat->debug_happend)
		ft_printf("\t\t\t\t\t\t\t\thappend= %s\n", "sep_token");
	dat->srt = -1;
	return (0);
}

int		do_endline(t_lexdata *dat)
{
	int		err;

	if ((err = add_token_nodata(dat, TOKEN_TYPE_END)))
		return (err);
	if (dat->debug_happend)
		ft_printf("\t\t\t\t\t\t\t\thappend= %s\n", "endline_token");
	return (0);
}

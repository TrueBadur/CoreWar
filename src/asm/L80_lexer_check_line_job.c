/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   L70_lexer_clear.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 17:39:02 by jleann            #+#    #+#             */
/*   Updated: 2019/10/17 16:30:17 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"


int		choice_cmd(t_lexdata *dat, char *line)
{
	char	*cur;
	int		rls;

	// TODO if something before .name (labe: .name "_name_")
//	if (dat->srt != -1)
//	{
//		ft_printf(LEX_ERR_MSG_BEFORE_CMD);
//		return (ERR_LEX__ID_BEFORE_CMD);
//	}
	rls = ERR_LEX__ID_UNDEFINE_CMD;
	if ((cur = ft_strstr(line, NAME_CMD_STRING)))
		rls = process_cmd(dat, cur + ft_strlen(NAME_CMD_STRING), CMD_ID_NAME);
	else if ((cur = ft_strstr(line, COMMENT_CMD_STRING)))
		rls = process_cmd(dat, cur + ft_strlen(COMMENT_CMD_STRING), CMD_ID_COMMENT);
	return (rls);
}

// check test_data
int     do_cmd(t_lexdata *dat, char *line)
{
	int err;

	if ((err = choice_cmd(dat, line)))
		return (err);
	if (dat->debug_happend)
		ft_printf("\t\t\t\t\t\t\t\thappend= cmd\n");
	return (0);
}

int     do_inst(t_lexdata *dat, int idx, int *inst_set)
{
	int		len;
	int		err;

	// ' ', '\t'
	// or '%''-'
	// or '#''\0' can be for inst of 0 args
	// ',' bad in any case
	if(dat->cur_line[idx] == SEPARATOR_CHAR)
		return (ERR_LEX__ID_BAD_AFTER_INST);
	dat->end = idx;
	len = dat->end - dat->srt;
	if (dat->debug_happend)
		ft_printf("\t\t\t\tto_check= %.*s\n", len, dat->cur_line + dat->srt);
	if ((err = add_inst(dat)))
		return (err);
	if (skip_char(dat->cur_line[idx]))
		dat->srt = -1;
	else
		dat->srt = idx;
	*inst_set = 1;
	if (dat->debug_happend)
		ft_printf("\t\t\t\t\t\t\t\thappend= %s\n", "inst_token");
	return (0);
}

int     do_label(t_lexdata *dat, int idx)
{
	int		len;
	int		err;

	dat->end = idx;
	len = dat->end - dat->srt;
	if (dat->debug_happend)
		ft_printf("\t\t\t\tto_check= %.*s\n", len, dat->cur_line + dat->srt);
	if ((err = add_label(dat)))
		return (err);
	//TO_DO skip space and lines
	dat->srt = -1;
	if (dat->debug_happend)
		ft_printf("\t\t\t\t\t\t\t\thappend= %s\n", "label_token");
	return (0);
}

int     do_param(t_lexdata *dat, char *line, int idx)
{
	int		len;
	int		err;

	dat->end = idx;
	len = dat->end - dat->srt;
	if (dat->debug_happend)
		ft_printf("\t\t\t\tto_check= %.*s\n", len, dat->cur_line + dat->srt);
	if ((err = add_parm(dat)))
		return (err);
	if (skip_char(dat->cur_line[idx]) || line[idx] == SEPARATOR_CHAR)
		dat->srt = -1;
	else
		dat->srt = idx;
	return (0);
}

int     do_comment(t_lexdata *dat)
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

int     do_sepr(t_lexdata *dat, int idx)
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

int     do_endline(t_lexdata *dat)
{
	int		err;

	if ((err = add_token_nodata(dat, TOKEN_TYPE_END)))
		return (err);
	if (dat->debug_happend)
		ft_printf("\t\t\t\t\t\t\t\thappend= %s\n", "endline_token");
	return (0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   n80_lexer_check_line_job.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 17:39:02 by wgorold           #+#    #+#             */
/*   Updated: 2019/10/30 18:21:57 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

int		do_cmd(t_lexdata *dat, char *line)
{
	int err;

	if ((err = choice_cmd(dat, line)))
		return (err);
	if (dat->debug_happend)
		ft_printf("\t\t\t\t\t\t\t\thappend= cmd\n");
	return (0);
}

int		do_inst(t_lexdata *dat, int idx, int *inst_set)
{
	int		len;
	int		err;

	if (dat->cur_line[idx] == SEPARATOR_CHAR)
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

int		do_label(t_lexdata *dat, int idx)
{
	int		len;
	int		err;

	dat->end = idx;
	len = dat->end - dat->srt;
	if (dat->debug_happend)
		ft_printf("\t\t\t\tto_check= %.*s\n", len, dat->cur_line + dat->srt);
	if ((err = add_label(dat)))
		return (err);
	dat->srt = -1;
	if (dat->debug_happend)
		ft_printf("\t\t\t\t\t\t\t\thappend= %s\n", "label_token");
	return (0);
}

int		do_param(t_lexdata *dat, char *line, int idx)
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

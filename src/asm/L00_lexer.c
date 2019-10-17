/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   L00_lexer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 17:39:02 by jleann            #+#    #+#             */
/*   Updated: 2019/10/17 16:41:30 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <libstd.h>
#include "lexer.h"

int		choice_cmd(t_lexdata *dat, char *line)
{
	char	*cur;
	int		rls;

	rls = ERROR_LEX_UNDEFINE_CMD;
	if ((cur = ft_strstr(line, NAME_CMD_STRING)))
		rls = process_cmd(dat, cur + ft_strlen(NAME_CMD_STRING), 1);
	else if ((cur = ft_strstr(line, COMMENT_CMD_STRING)))
		rls = process_cmd(dat, cur + ft_strlen(COMMENT_CMD_STRING), 2);
	return (rls);
}

/*
int		skip_setter(t_lexdata *dat, char *line, int idx)
{
	dat->srt = -1;
	dat->end = -1;
	idx -= 1;
	while (line[++idx])
	{
		
		if (not_skip_char(line[idx]))
		{
			if (dat->srt == -1)
				dat->srt = idx;
			else
			{
				dat->end = idx;
				return (idx);
			}
		}
	}
	return (-1);
}
*/

int		check_line(t_lexdata *dat, char *line)
{
	int		idx;
	int		err;
	int		inst_set;
	int		len;
	int		line_len;

	idx = -1;
	inst_set = 0;
	dat->srt = -1;
	dat->end = -1;
	dat->cur_line = line;
	line_len = ft_strlen(line);
	while (++idx < line_len + 1)
	{
		if (dat->debug_happend)
			ft_printf("rest=%s\n", line + idx);
		if (not_skip_char(line[idx]) && dat->srt == -1)
			dat->srt = idx;
		if (!not_skip_char(line[idx]) && dat->srt == -1)
			continue;
		
		if (inst_set == 0)
		{
			if (line[idx] == CMD_START)
			{
				if ((err = choice_cmd(dat, line)))
					return (err);
				if (dat->debug_happend)
					ft_printf("\t\t\t\t\t\t\t\thappend= cmd\n");
				return (0);
			}

			else if (line[idx] == ' ') // char for end of inst ' '. maybe '%'
			{
				dat->end = idx;
				len = dat->end - dat->srt;
				if (dat->debug_happend)
					ft_printf("\t\t\t\tto_check= %.*s\n", len, dat->cur_line + dat->srt);
				if ((err = add_inst(dat)))
					return (err);
				dat->srt = -1;
				inst_set = 1;
				if (dat->debug_happend)
					ft_printf("\t\t\t\t\t\t\t\thappend= %s\n", "inst_token");
			}
			
			else if (line[idx] == LABEL_CHAR)
			{
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
			}
		}
		else
		{
			if (line[idx] == SEPARATOR_CHAR || line[idx] == '\0')
			{
				dat->end = idx;
				len = dat->end - dat->srt;
				if (dat->debug_happend)
					ft_printf("\t\t\t\tto_check= %.*s\n", len, dat->cur_line + dat->srt);
				if ((err = add_parm(dat)))
					return (err);
				dat->srt = -1;
			}
			if (line[idx] == SEPARATOR_CHAR)
			{
				if ((err = add_token_sep(dat)))
					return (err);
				if (dat->debug_happend)
					ft_printf("\t\t\t\t\t\t\t\thappend= %s\n", "sep_token");
			}
		}
		if (check_comment(dat, line + idx))
		{
			if (dat->debug_happend)
				ft_printf("\t\t\t\t\t\t\t\thappend= comment\n");
			if ((err = add_token_endline(dat)))
					return (err);
			if (dat->debug_happend)
				ft_printf("\t\t\t\t\t\t\t\thappend= %s\n", "endline_token");
			return (0);
		}
	}
	if ((err = add_token_endline(dat)))
		return (err);
	if (dat->debug_happend)
		ft_printf("\t\t\t\t\t\t\t\thappend= %s\n", "endline_token");
	//debug_token_list(dat);
	return (0);
}

int		run_lexer(char *fname, t_lexdata **dat_out)
{
	t_lexdata		*dat;
	char			*line;
	int				rlt;

	dat = (t_lexdata *)malloc(sizeof(t_lexdata));
	init_dat(dat);
	if (get_fd(fname, dat))
		return (ERROR_LEX_FD);
	while ((rlt = get_next_line(dat->fd, &line)) == 1)
	{
		if (add_line(dat, line))
		{
			error_case(dat, ERROR_LEX_NULL_NODE);
			return (-1);
		}
		if (check_line(dat, line))
			return (-1);
	}

	if (rlt == -1) //TODO error gnl
		return (-1);
	if (dat->debug_out)
		debug_token_list(dat);
    *dat_out = dat;
	return (0);
}


void		free_lexdata(t_lexdata *data)
{
	(void)data;
}
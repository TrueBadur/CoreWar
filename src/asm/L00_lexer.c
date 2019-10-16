/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   L00_lexer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 17:39:02 by jleann            #+#    #+#             */
/*   Updated: 2019/10/16 18:59:16 by wgorold          ###   ########.fr       */
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

	idx = -1;
	dat->srt = -1;
	dat->end = -1;
	dat->cur_line = line;
	while (line[++idx])
	{
		ft_printf("rest=%s\n", line + idx);
		if (not_skip_char(line[idx]) && dat->srt == -1)
			dat->srt = idx;
		
		if (line[idx] == CMD_START)
		{
			if ((err = choice_cmd(dat, line)))
				return (err);
			if (dat->debug_happend)
				ft_printf("happend= cmd\n");
			return (0);
		}

		else if (line[idx] == ' ') // char for end of inst ' '. maybe '%'
		{
			dat->end = idx;
			if ((err = add_inst(dat)))
				return (err);
			dat->srt = -1;
			ft_printf("happend= %s\n\trest=%s\n", "inst_token", line + idx);
		}
		
		else if (line[idx] == LABEL_CHAR)
		{
			dat->end = idx;
			if ((err = add_label(dat)))
				return (err);
			//TO_DO skip space and lines
			dat->srt = -1;
			ft_printf("happend= %s\n\trest=%s\n", "label_token", line + idx);
		}
		
		else if (check_comment(dat, line + idx))
		{
			if (dat->debug_happend)
				ft_printf("happend= comment\n");
			return (0);
		}
	}
	debug_token_list(dat);
	return (0);
}

int		run_lexer(char *fname, t_lexdata **dat_out)
{
	(void)dat_out; //malloc
	t_lexdata		dat;
	char			*line;
	int				rlt;

	init_dat(&dat);
	if (get_fd(fname, &dat))
		return (ERROR_LEX_FD);
	while ((rlt = get_next_line(dat.fd, &line)) == 1)
	{
		if (add_line(&dat, line))
		{
			error_case(&dat, ERROR_LEX_NULL_NODE);
			return (-1);
		}
		if (check_line(&dat, line))
			return (-1);
	}

	if (rlt == -1) //TODO error gnl
		return (-1);
	return (0);
}


void		free_lexdata(t_lexdata *data)
{
	(void)data;
}
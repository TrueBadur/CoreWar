/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   L00_lexer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 17:39:02 by jleann            #+#    #+#             */
/*   Updated: 2019/10/15 23:09:43 by wgorold          ###   ########.fr       */
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

int		check_line(t_lexdata *dat, char *line)
{
	int		idx;
	char	*cur;
	int		err;

	idx = -1;
	while (line[++idx])
	{
		cur = idx + line;
		if (*cur == CMD_START)
		{
			if ((err = choice_cmd(dat, line)))
				return (err);
			return (0);
		}
		else if (check_comment(dat, cur))
			return (0);
	}
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
	while ((rlt = get_next_line(dat.fd, &line)))
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
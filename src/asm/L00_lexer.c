/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   L00_lexer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 17:39:02 by jleann            #+#    #+#             */
/*   Updated: 2019/10/15 18:10:50 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <libstd.h>
#include "lexer.h"

int		process_cmd(t_lexdata *dat, char *line)
{
	char	*cur;

	if ((cur = ft_strstr(line, NAME_CMD_STRING)))
	{
		//ft_printf("process_cmd_name START\n");
		process_cmd_name(dat, line, cur + ft_strlen(NAME_CMD_STRING));
		return (0);
	}
	else if ((cur = ft_strstr(line, COMMENT_CMD_STRING)))
	{
		return (0);
	}
	return (1);
}

int		check_line(t_lexdata *dat, char *line)
{
	int		idx;
	char	*cur;

	idx = -1;
	while (line[++idx])
	{
		cur = idx + line;
		if (*cur == CMD_START)
		{
			//ft_printf("CMD_START\n");
			process_cmd(dat, line);
		}
		else if (check_comment(dat, cur))
			return (0);
	}
	return (0);
}

t_lexdata	*run_lexer(char *fname)
{
	t_lexdata		dat;
	char			*line;
	int 			fd;
	int				rlt;

	if ((fd = get_fd(fname)) == 0)
		return (NULL);
	init_dat(&dat);
	dat.fd = fd;
	
	if (dat.debug_fd)
		ft_printf("lexer_ds = %d\n", fd);

	while ((rlt = get_next_line(fd, &line)))
	{
		if (add_line(&dat, line))
		{
			error_case(&dat, ERROR_LEX_NULL_NODE);
			return (NULL);
		}
		check_line(&dat, line);
	}
	if (rlt == -1) //TODO error gnl
		return (NULL);

	return (NULL);
}
void		free_lexdata(t_lexdata *data)
{
	(void)data;
}
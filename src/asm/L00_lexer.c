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

#include "lexer.h"

int		check_line(t_lexdata *dat, char *line)
{
	int		idx;
	int		err;
	int		inst_set;
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
		if (skip_char(line[idx]) && dat->srt == -1)
			continue;
		
		if (inst_set == 0)
		{
			if (line[idx] == CMD_START) // and dat->srt == -1
			    return (do_cmd(dat, line));
			else if (skip_char(line[idx]) || special_char(line[idx]))
			{
			    if ((err = do_inst(dat, idx, &inst_set)))
                    return (err);
			}
			
			else if (line[idx] == LABEL_CHAR)
			{
                if ((err = do_label(dat, idx)))
                    return (err);
			}
		}
		else
		{
			if (dat->srt != idx
			&& (end_line_or_separ(line[idx]) || skip_char(line[idx])))
			{
                if ((err = do_param(dat, line, idx)))
                    return (err);
			}
		}
		if (line[idx] == SEPARATOR_CHAR)
		{
			if ((err = do_sepr(dat, idx)))
				return (err);
		}
		if (check_comment(dat, line + idx))
		    return (do_comment(dat));
	}
	return (do_endline(dat));
}

int		run_lexer(char *fname, t_lexdata **dat_out)
{
	t_lexdata		*dat;
	char			*line;
	int				tmp;

	if ((tmp = init_dat(&dat)))
		return (clean_n_exit(dat, tmp));
	if (get_fd(fname, dat))
		return (clean_n_exit(dat, ERROR_LEX_FD));
	while ((tmp = get_next_line(dat->fd, &line)) == 1)
	{
		if ((tmp = add_line(dat, line)))
			return (clean_n_exit(dat, tmp));
		if ((tmp = check_line(dat, line)))
			return (clean_n_exit(dat, tmp));
	}
	if (tmp == -1)
		return (clean_n_exit(dat, ERROR_LEX_GNL));
	if ((tmp = update_label(dat)))
		return (clean_n_exit(dat, tmp));
	if (dat->debug_out)
		debug_token_list(dat);
    *dat_out = dat;
	return (0);
}
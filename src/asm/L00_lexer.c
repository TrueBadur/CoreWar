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

int		choice_cmd(t_lexdata *dat, int idx)
{
	char	*line;
	int		rls;

	line = dat->cur_line;
	rls = ERROR_LEX_UNDEFINE_CMD;

	//ft_printf("ft_strncmp=%d\n", ft_strncmp(line, NAME_CMD_STRING, ft_strlen(NAME_CMD_STRING)));

	if (ft_strncmp(line, NAME_CMD_STRING, ft_strlen(NAME_CMD_STRING)) == 0)
		rls = process_cmd(dat, idx + ft_strlen(NAME_CMD_STRING), CMD_ID_NAME);
	else if (ft_strncmp(line, COMMENT_CMD_STRING, ft_strlen(COMMENT_CMD_STRING)) == 0)
		rls = process_cmd(dat, idx + ft_strlen(COMMENT_CMD_STRING), CMD_ID_COMMENT);
	return (rls);
}

// check test_data
int     do_cmd(t_lexdata *dat, int idx)
{
    int err;

    if ((err = choice_cmd(dat, idx)))
        return (err);
    if (dat->debug_happend)
        ft_printf("\t\t\t\t\t\t\t\thappend= cmd\n");
    return (0);
}

int     do_inst(t_lexdata *dat, int idx, int *inst_set)
{
    int		len;
    int		err;

    dat->end = idx;
    len = dat->end - dat->srt;
    if (dat->debug_happend)
        ft_printf("\t\t\t\tto_check= %.*s\n", len, dat->cur_line + dat->srt);
    if ((err = add_inst(dat)))
        return (err);
    dat->srt = -1;
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
    if (line[idx] == SEPARATOR_CHAR)
    {
        if ((err = add_token_nodata(dat, TOKEN_TYPE_DELIM)))
            return (err);
        if (dat->debug_happend)
            ft_printf("\t\t\t\t\t\t\t\thappend= %s\n", "sep_token");
        dat->srt = -1;
    }
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

int     do_endline(t_lexdata *dat)
{
    int		err;

    if ((err = add_token_nodata(dat, TOKEN_TYPE_END)))
        return (err);
    if (dat->debug_happend)
        ft_printf("\t\t\t\t\t\t\t\thappend= %s\n", "endline_token");
    return (0);
}

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
		if (!not_skip_char(line[idx]) && dat->srt == -1)
			continue;
		
		if (inst_set == 0)
		{
			if (line[idx] == CMD_START)
			    return (do_cmd(dat, idx));

			else if (line[idx] == ' ') // separator for inst: ' ', '%'
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
			if (line[idx] == SEPARATOR_CHAR || line[idx] == '\0')
			{
                if ((err = do_param(dat, line, idx)))
                    return (err);
			}
		}
		if (check_comment(dat, line + idx))
		    return (do_comment(dat));
	}
	return (do_endline(dat));
}

/*
**	to_clean
**		champ_name
**		champ_comment
**		label_list (only_nodes)
**		token_list
**		lines
**		t_lexdata *dat
*/
int 	clean_n_exit(t_lexdata *dat, int err)
{
	t_list_node *node;
	t_list_node *node_nxt;
	t_token		*tkn;

	if (dat->champ_name)
		free(dat->champ_name);
	if (dat->champ_comment)
		free(dat->champ_name);

	node = dat->label_list.begin;
	while (node)
	{
		node_nxt = node->next;
		free(node);
		node = node_nxt;
	}

	node = dat->token_list.begin;
	while (node)
	{
		node_nxt = node->next;
		tkn = (t_token *)(node->content);
		if (tkn->label)
			free(tkn->label);
		free(node->content);
		free(node);
		node = node_nxt;
	}

	node = dat->lines.begin;
	while (node)
	{
		node_nxt = node->next;
		free(node->content);
		free(node);
		node = node_nxt;
	}

	free(dat);
	return (err);
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


void		free_lexdata(t_lexdata *data)
{
	(void)data;
}
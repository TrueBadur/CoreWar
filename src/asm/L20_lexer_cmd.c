/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   L20_lexer_cmd_name.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 17:39:02 by jleann            #+#    #+#             */
/*   Updated: 2019/10/15 23:14:08 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

/*
** 0  - is_start
** -1 - fail char
** 1  - skip char
** 2  - skip line
*/

int		start_name(t_lexdata *dat, char *cur, char **start)
{
	if (*cur == ARG_CMD_START)
	{
		*start = cur;
		return (0);
	}
	else if (skip_char(*cur))
		return (1);
	else if (check_comment(dat, cur))
		return (2);
	else if (end_line(*cur))
		return (2);
	else
		return (-1);
}

int		search_start_in_lines(t_lexdata *dat, char **start, char **cur)
{
	int		rls;

	*start = NULL;
	while (*start == NULL)
	{
		rls = start_name(dat, *cur, start);
		if (rls == 0 || rls == 1)
			*cur += 1;
		else if (rls == 2) {
			return (ERR_LEX__ID_BAD_CMD_NO_START);
			//if (get_next_line(dat->fd, &line) != 1)
			//	return (ERR_LEX__ID_BAD_ARG_START);
			//if (add_line(dat, line))
			//	return (ERR_LEX__ID_NULL_NODE);
			//*cur = line;
		} else if (rls == -1) {
			return (ERR_LEX__ID_BAD_ARG_START);
		}
	}
	return (0);
}

int		search_end_in_lines(t_lexdata *dat, char **cur, t_list *lines)
{
	t_list_node	*node;
	char		*line;

	line = NULL;
	while (**cur != ARG_CMD_START)
	{
		if (**cur != '\0')
		{
			*cur += 1;
			continue ;
		}
		node = ft_lstnew_node(NULL, 0);
		if (line == NULL)
			node->content = dat->lines.end->content;
		else
			node->content = line;
		ft_lstaddend(lines, node);
		if (get_next_line(dat->fd, &line) != 1)
			return (ERR_LEX__ID_CMD_NO_END);
		if (add_line(dat, line))
				return (ERR_LEX__ID_NULL_NODE);
		dat->cur_line = line;
		*cur = line;
	}
	return (0);
}

int		check_end_of_line(t_lexdata *dat, char *cur)
{
	cur += 1;
	while (*cur != '\0')
	{
		if (check_comment(dat, cur))
			break ;
		else if (not_skip_char(*cur))
			return (ERR_LEX__ID_BAD_CMD_END);
		cur += 1;
	}
	return (0);
}

int		cmd_exit(t_list *lines, int out)
{
	free_list(lines);
	return (out);
}

int 	check_double_cmd(t_lexdata *dat, int id_cmd)
{
	if (id_cmd == CMD_ID_NAME && dat->champ_name != NULL)
		return (ERR_LEX__ID_DOUBLE_NAME);
	if (id_cmd == CMD_ID_COMMENT && dat->champ_comment != NULL)
		return (ERR_LEX__ID_DOUBLE_COMMENT);
	return (0);
}

int 	check_size(t_lexdata *dat, int id_cmd)
{
	if (id_cmd == CMD_ID_NAME && (ft_strlen(dat->champ_name) > PROG_NAME_LENGTH))
		return (ERR_LEX__ID_LONG_NAME);
	if (id_cmd == CMD_ID_COMMENT && (ft_strlen(dat->champ_comment) > COMMENT_LENGTH))
		return (ERR_LEX__ID_LONG_COMMENT);
	return (0);
}

int		process_cmd(t_lexdata *dat, char *cur, int id_cmd)
{
	t_list		lines;
	char		*start;
	char		*to_set;
	int			err;

	if ((err = check_double_cmd(dat, id_cmd)))
		return (err);
	init_stack_list(&lines);
	if ((err = search_start_in_lines(dat, &start, &cur)))
		return (cmd_exit(&lines, err));
	if ((err = search_end_in_lines(dat, &cur, &lines)))
		return (cmd_exit(&lines, err));
	if ((err = check_end_of_line(dat, cur)))
		return (cmd_exit(&lines, err));
	if (lines.len == 0)										// one line	
	{										
		if ((err = short_name(start, &to_set)))
			return (cmd_exit(&lines, err));
	}
	else													// multi line
	{
		if ((err = long_name(dat, start, &lines, &to_set)))
			return (cmd_exit(&lines, err));
	}
	if (id_cmd == CMD_ID_NAME)
		dat->champ_name = to_set;
	if (id_cmd == CMD_ID_COMMENT)
		dat->champ_comment = to_set;
	if ((err = check_size(dat, id_cmd)))
		return (cmd_exit(&lines, err));
	debug_cmd_name(dat, id_cmd);
	return (cmd_exit(&lines, 0));
}

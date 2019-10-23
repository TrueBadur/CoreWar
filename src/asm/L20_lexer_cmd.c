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

int		start_name(t_lexdata *dat, int *idx, char **start)
{
	char	*line;

	line = dat->cur_line;
	if (line[*idx] == ARG_CMD_START)
	{
		*start = line + *idx;
		return (0);
	}
	else if (line[*idx] == ' ')
		return (1);
	else if (check_comment_idx(dat, idx))
		return (2);
	else if (end_line(line[*idx]))
	{
		*idx += 1;
		return (2);
	}
	else
		return (1);
}

int		search_start_in_lines(t_lexdata *dat, char **start, int *cur)
{
	char	*line;
	int		rls;

	*start = NULL;
	while (*start == NULL)
	{
		rls = start_name(dat, cur, start);
		if (rls == 0 || rls == 1)
			*cur += 1;
		else if (rls == 2)
		{
			ft_printf("Syntax error at token [TOKEN][%03d:%03d] ENDLINE\n", dat->lines.len, *cur);
			return (ERROR_LEX_NO_CMD_ARG_IN_LINE);
			// TODO if next_line [002:001]
			//if (get_next_line(dat->fd, &line) != 1)
			//	return (ERROR_LEX_NAME_START);
			//if (add_line(dat, line))
			//	return (ERROR_LEX_NULL_NODE);
			//*cur = line;
		}
		else if (rls == -1)
			return (ERROR_LEX_NAME_START);
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
			return (ERROR_LEX_NAME_START);
		if (add_line(dat, line))
				return (ERROR_LEX_NULL_NODE);
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
		else if (*cur != ' ')
			return (ERROR_LEX_NAME_END_INVALIDE);
		cur += 1;
	}
	return (0);
}

int		process_cmd(t_lexdata *dat, int idx, int id_cmd)
{
	t_list		lines;
	char		*start;
	char		*to_set;
	int			err;
	char 		*cur;

	init_stack_list(&lines);
	if ((err = search_start_in_lines(dat, &start, &idx)))
		return (err);
	cur = dat->cur_line + idx;
	if ((err = search_end_in_lines(dat, &cur, &lines)))
		return (err);
	if ((err = check_end_of_line(dat, cur)))
		return (err);
	if (lines.len == 0)										// one line	
	{										
		if ((err = short_name(start, &to_set)))
			return (err);
	}
	else													// multi line
	{
		if ((err = long_name(dat, start, &lines, &to_set)))
			return (err);
	}
	if (id_cmd == CMD_ID_NAME)
		dat->champ_name = to_set;
	if (id_cmd == CMD_ID_COMMENT)
		dat->champ_comment = to_set;
	debug_cmd_name(dat, id_cmd);
	return (0);
}

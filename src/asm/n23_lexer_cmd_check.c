/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   n23_lexer_cmd_check.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 17:39:02 by wgorold           #+#    #+#             */
/*   Updated: 2019/10/30 18:21:49 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

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
	free_nodes_list(lines);
	return (out);
}

int		check_double_cmd(t_lexdata *dat, int id_cmd)
{
	if (id_cmd == CMD_ID_NAME && dat->champ_name != NULL)
		return (ERR_LEX__ID_DOUBLE_NAME);
	if (id_cmd == CMD_ID_COMMENT && dat->champ_comment != NULL)
		return (ERR_LEX__ID_DOUBLE_COMMENT);
	return (0);
}

int		check_size(t_lexdata *dat, int id_cmd)
{
	if (id_cmd == CMD_ID_NAME
		&& (ft_strlen(dat->champ_name) > PROG_NAME_LENGTH))
		return (ERR_LEX__ID_LONG_NAME);
	if (id_cmd == CMD_ID_COMMENT
		&& (ft_strlen(dat->champ_comment) > COMMENT_LENGTH))
		return (ERR_LEX__ID_LONG_CMT);
	return (0);
}

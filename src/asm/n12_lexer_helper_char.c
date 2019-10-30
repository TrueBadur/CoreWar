/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   L10_lexer_helper.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 17:39:02 by wgorold           #+#    #+#             */
/*   Updated: 2019/10/30 13:50:09 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

int		skip_char(char cur)
{
	if (cur == ' ')
		return (1);
	if (cur == '\t')
		return (1);
	return (0);
}

int		not_skip_char(char cur)
{
	return (!skip_char(cur));
}

/*
** add#
** add:
** add%
** add\0
** add,
*/

int		special_char(char cur)
{
	if (cur == COMMENT_CHAR)
		return (1);
	if (cur == COMMENT_CHAR_ADV)
		return (1);
	if (cur == DIRECT_CHAR)
		return (1);
	if (cur == SEPARATOR_CHAR)
		return (1);
	if (cur == '-')
		return (1);
	if (cur == '\0')
		return (1);
	return (0);
}

int		end_line_or_separ(char cur)
{
	if (cur == COMMENT_CHAR)
		return (1);
	if (cur == COMMENT_CHAR_ADV)
		return (1);
	if (cur == '\0')
		return (1);
	if (cur == SEPARATOR_CHAR)
		return (1);
	return (0);
}

int		end_line(char cur)
{
	if (cur == '\0')
		return (1);
	return (0);
}

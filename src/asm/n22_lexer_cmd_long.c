/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   n22_lexer_cmd_long.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 17:39:02 by wgorold           #+#    #+#             */
/*   Updated: 2019/10/30 18:21:48 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

void	get_len(char *start, t_list *lines, int *len)
{
	int			tmp;
	int			idx;
	char		*line;
	t_list_node	*node;

	tmp = ft_strlen(start + 1);
	node = lines->begin;
	node->content_size = tmp;
	*len = tmp + 1;
	node = node->next;
	while (node->next != NULL)
	{
		tmp = ft_strlen((char *)(node->content));
		node->content_size = tmp;
		*len += tmp + 1;
		node = node->next;
	}
	idx = 0;
	line = (char *)(node->content);
	while (*(line + idx) != ARG_CMD_START)
		++idx;
	*len += idx;
	node->content_size = idx;
}

void	get_copy(char *start, t_list *lines, char *out)
{
	int			len;
	t_list_node	*node;

	len = 0;
	node = lines->begin;
	ft_strncpy(out, start + 1, node->content_size);
	len += node->content_size;
	out[len++] = '\n';
	node = node->next;
	while (node->next != NULL)
	{
		ft_strncpy(out + len, (char *)(node->content), node->content_size);
		len += node->content_size;
		out[len++] = '\n';
		node = node->next;
	}
	ft_strncpy(out + len, (char *)(node->content), node->content_size);
}

int		long_name(t_lexdata *dat, char *start, t_list *lines, char **to_set)
{
	int			len;
	char		*out;
	t_list_node	*node;

	node = ft_lstnew_node(NULL, 0);
	node->content = dat->lines.end->content;
	ft_lstaddend(lines, node);
	get_len(start, lines, &len);
	out = ft_strnew(len);
	if (!out)
		return (ERR_LEX__ID_MALLOC_STR);
	get_copy(start, lines, out);
	*to_set = out;
	return (0);
}

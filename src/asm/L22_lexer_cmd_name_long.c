/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   L22_lexer_cmd_name_long.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 17:39:02 by jleann            #+#    #+#             */
/*   Updated: 2019/10/15 20:41:11 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

void	get_len(char *start, t_list *lines, int *len)
{
	int			tmp;
	int 		idx;
	char		*line;
	t_list_node	*node;
	
	//len_first
	tmp = ft_strlen(start + 1);
	node = lines->begin;
	node->content_size = tmp;
	*len = tmp + 1; // for \n
	ft_printf(">>>>>>>> start = %d\n", *len);
	
	//len_mid
	node = node->next;
	while (node->next != NULL)
	{
		tmp = ft_strlen((char *)(node->content));
		node->content_size = tmp;
		*len += tmp + 1;
		node = node->next;
		ft_printf(">>>>>>>> mid = %d\n", tmp);
	}

	// len_of_last
	idx = 0;
	line = (char *)(node->content);
	while (*(line + idx) != ARG_CMD_START)
		++idx;
	*len += idx;
	node->content_size = idx;
	ft_printf(">>>>>>>> last = %d\n", idx);
}

void	get_copy(char *start, t_list *lines, char *out)
{
	int			len;
	t_list_node	*node;
	
	//copy_first
	len = 0;
	node = lines->begin;
	ft_strncpy(out, start + 1, node->content_size);
	len += node->content_size;
	out[len++] = '\n';
	ft_printf(">>>>>>>> out_len = %d\n", len);
	
	//copy_mid
	node = node->next;
	while (node->next != NULL)
	{
		ft_strncpy(out + len, (char *)(node->content), node->content_size);
		len += node->content_size;
		out[len++] = '\n';
		node = node->next;
	}
	//copy_last
	ft_strncpy(out + len, (char *)(node->content), node->content_size);
}

int		long_name(t_lexdata *dat, char *start, t_list *lines)
{
	int			len;
	char		*out;
	t_list_node	*node;

	node = ft_lstnew_node(NULL, 0);
	node->content = dat->lines.end->content;
	ft_lstaddend(lines, node);
	ft_printf(">>>>>>>> num_node = %d\n", lines->len);

	get_len(start, lines, &len);

	out = ft_strnew(len);		// malloc
	if (!out)
		return (ERROR_LEX_MALLOC_STR);
		
	get_copy(start, lines, out);

	dat->champ_name = out;
	free_list(lines);
	debug_cmd_name(dat);
	return (0);
}
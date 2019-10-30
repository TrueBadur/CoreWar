/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   L70_lexer_clear.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 17:39:02 by wgorold           #+#    #+#             */
/*   Updated: 2019/10/30 13:50:44 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

/*
**	to_clean
**		champ_name
**		champ_comment
**		label_list (only_nodes)
**		token_list
**		lines
**		t_lexdata *dat
*/

void	print_msg_error_adv(t_lexdata *dat, int err)
{
	if (err == ERR_LEX__ID_BAD_CMD_END)
		ft_printf(LEX_ERR_MSG_BAD_CMD_END, dat->cur_line);
	else if (err == ERR_LEX__ID_BAD_CMD_NO_START)
		ft_printf(LEX_ERR_MSG_BAD_CMD_NO_START);
	else if (err == ERR_LEX__ID_BAD_ARG_START)
		ft_printf(ERR_LEX_MSG_BAD_ARG_START, dat->cur_line);
	else if (err == ERR_LEX__ID_CMD_NO_END)
		ft_printf(LEX_ERR_MSG_CMD_NO_END);
	else if (err == ERR_LEX__ID_MALLOC_STR)
		ft_printf(LEX_ERR_MSG_MALLOC_STR);
	else if (err == ERR_LEX__ID_NULL_NODE)
		ft_printf(LEX_ERR_MSG_NULL_NODE);
	else if (err == ERR_LEX__ID_FD)
		ft_printf(LEX_ERR_MSG_FD);
	else if (err == ERR_LEX__ID_UNDEFINE_CMD)
		ft_printf(LEX_ERR_MSG_UNDEFINE_CMD);
	else if (err == ERR_LEX__ID_LABEL_UPDATE)
		ft_printf(LEX_ERR_MSG_LABEL_UPDATE, dat->cur_line);
	else if (err == ERR_LEX__ID_GNL)
		ft_printf(LEX_ERR_MSG_GNL);
	else if (err == ERR_LEX__ID_MALLOC_DAT)
		ft_printf(LEX_ERR_MSG_MALLOC_DAT);
	else if (err == ERR_LEX__ID_EMPTY_PARAM)
		ft_printf(LEX_ERR_MSG_EMPTY_PARAM);
}

void	print_msg_error(t_lexdata *dat, int err)
{
	if (err == ERR_LEX__ID_NOT_LABEL_CHAR)
		ft_printf(LEX_ERR_MSG_NOT_LABEL_CHAR, dat->end - dat->srt,
		dat->cur_line + dat->srt, dat->cur_line[dat->cur_idx]);
	else if (err == ERR_LEX__ID_INST_NOT_FOUND)
		ft_printf(LEX_ERR_MSG_INST_NOT_FOUND,
		dat->end - dat->srt, dat->cur_line + dat->srt);
	else if (err == ERR_LEX__ID_DOUBLE_NAME)
		ft_printf(LEX_ERR_MSG_DOUBLE_NAME);
	else if (err == ERR_LEX__ID_DOUBLE_COMMENT)
		ft_printf(LEX_ERR_MSG_DOUBLE_COMMENT);
	else if (err == ERR_LEX__ID_LONG_NAME)
		ft_printf(LEX_ERR_MSG_LONG_NAME,
		ft_strlen(dat->champ_name), PROG_NAME_LENGTH);
	else if (err == ERR_LEX__ID_LONG_COMMENT)
		ft_printf(LEX_ERR_MSG_LONG_COMMENT,
		ft_strlen(dat->champ_comment), COMMENT_LENGTH);
	else if (err == ERR_LEX__ID_LABEL_EMPTY)
		ft_printf(LEX_ERR_MSG_LABEL_EMPTY);
	else if (err == ERR_LEX__ID_ATOI)
		ft_printf(LEX_ERR_MSG_ATOI);
	else if (err == ERR_LEX__ID_BAD_AFTER_INST)
		ft_printf(LEX_ERR_MSG_BAD_AFTER_INST);
	else
		print_msg_error_adv(dat, err);
}

void	print_error(t_lexdata *dat, int err)
{
	unsigned long line;

	line = (dat->err_line == -1) ? dat->lines.len : dat->err_line;
	ft_printf("\033[31;1mLexer_ERROR [%03d, %03d]:", line, dat->srt);
	print_msg_error(dat, err);
	ft_printf("\n\033[0m");
}

void	clear_token(t_lexdata *dat)
{
	t_list_node	*node;
	t_list_node	*node_nxt;
	t_token		*tkn;

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
}

int		clean_n_exit(t_lexdata *dat, int err)
{
	t_list_node	*node;
	t_list_node	*node_nxt;

	if (err)
		print_error(dat, err);
	if (dat->champ_name)
		free(dat->champ_name);
	if (dat->champ_comment)
		free(dat->champ_comment);
	clear_token(dat);
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

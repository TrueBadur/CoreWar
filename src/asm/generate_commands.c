/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_commands.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleann <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 18:32:05 by jleann            #+#    #+#             */
/*   Updated: 2019/10/26 18:32:06 by jleann           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "champ_generator.h"
#include "debug_funcs.h"

void		read_params(t_command *cmd, t_list_node **lst)
{
	t_op	*opdata;
	int		cur_par;
	t_token	*token;

	opdata = get_op_info(cmd->cmd_type);
	cur_par = 0;
	while (cur_par < opdata->params_num)
	{
		token = eat(lst, PARAM_ID);
		if (((uint8_t)(token->sub_type) & opdata->paramtypes[cur_par]) == 0)
			raise_error_sem(INVALID_PAR_TYPE_ERR, token);
		cmd->params[cur_par] = token;
		token = (*lst)->content;
		if (token->type != DELIM_ID)
			break ;
		else
			eat(lst, DELIM_ID);
		cur_par++;
	}
}

void		read_command(t_command *cmd, t_list_node **lst)
{
	t_token	*token;

	token = eat(lst, 0);
	if (token->type == LABEL_ID)
	{
		cmd->label = token;
		token = eat(lst, LABEL_ID);
	}
	token = eat(lst, 0);
	if (token->type == INST_ID)
	{
		cmd->cmd_type = (char)(token->data);
		eat(lst, INST_ID);
		read_params(cmd, lst);
	}
	eat(lst, ENDL_ID);
}

void		read_tokens(t_lexdata *ldata, t_champdata *cdata, size_t *larr)
{
	t_list_node	*cur_token;
	t_command	buff_cmd;
	t_token		*token;

	cur_token = ldata->token_list.begin;
	while (cur_token)
	{
		token = cur_token->content;
		if (token->type == ENDL_ID)
			cur_token = cur_token->next;
		else
		{
			ft_bzero(&buff_cmd, sizeof(t_command));
			read_command(&buff_cmd, &cur_token);
			if (buff_cmd.label != NULL)
				larr[buff_cmd.label->data] = cdata->size;
			if (buff_cmd.cmd_type != 0)
			{
				buff_cmd.pos_in_file = cdata->size;
				cdata->size += calc_command_size(&buff_cmd);
				ft_lstaddend(&(cdata->commands),
	ft_lstnew_node(&buff_cmd, sizeof(t_command)));
			}
		}
	}
}

void		replace_labels(t_list *cmds, size_t *larr)
{
	t_command	*cur_cmd;
	t_list_node	*cur_node;
	char		cur_par;
	t_op		*cur_op;

	cur_node = cmds->begin;
	while (cur_node)
	{
		cur_cmd = cur_node->content;
		if (cur_cmd->cmd_type > 0)
		{
			cur_op = get_op_info(cur_cmd->cmd_type);
			cur_par = 0;
			while (cur_par < cur_op->params_num)
			{
				if (cur_cmd->params[cur_par]->val_type == PARAM_LABEL)
					cur_cmd->params[cur_par]->data = (int)
							(larr[cur_cmd->params[cur_par]->data] -
							cur_cmd->pos_in_file);
				cur_par++;
			}
		}
		cur_node = cur_node->next;
	}
}

void		generate_commands(t_champdata *cdata, t_lexdata *ldata)
{
	size_t	*larr;

	larr = ft_memalloc(sizeof(size_t) * ldata->labels_num);
	read_tokens(ldata, cdata, larr);
	replace_labels(&(cdata->commands), larr);
	print_labels(larr, ldata->labels_num);
	free(larr);
}

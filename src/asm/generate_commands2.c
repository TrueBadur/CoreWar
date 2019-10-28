/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_commands2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleann <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 18:32:18 by jleann            #+#    #+#             */
/*   Updated: 2019/10/26 18:32:19 by jleann           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "champ_generator.h"

t_token		*eat(t_list_node **lst, char type)
{
	t_token	*token;

	if (*lst == NULL)
		raise_error_sem(UNEXPECTED_EOF_ERR, NULL);
	token = (*lst)->content;
	if (!type || token->type == type)
	{
		(*lst) = (*lst)->next;
		return (token);
	}
	else
		raise_error_sem(UNEXPECTED_TOKEN_AT_ERR, token);
	return (NULL);
}

size_t		calc_command_size(t_command *cmd)
{
	t_op	*cur_op;
	size_t	size;
	int		cur_par;

	cur_op = get_op_info(cmd->cmd_type);
	size = 1;
	size += cur_op->is_param_b;
	cur_par = 0;
	while (cur_par < cur_op->params_num)
	{
		if (cmd->params[cur_par]->sub_type == T_REG)
			size += 1;
		else if (cmd->params[cur_par]->sub_type == T_IND)
			size += 2;
		else if (cmd->params[cur_par]->sub_type == T_DIR)
			size += cur_op->t_dir_size ? 2 : 4;
		cur_par++;
	}
	return (size);
}

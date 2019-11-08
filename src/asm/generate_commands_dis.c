/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_commands_dis.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleann <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 02:28:44 by jleann            #+#    #+#             */
/*   Updated: 2019/11/02 02:28:44 by jleann           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "disassembler.h"

inline static uint8_t	get_par_type(uint8_t ops, uint8_t id)
{
	uint8_t tmp;

	tmp = (uint8_t)(ops >> (uint8_t)(6 - id * 2)) & 3U;
	if (tmp == 1)
		return (T_REG);
	else if (tmp == 2)
		return (T_DIR);
	else if (tmp == 3)
		return (T_IND);
	else
		return (-1);
}

static void				read_params(t_command *cmd, void *exc, size_t *cr,
									size_t cap)
{
	uint8_t	cur_par;
	t_op	*op;

	op = get_op_info(cmd->cmd_type);
	cur_par = 0;
	while (cur_par < op->params_num)
	{
		if (op->paramtypes[cur_par] == T_REG)
		{
			cmd->params[cur_par].data = read_int8_mem(exc, cr, cap);
			cmd->params[cur_par].type = T_REG;
		}
		else if (op->paramtypes[cur_par] == T_IND)
		{
			cmd->params[cur_par].data = read_int8_mem(exc, cr, cap);
			cmd->params[cur_par].type = T_IND;
		}
		else if (op->paramtypes[cur_par] == T_DIR)
		{
			cmd->params[cur_par].data = op->t_dir_size ?
					read_int16_mem(exc, cr, cap) : read_int32_mem(exc, cr, cap);
			cmd->params[cur_par].type = T_DIR;
		}
		cur_par++;
	}
}

static void				read_params_opt(t_command *cmd, void *exc, size_t *cr,
									size_t cap)
{
	uint8_t	cur_par;
	t_op	*op;
	uint8_t	tmp;

	op = get_op_info(cmd->cmd_type);
	cur_par = 0;
	while (cur_par < op->params_num)
	{
		tmp = get_par_type(cmd->par_types, cur_par);
		if (tmp == T_REG && T_REG & op->paramtypes[cur_par])
			cmd->params[cur_par].data = read_int8_mem(exc, cr, cap);
		else if (tmp == T_IND && T_IND & op->paramtypes[cur_par])
			cmd->params[cur_par].data = read_int16_mem(exc, cr, cap);
		else if (tmp == T_DIR && T_DIR & op->paramtypes[cur_par])
			cmd->params[cur_par].data = op->t_dir_size ?
					read_int16_mem(exc, cr, cap) : read_int32_mem(exc, cr, cap);
		else
			raise_error_dis(INVALID_PAR_TYPE_ERR);
		cmd->params[cur_par].type = tmp;
		cur_par++;
	}
}

static void				read_command(t_command *cmd, char *exec_code,
									size_t *cur, size_t size)
{
	t_op	*op;

	cmd->cmd_type = exec_code[*cur];
	(*cur)++;
	if ((op = get_op_info(cmd->cmd_type)) == NULL)
		raise_error_dis(INVALID_CMD_TYPE_ERR);
	if (op->is_param_b)
	{
		cmd->par_types = exec_code[*cur];
		(*cur)++;
		read_params_opt(cmd, exec_code, cur, size);
	}
	else
		read_params(cmd, exec_code, cur, size);
}

void					generate_commands_dis(t_headdata *data, void *exec_code,
								t_list *cmd_lst)
{
	size_t		cur;
	t_command	buff_cmd;

	ft_bzero(cmd_lst, sizeof(t_list));
	cur = 0;
	while (cur < data->size)
	{
		ft_bzero(&buff_cmd, sizeof(t_command));
		read_command(&buff_cmd, exec_code, &cur, data->size);
		ft_lstaddend(cmd_lst, ft_lstnew_node(&buff_cmd, sizeof(t_command)));
	}
}

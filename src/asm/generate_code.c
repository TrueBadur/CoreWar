/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_code.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleann <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 18:29:27 by jleann            #+#    #+#             */
/*   Updated: 2019/10/26 18:29:28 by jleann           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "champ_generator.h"

uint8_t		generate_params_code(t_command *cmd, t_op *opdata)
{
	uint8_t	cur_par;
	uint8_t	res;

	res = 0;
	cur_par = 0;
	while (cur_par < opdata->params_num)
	{
		if (cmd->params[cur_par]->sub_type == T_DIR)
			res += T_DIR_CODE << (2U * (3 - cur_par));
		else if (cmd->params[cur_par]->sub_type == T_IND)
			res += T_IND_CODE << (2U * (3 - cur_par));
		else if (cmd->params[cur_par]->sub_type == T_REG)
			res += T_REG_CODE << (2U * (3 - cur_par));
		cur_par++;
	}
	return (res);
}

void		write_int16(char **dest, int16_t value)
{
	(*dest)[0] = ((uint8_t *)(&value))[1];
	(*dest)[1] = ((uint8_t *)(&value))[0];
	*dest += 2;
}

void		write_int32(char **dest, int32_t value)
{
	write_int16(dest, ((int16_t *)(&value))[1]);
	write_int16(dest, ((int16_t *)(&value))[0]);
}

void		write_command(char	*dest, t_command *cmd)
{
	t_op	*opdata;
	char 	cur_par;

	opdata = get_op_info(cmd->cmd_type);
	*dest++ = cmd->cmd_type;
	if (opdata->is_param_b)
		*dest++ = generate_params_code(cmd, opdata);
	cur_par = 0;
	while (cur_par < opdata->params_num)
	{
		if (cmd->params[cur_par]->sub_type == T_REG)
			*dest++ = (int8_t)(cmd->params[cur_par]->data);
		else if (cmd->params[cur_par]->sub_type == T_IND)
			write_int16(&dest, (int16_t)(cmd->params[cur_par]->data));
		else if (cmd->params[cur_par]->sub_type == T_DIR)
		{
			if (opdata->t_dir_size)
				write_int16(&dest, (int16_t)(cmd->params[cur_par]->data));
			else
				write_int32(&dest, (int32_t)(cmd->params[cur_par]->data));
		}
		cur_par++;
	}
}

void		generate_code(t_champdata *data)
{
	t_list_node	*cur_cmd;
	t_command	*cmd;

	data->exec_code = ft_memalloc(data->size);
	cur_cmd = data->commands.begin;

	while (cur_cmd)
	{
		cmd = cur_cmd->content;
		if (cmd->cmd_type != 0)
			write_command(data->exec_code + cmd->pos_in_file, cmd);
		cur_cmd = cur_cmd->next;
	}
}

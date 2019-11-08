/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   writer_dis.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleann <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 02:49:20 by jleann            #+#    #+#             */
/*   Updated: 2019/11/02 02:49:21 by jleann           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "disassembler.h"

static char		*get_par_type(char type)
{
	if (type == T_REG)
		return ("T_REG");
	else if (type == T_DIR)
		return ("T_DIR");
	else if (type == T_IND)
		return ("T_IND");
	return ("");
}

static void		print_command(int fd, t_command *cmd)
{
	int cur;

	if (cmd->cmd_type > 0)
	{
		ft_fdprintf(fd, "%s ", get_op_info(cmd->cmd_type)->name);
		cur = 0;
		while (cur < get_op_info(cmd->cmd_type)->params_num)
		{
			if (cur != 0)
				ft_fdprintf(fd, ", ");
			if (cmd->params[cur].type == T_DIR)
				ft_fdprintf(fd, "%%%d", cmd->params[cur].data);
			if (cmd->params[cur].type == T_IND)
				ft_fdprintf(fd, "%d", cmd->params[cur].data);
			if (cmd->params[cur].type == T_REG)
				ft_fdprintf(fd, "r%d", cmd->params[cur].data);
			cur++;
		}
		ft_fdprintf(fd, "\n");
	}
}

static void		print_commands(int fd, t_list_node *lst)
{
	while (lst)
	{
		print_command(fd, lst->content);
		lst = lst->next;
	}
}

void			write_commands_dis(t_headdata *data, t_list *cmd_lst,
									char *ofname)
{
	int fd;

	if ((fd = (open(ofname,
			O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU | S_IRWXG | S_IRWXO))) == -1)
	{
		ft_fdprintf(STDERR_FILENO, "Cannot create file(((\n");
		exit(2);
	}
	ft_fdprintf(fd, ".name \"%.128s\"\n", data->champ_name);
	ft_fdprintf(fd, ".comment \"%.2048s\"\n", data->champ_comment);
	print_commands(fd, cmd_lst->begin);
}

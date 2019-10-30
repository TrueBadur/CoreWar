#include "disassembler.h"

static void	read_command(t_command *cmd, char *exec_code, size_t *cur)
{
	cmd->cmd_type = exec_code[*cur];
	(*cur)++;
}

void	generate_commands_dis(t_headdata *data,
		void *exec_code, t_list *cmd_lst)
{
	size_t	cur;
	t_command	buff_cmd;

	cur = 0;
	while (cur < data->size)
	{
		ft_bzero(&buff_cmd, sizeof(t_command));
		read_command(&buff_cmd, exec_code, &cur);
		ft_lstaddend(cmd_lst, ft_lstnew_node(&buff_cmd, sizeof(t_command)));
	}
}

#include "lexer.h"
#include "champ_generator.h"

char 		*get_par_type(char type)
{
	if (type == T_REG)
		return "T_REG";
	else if (type == T_DIR)
		return "T_DIR";
	else if (type == T_IND)
		return "T_IND";
	return ("");
}

void		print_command(t_command *cmd)
{
	int cur;

	ft_printf("LABEL: %s\n", cmd->label ? cmd->label->label : "NONE");
	if (cmd->cmd_type > 0)
	{
		ft_printf("CMD_TYPE: %s\n", get_op_info(cmd->cmd_type)->name);
		ft_printf("POS IN FILE: %lld\n", cmd->pos_in_file + 2193);
		ft_printf("SIZE OF COMMAND: %lld\n", calc_command_size(cmd));
		cur = 0;
		while (cur < get_op_info(cmd->cmd_type)->params_num)
		{
			ft_printf("PARAM TYPE: %s\n", get_par_type(cmd->params[cur]->sub_type));
			ft_printf("PARAM VALUE: %d\n\n", cmd->params[cur]->data);
			cur++;
		}
	}
}

void		print_commands(t_list_node *lst)
{
	while (lst)
	{
		print_command(lst->content);
		lst = lst->next;
	}
}

void		print_labels(size_t *larr, unsigned labels_num)
{
	unsigned	i;

	i = 0;
	ft_printf("LABELS:\n");
	while (i < labels_num)
	{
		ft_printf("LABEL %d: %d\n", i, larr[i]);
		i++;
	}
	ft_printf("\n");
}


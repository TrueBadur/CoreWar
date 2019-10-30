#include "disassembler.h"

void	write_commands_dis(t_headdata *data, t_list *cmd_lst, char *ofname)
{
	ft_printf(".name \"%.128s\"\n", data->champ_name);
	ft_printf(".comment \"%.2048s\"\n", data->champ_comment);
	ft_printf("code_size: %d\n", data->size);
}
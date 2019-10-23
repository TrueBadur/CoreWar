//
// Created by Jasper Leann on 11/10/2019.
//

#include "semantic_graph.h"
#include "ft_printf.h"
#include "read_args.h"
#include "lexer.h"
#include "champ_generator.h"
#include "writer.h"

void print_command_data(t_command *cmd)
{
    ft_printf("label: %s\n", cmd->label ? cmd->label->data : "None");
    if (cmd->cmd_type != 0)
    {
        ft_printf("cmd: %s\n", get_op_info(cmd->cmd_type)->name);
        ft_printf("Nuber of params: %d\n", get_op_info(cmd->cmd_type)->params_num);
        for (int i = 0; i < get_op_info(cmd->cmd_type)->params_num; i++)
        {
            ft_printf("  Par %d: %d\n", i, cmd->params[i]->sub_type);
        }
    }
    else
        ft_printf("EOF\n");
    ft_printf("\n");
}


void    print_commands(t_champdata *data)
{
    t_list_node *cur_cmd;

    ft_printf("Champion name: \"%s\"\n", data->champ_name);
    ft_printf("Champion comment: \"%s\"\n", data->champ_comment);
    ft_printf("\n");
    cur_cmd = data->commands.begin;
    while (cur_cmd)
    {
        print_command_data(cur_cmd->content);
        cur_cmd = cur_cmd->next;
    }
}

    void 	assemble(t_argdata *args)
{
	t_lexdata	*lexdata;
	t_champdata	*champdata;

	if (run_lexer(args->fname, &lexdata))
		exit(1);
//    debug_token_list(lexdata);
	champdata = run_champgenerator(lexdata);
	print_commands(champdata);
	write_champ(champdata, args);
	free_lexdata(lexdata);
	free_champdata(champdata);
}


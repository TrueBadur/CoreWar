
#include <op.h>
#include "lexer.h"
#include "libstd.h"
#include "semantic_graph.h"

void	begin_func(t_command *cmd, t_token *token)
{
	ft_bzero(cmd, sizeof(t_command));
}

void	label_func(t_command *cmd, t_token *token)
{
	cmd->label = token;
}

void	cmd_func(t_command *cmd, t_token *token)
{
	cmd->cmd_type = *(char *)(token->data);
}

void	param_func(t_command *cmd, t_token *token)
{
	t_op	*cur_op;
	int i;

	i = 0;
	cur_op = get_op_info(cmd->cmd_type);
    while (cmd->params[i] != NULL && i < 3)
        i++;
    if (i  >= cur_op->params_num)
        raise_error_sem(TOO_MANY_PARAMS_ERR, token);
    if ((token->sub_type & cur_op->paramtypes[i]) == 0)
    	raise_error_sem(INVALID_PAR_TYPE_ERR, token);
    cmd->params[i] = token;
}

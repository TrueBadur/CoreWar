
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
//	need_to_implement
}

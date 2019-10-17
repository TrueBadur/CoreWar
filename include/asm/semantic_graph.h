
#ifndef COREWAR_SEMANTIC_GRAPH_H
#define COREWAR_SEMANTIC_GRAPH_H

#include "ft_list.h"
#include "lexer.h"

typedef struct		s_command
{
	char	cmd_type;
	t_token	*params[3];
	t_token	*label;
}					t_command;

typedef struct		s_semnode
{
	char 	req_type;
	void (*op) (t_command *, t_token *);
	t_list	links;
}					t_semnode;

#define BEGIN_ID 0
#define LABEL_ID 1
#define CMD_ID 2
#define ENDL_ID 3
#define PARAM_ID 4
#define DELIM_ID 5
#define END_ID 6


# define UNEXPECTED_TOKEN_AT_ERR "Unexpected token, "
# define TOO_MANY_PARAMS_ERR "Too many params, "
# define UNEXPECTED_EOF_ERR "Unexpected end of file, "
# define INVALID_PAR_TYPE_ERR "Invalid parameter type, "

t_semnode	*create_node(char id, void (*op) (t_command *, t_token *));
void		create_link(t_semnode *from, t_semnode *to);
t_semnode	*look_for(t_semnode *from, char id);
void		free_sem_graph(t_semnode **graph);

t_semnode	**generate_sem_graph();
void	begin_func(t_command *cmd, t_token *token);
void	label_func(t_command *cmd, t_token *token);
void	cmd_func(t_command *cmd, t_token *token);
void	param_func(t_command *cmd, t_token *token);
void    raise_error_sem(const char *str, t_token *token);

#endif //COREWAR_SEMANTIC_GRAPH_H

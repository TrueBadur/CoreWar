
#include <ft_printf.h>
#include "libstd.h"
#include "champ_generator.h"
#include "semantic_graph.h"
#include "lexer.h"

void		read_tokens(t_lexdata *data, t_list *cmd_lst)
{
	t_semnode	**sem_graph;
	t_semnode	*cur_node;
	t_list_node	*cur_token;
	t_command	tmp_cmd;

	sem_graph = generate_sem_graph();
	cur_token = data->token_list.begin;
	cur_node = sem_graph[0];
	while (cur_token)
	{
		cur_node->op(&tmp_cmd, cur_token->content);
		if ((cur_node = look_for(cur_node, ((t_token *)cur_token->content)->type)))
		{
			if (cur_node->req_type == END_ID)
				ft_lstadd(cmd_lst, ft_lstnew_node(&tmp_cmd, sizeof(t_command)));
		}
		else
			raise_error_sem(UNEXPECTED_TOKEN_AT_ERR, cur_token->content);
		cur_token = cur_token->next;
	}
	if (cur_node->req_type != BEGIN_ID)
	    raise_error_sem(UNEXPECTED_EOF_ERR, NULL);
	free_sem_graph(sem_graph);
}

t_champdata		*run_champgenerator(t_lexdata *data)
{
	t_champdata	*res;

	res = ft_memalloc(sizeof(t_champdata));
	res->champ_name = data->champ_name;
	res->champ_comment = data->champ_comment;
	read_tokens(data, &(res->commands));
	return (res);
}

void            raise_error_sem(const char *str, t_token *token)
{
    if (token)
        ft_printf("%s at: (%d, %d)\n", token->line_num, token->pos_num);
    else
        ft_printf("%s\n");
}

void			free_champdata(t_champdata *data)
{

}

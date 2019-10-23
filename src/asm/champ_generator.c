
#include <ft_printf.h>
#include "libstd.h"
#include "champ_generator.h"
#include "semantic_graph.h"
#include "lexer.h"

char*	back_str_type(int id_label);
char*	back_str_sub_type(int id_label);
char*	back_str_val_type(int id_label);
void	print_data(void *data, int type, int val_type);

void        print_debug(t_token *tkn)
{
    ft_printf("\ttype=     %2d %s\n",  tkn->type, back_str_type(tkn->type));
    ft_printf("\tsub_type= %2d %s\n", tkn->sub_type, back_str_sub_type(tkn->sub_type));
    ft_printf("\tval_type= %2d %s\n", tkn->val_type, back_str_val_type(tkn->val_type));
    ft_printf("\tline_num= %2d\n", tkn->line_num);
    ft_printf("\tpos_num=  %2d\n", tkn->pos_num);
    print_data(tkn->data, tkn->type, tkn->val_type);
    ft_printf("\n");
}

void		read_tokens(t_lexdata *data, t_list *cmd_lst)
{
    t_semnode	**sem_graph;
    t_semnode	*cur_node;
    t_list_node	*cur_token;
    t_command	tmp_cmd;

    sem_graph = generate_sem_graph();
    cur_token = data->token_list.begin;
    cur_node = sem_graph[0];
    cur_node->op(&tmp_cmd, cur_token->content);
    while (cur_token)
    {
        if ((cur_node = look_for(cur_node, ((t_token *)cur_token->content)->type)))
        {
            if (cur_node->req_type == END_ID && tmp_cmd.cmd_type != 0)
                ft_lstaddend(cmd_lst, ft_lstnew_node(&tmp_cmd, sizeof(t_command)));
        }
        else
            raise_error_sem(UNEXPECTED_TOKEN_AT_ERR, cur_token->content);
        if (cur_node->op)
            cur_node->op(&tmp_cmd, cur_token->content);
        if (cur_node->req_type != END_ID && cur_node->req_type != BEGIN_ID)
            cur_token = cur_token->next;
    }
    ft_lstaddend(cmd_lst, ft_lstnew_node(&tmp_cmd, sizeof(t_command)));
    if (look_for(cur_node, END_ID) == NULL)
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
    {
        ft_printf("%s at: (%d, %d)\n",str, token->line_num, token->pos_num);
        print_debug(token);
    }
    else
        ft_printf("%s\n", str);
    exit(2);
}

void			free_champdata(t_champdata *data)
{
	(void)data;
}

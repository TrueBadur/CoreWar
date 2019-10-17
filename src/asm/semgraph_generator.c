
#include "libft.h"
#include "semantic_graph.h"


t_semnode	**generate_sem_graph()
{
	t_semnode	**sem_graph;

	sem_graph = malloc(sizeof(t_semnode) * 7);
	sem_graph[0] = create_node(BEGIN_ID, begin_func);
	sem_graph[1] = create_node(LABEL_ID, label_func);
	sem_graph[2] = create_node(ENDL_ID, NULL);
	sem_graph[3] = create_node(INST_ID, cmd_func);
	sem_graph[4] = create_node(PARAM_ID, param_func);
	sem_graph[5] = create_node(DELIM_ID, NULL);
	sem_graph[6] = create_node(END_ID, NULL);
	create_link(sem_graph[0], sem_graph[1]);
	create_link(sem_graph[0], sem_graph[3]);
	create_link(sem_graph[1], sem_graph[3]);
	create_link(sem_graph[1], sem_graph[2]);
	create_link(sem_graph[3], sem_graph[4]);
	create_link(sem_graph[2], sem_graph[3]);
	create_link(sem_graph[2], sem_graph[6]);
	create_link(sem_graph[2], sem_graph[2]);
	create_link(sem_graph[4], sem_graph[2]);
	create_link(sem_graph[4], sem_graph[5]);
    create_link(sem_graph[5], sem_graph[4]);

    create_link(sem_graph[6], sem_graph[0]);
    create_link(sem_graph[0], sem_graph[2]);

    return (sem_graph);
}

t_semnode	*look_for(t_semnode *from, char id)
{
	t_list_node	*cur_node;

	cur_node = from->links.begin;
	while (cur_node && ((t_semnode *)(cur_node->content))->req_type != id &&
	        ((t_semnode *)(cur_node->content))->req_type != END_ID &&
            ((t_semnode *)(cur_node->content))->req_type != BEGIN_ID)
		cur_node = cur_node->next;
	return (cur_node ? cur_node->content : NULL);
}

t_semnode	*create_node(char id, void (*op) (t_command *, t_token *))
{
	t_semnode	*res;

	res = ft_memalloc(sizeof(t_semnode));
	res->req_type = id;
	res->op = op;
	return (res);
}

void		create_link(t_semnode *from, t_semnode *to)
{
	t_list_node	*lstnode;

	lstnode = ft_memalloc(sizeof(t_list_node));
	lstnode->content = to;
	ft_lstadd(&(from->links), lstnode);
}

void		free_sem_graph(t_semnode **graph)
{
	int	cur;

	cur = 0;
	while (cur < 7)
		free(graph[cur++]);
	free(graph);
}

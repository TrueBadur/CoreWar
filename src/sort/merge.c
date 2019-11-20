/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blomo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 16:24:31 by ehugh-be          #+#    #+#             */
/*   Updated: 2019/11/13 20:11:41 by blomo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

#define SZ 10

int 	show(void *data)
{
	printf("%d -> ", *(int *)(data));
	return 0;
}

int 	lst_show_sub(void *data)
{
	t_list		*lst;
	t_list_node	*cur;
	t_list_node	*to_show;

	lst = (t_list *)data;
	cur = lst->begin;
	while (cur)
	{
		to_show = cur->content;
		while(to_show)
		{
			printf("%d -> ", *(int *)(to_show->content));
			to_show = to_show->next;
		}
		printf("\n");
		cur = cur->next;
	}
	return (0);
}

int 	show_sub(void *data)
{
	t_list_node	*cur;
	t_list_node	*to_show;

	cur = (t_list_node	*)data;
	while (cur)
	{
		printf("%d -> ", *(int *)(cur->content));
		cur = cur->next;
	}
	return (0);
}

int		nms_cnt_lst(t_list *control, t_list *to_sort)
{
	t_list_node	*node;
	t_list_node	*tmp;
	int 		idx;

	node = to_sort->begin;
	ft_lstaddend(control, ft_lstnew_noc(node, 0));
	tmp = node->next;
	idx = 0;
	while(tmp)
	{
		if (*(int *)tmp->content <= *(int *)node->content)
		{
			node->next = NULL;
			tmp->prev = NULL;
			ft_lstaddend(control, ft_lstnew_noc(tmp, 0));
		}
		node = tmp;
		tmp = node->next;
	}
	return (0);
}

int		condition(t_list_node *lf_tmp, t_list_node	*rg_tmp)
{
	if (*(int *)(lf_tmp->content) <= *(int *)(rg_tmp->content))
		return (1);
	else
		return (0);
}

void	merge(t_list_node *left, t_list_node *right, t_list *trash)
{
	t_list_node *str;
	t_list_node *yarn;
	t_list_node *lf_tmp;
	t_list_node *rg_tmp;
	char		yarn_state;
	char 		undone;

	lf_tmp = (t_list_node *)(left->content);
	rg_tmp = (t_list_node *)(right->content);
	undone = 1;

	if (condition(lf_tmp, rg_tmp))
	{
		str = lf_tmp;
		yarn = lf_tmp;
		lf_tmp = lf_tmp->next;
		yarn_state = -1;
		if (lf_tmp == NULL)
		{
			yarn->next = rg_tmp;
			rg_tmp->prev = yarn;
			undone = 0;
		}
	}
	else
	{
		str = rg_tmp;
		yarn = rg_tmp;
		rg_tmp = rg_tmp->next;
		yarn_state = 1;
		if (rg_tmp == NULL)
		{
			yarn->next = lf_tmp;
			lf_tmp->prev = yarn;
			undone = 0;
		}
	}

	while(undone)
	{
		if (yarn_state == 1)
		{
			if (condition(lf_tmp, rg_tmp))
			{
				yarn->next = lf_tmp;
				lf_tmp->prev = yarn;
				rg_tmp->prev = NULL;
				yarn_state = -1;
				yarn = lf_tmp;
				lf_tmp = lf_tmp->next;
				if (lf_tmp == NULL)
				{
					yarn->next = rg_tmp;
					rg_tmp->prev = yarn;
					break ;
				}
			}
			else
			{
				yarn = rg_tmp;
				rg_tmp = rg_tmp->next;
				if (rg_tmp == NULL)
				{
					yarn->next = lf_tmp;
					lf_tmp->prev = yarn;
					break ;
				}
			}
		}
		else
		{
			if (condition(lf_tmp, rg_tmp))
			{
				yarn = lf_tmp;
				lf_tmp = lf_tmp->next;
				if(lf_tmp == NULL)
				{
					yarn->next = rg_tmp;
					rg_tmp->prev = yarn;
					break ;
				}
			}
			else
			{
				yarn->next = rg_tmp;
				rg_tmp->prev = yarn;
				lf_tmp->prev = NULL;
				yarn_state = 1;
				yarn = rg_tmp;
				rg_tmp = rg_tmp->next;
				if (rg_tmp == NULL)
				{
					yarn->next = lf_tmp;
					lf_tmp->prev = yarn;
					break;
				}
			}
		}
	}

	left->content = NULL;
	right->content = str;
	if (left->content_size > right->content_size)
		right->content_size = left->content_size;
	right->content_size += 1;

	right->prev = left->prev;
	left->next = NULL;
	left->prev = NULL;
	ft_lstaddend(trash, left);
}

void	show_cs_from_back(t_list_node *node, t_list_node *end)
{
	printf("node: ");
	show_sub(node->content);
	printf("\n");
	while (end)
	{
		printf("%zu: ", end->content_size);
		show_sub(end->content);
		end = end->prev;
		printf("\n");
	}
	printf("\n");
}

void	show_elem(t_list_node *node)
{
	while (node)
	{
		printf("%d -> ", *(int *)(node->content));
		node = node->next;
	}
	printf("\n");
}

void	nms(t_list *to_sort)
{
	t_list		*control;
	t_list		*trash;
	t_list_node	*node;

	control = ft_lstinit();
	nms_cnt_lst(control, to_sort);

	printf("len=%zu\n", control->len);
	ft_lstiter(control, &show_sub); //show_sub(control);

	printf("next: sort\n\n");


	if (to_sort->len < 2)
		return;

	trash = ft_lstinit();
	node = control->begin;

	printf("next: sort init position\n\n");
	show_cs_from_back(node, control->end);
	printf("next: apply sort\n\n");
	while (1)
	{
		if (node->next == NULL && node->prev == NULL)
			break ;
		else if (node->prev == NULL)
			node = node->next;
		else if (node->next == NULL)
			merge(node->prev, node, trash);
		else if (node->content_size == node->prev->content_size)
			merge(node->prev, node, trash);
		else
			node = node->next;
		show_cs_from_back(node, control->end);
	}
	show_elem(node->content);
}

int main(void)
{
	t_list		*to_sort;
	t_list_node	*node;
	int 		idx;
	int tab[SZ] = {3, 4, 2, 1, 7, 5 , 8, 9, 0, 6};


	to_sort = ft_lstinit();
	node = NULL;
	idx = -1;
	while (++idx < SZ)
		ft_lstaddend(to_sort, ft_lstnew_noc(tab + idx, 0));
	ft_lstiter(to_sort, &show);
	printf("\n");
	printf("\n");
	nms(to_sort);

}

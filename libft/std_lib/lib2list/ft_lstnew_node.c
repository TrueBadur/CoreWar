/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_node.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehugh-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 23:19:26 by jleann            #+#    #+#             */
/*   Updated: 2019/10/14 21:57:10 by ehugh-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include "libft.h"

t_list_node				*ft_lstnew_node(void *content, size_t content_size)
{
	t_list_node	*res;

	res = malloc(sizeof(t_list));
	if (!res)
		return (NULL);
	if (content == NULL || content_size == 0)
	{
		res->content = NULL;
		res->content_size = 0;
		res->next = NULL;
		res->prev = NULL;
		return (res);
	}
	if (!(res->content = malloc(content_size)))
	{
		free(res);
		return (NULL);
	}
	ft_memcpy(res->content, content, content_size);
	res->content_size = content_size;
	res->next = NULL;
	res->prev = NULL;
	return (res);
}

t_list_node				*ft_lstnew_noc(void *content, size_t content_size)
{
	t_list_node	*res;

	res = ft_memalloc(sizeof(t_list));
	if (!res)
		return (NULL);
	res->content = content;
	res->content_size = content_size;
	return (res);
}
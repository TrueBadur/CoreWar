/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehugh-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 13:28:07 by ehugh-be          #+#    #+#             */
/*   Updated: 2018/11/27 19:17:42 by ehugh-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_list.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*new;

	if (!(new = malloc(sizeof(t_list))))
		return (NULL);
	new->content_size = content_size;
	new->data = NULL;
	if (!content)
		new->content_size = 0;
	else if (content_size <= sizeof(new->data))
		ft_memcpy(&new->data, content, content_size);
	else if (!(new->data = malloc(content_size)))
	{
		free(new);
		return (NULL);
	}
	else
		ft_memcpy(new->data, content, content_size);
	new->next = NULL;
	return (new);
}

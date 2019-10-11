/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfind.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehugh-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 23:22:20 by ehugh-be          #+#    #+#             */
/*   Updated: 2019/04/01 23:22:20 by ehugh-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_list.h"

t_list	*ft_lstfind_n(t_list *lst, int num)
{
	t_list	*ret;

	ret = lst;
	while (ret->next && num--)
		ret = ret->next;
	return (ret->next ? ret : NULL);
}

t_list	*ft_lstfindlast(t_list *lst)
{
	t_list *ret;

	ret = lst;
	while (ret->next)
		ret = ret->next;
	return (ret);
}

t_list	*ft_lstfind_v(t_list *lst, void *val, size_t s)
{
	t_list *ret;

	ret = lst;
	while (ret->next)
	{
		if (!ft_memcmp(val, ret->data, s < ret->content_size ? s :
		ret->content_size))
			return (ret);
	}
	return (NULL);
}

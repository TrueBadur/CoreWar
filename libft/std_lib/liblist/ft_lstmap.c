/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehugh-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 16:30:34 by ehugh-be          #+#    #+#             */
/*   Updated: 2018/11/27 19:04:03 by ehugh-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_list.h"

static void	*ft_dellst(t_list **lst)
{
	t_list *tmp;

	if (!lst)
		return (NULL);
	while (*lst)
	{
		free((*lst)->data);
		tmp = (*lst)->next;
		free(*lst);
		*lst = tmp;
	}
	return (NULL);
}

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *ret;
	t_list *ret_c;

	if (!lst || !f)
		return (NULL);
	if (!(ret = f(lst)))
		return (NULL);
	ret_c = ret;
	lst = lst->next;
	while (lst)
	{
		if (!(ret->next = f(lst)))
			return (ft_dellst(&ret_c));
		ret = ret->next;
		lst = lst->next;
	}
	return (ret_c);
}

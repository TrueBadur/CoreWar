/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstcopy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehugh-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 05:30:53 by ehugh-be          #+#    #+#             */
/*   Updated: 2019/04/05 05:30:53 by ehugh-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_list.h"

/*
** Function copy given list to a new one without coping content of the list
** nodes, so if some data stored in list node by reference new list node will
** reference to the very same data.
** @param lst pointer to the list to be copied
** @return pointer to newly created list
*/

t_list	*ft_lstcopy(t_list *lst)
{
	t_list *ret;
	t_list *tmp;

	if (!lst)
		return (NULL);
	ret = malloc(sizeof(t_list));
	tmp = ret;
	while (lst)
	{
		ft_memcpy(tmp, lst, sizeof(t_list));
		if ((lst = lst->next))
			tmp->next = malloc(sizeof(t_list));
		else
			tmp->next = NULL;
		tmp = tmp->next;
	}
	return (ret);
}

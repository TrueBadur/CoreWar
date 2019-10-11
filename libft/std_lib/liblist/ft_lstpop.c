/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehugh-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 13:47:57 by ehugh-be          #+#    #+#             */
/*   Updated: 2018/11/28 13:59:30 by ehugh-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_list.h"

void	*ft_lstpop(t_list **lst)
{
	void	*content;
	t_list	*lst_c;

	if (!lst || !*lst)
		return (NULL);
	content = (*lst)->data;
	lst_c = (*lst)->next;
	free(*lst);
	*lst = lst_c;
	return (content);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_delone.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehugh-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 13:50:44 by ehugh-be          #+#    #+#             */
/*   Updated: 2018/11/29 14:25:28 by ehugh-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_list.h"

void	ft_lstdelone(t_list **alst, void (*del)(void *, size_t))
{
	if (!alst || !*alst)
		return ;
	if (del)
		del((*alst)->data, (*alst)->content_size);
	else if ((*alst)->content_size > sizeof((*alst)->data))
		free((*alst)->data);
	free(*alst);
	*alst = NULL;
	alst = NULL;
}

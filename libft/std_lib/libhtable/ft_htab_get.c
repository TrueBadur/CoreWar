/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_htab_get.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehugh-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 20:16:44 by ehugh-be          #+#    #+#             */
/*   Updated: 2019/07/22 19:01:29 by ehugh-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define FT_HTABLE_MISC
#include "htable.h"

t_list	*htab_get_lst_strt(t_vector *table, size_t pos)
{
	return (*(t_list**)(table->data + pos * sizeof(void*)));
}

t_list	*htab_get_lst(t_htab *htab, char *key)
{
	t_list		*lst;
	t_bucket	*bckt;

	lst = htab_get_lst_strt(htab->table, hash(key) % htab->tabsize);
	while (lst)
	{
		bckt = ((t_bucket*)lst->data);
		if (ft_strcmp(bckt->key, key) == 0)
			return (lst);
		lst = lst->next;
	}
	return (NULL);
}

void	*ft_htab_get(t_htab *self, char *key)
{
	t_list	*ls;

	return ((ls = htab_get_lst(self, key)) ? ((t_bucket*)ls->data)->data : ls);
}

int		ft_htab_isin(t_htab *self, char *key)
{
	return (ft_htab_get(self, key) ? 1 : 0);
}

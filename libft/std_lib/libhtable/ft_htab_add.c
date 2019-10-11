/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_htab_add.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehugh-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 13:48:21 by ehugh-be          #+#    #+#             */
/*   Updated: 2019/07/22 21:38:05 by ehugh-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define FT_HTABLE_MISC
#include "htable.h"

/*
** Adds key-value pair to table. If given key is already exists in table,
** corresponding value will be replaced with new one and old value will be lost.
** That may cause memory leaks, so use pop or rem or isin methods of htab.
** @param self - htable to add key-value pair to.
** @param key - key with which to add value to table.
** @param data - value to add to table.
** @return - the same htab if everything went well and NULL if memory allocation
** went wrong. Corresponding errno set.
*/

t_htab	*ft_htab_add(t_htab *self, char *key, void *data)
{
	long		pos;
	t_list		*lst;

	if (((self->count + 1)) / (float)self->tabsize > 0.75)
		self = ft_htab_grow(self);
	if ((lst = htab_get_lst(self, key)))
	{
		((t_bucket*)lst->data)->data = data;
		return (self);
	}
	pos = hash(key) % self->tabsize;
	lst = htab_get_lst_strt(self->table, pos);
	ft_lstadd(&lst, ft_lstnew(&(t_bucket){key, data}, sizeof(t_bucket)));
	if (!(self->table = ft_vecput(self->table, pos * sizeof(void*),
			sizeof(t_list*), &lst)))
	{
		ft_htab_free(self);
		perror("ft_htab_add: vector reallocation failed");
		return (NULL);
	}
	self->tabsize = self->table->cap / sizeof(void*);
	self->count++;
	return (self);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_htab_pop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehugh-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 13:49:40 by ehugh-be          #+#    #+#             */
/*   Updated: 2019/07/22 19:06:52 by ehugh-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define FT_HTABLE_MISC
#include "htable.h"

t_list	*htab_rem_lst(t_list *lst, char *key, void **data)
{
	t_list	*ret;

	if (!lst)
		return (NULL);
	if (!ft_strcmp(((t_bucket*)lst->data)->key, key))
	{
		ret = lst->next;
		*data = (t_bucket*)lst->data;
		free(lst);
		return (ret);
	}
	ret = lst;
	lst = lst->next;
	while (lst->next)
	{
		if (!ft_strcmp(((t_bucket*)lst->next->data)->key, key))
		{
			*data = (t_bucket*)lst->next->data;
			*data = ft_replace_pointer(lst->next, lst->next->next);
			return (ret);
		}
		lst = lst->next;
	}
	return (ret);
}

void	*ft_htab_pop(t_htab **self, char *key)
{
	size_t	pos;
	void	*data;

	data = NULL;
	pos = hash(key) % (*self)->tabsize;
	if (!((*self)->table = ft_vecput((*self)->table, pos * sizeof(void*),
									sizeof(t_list*), &(void*){htab_rem_lst(
					htab_get_lst_strt((*self)->table, pos), key, &data)})))
	{
		ft_htab_free((*self));
		perror("ft_htab_add: vector reallocation failed table set to NULL");
		data = ft_replace_pointer(data, ((t_bucket*)data)->data);
		return (data);
	}
	(*self)->count = (*self)->count ? (*self)->count - 1 : (*self)->count;
	if ((*self)->count && (((*self)->count - 1)) /
											(float)(*self)->tabsize < 0.05)
		(*self) = ft_htab_shrink((*self));
	data = ft_replace_pointer(data, ((t_bucket*)data)->data);
	return (data);
}

t_htab	*ft_htab_rem(t_htab *self, char *key, void (*f)(void*))
{
	void *data;

	data = self->pop(&self, key);
	if (f)
		f(data);
	return (self);
}

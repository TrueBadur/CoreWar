/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_htab_rehash.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehugh-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 21:29:51 by ehugh-be          #+#    #+#             */
/*   Updated: 2019/07/22 21:30:20 by ehugh-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define FT_HTABLE_MISC
#include "htable.h"

unsigned long	hash(char *str)
{
	unsigned long	hash;
	unsigned int	c;

	hash = 0;
	while ((c = *str++))
		hash = c + (hash << 6) + (hash << 16) - hash;
	return (hash);
}

t_htab			*htab_rehash_copy(t_htab *htab, t_vector *tmp)
{
	t_list		*lst;
	size_t		pos;
	t_list		*tlst;
	t_list		*tmpl;

	htab->iter = 0;
	tmp->offset = tmp->len / sizeof(void*);
	while (tmp->offset--)
	{
		lst = htab_get_lst_strt(tmp, tmp->offset);
		while (lst)
		{
			pos = hash(((t_bucket*)(lst->data))->key) % htab->tabsize;
			tlst = htab_get_lst_strt(htab->table, pos);
			tmpl = lst->next;
			ft_lstadd(&tlst, lst);
			htab->table = ft_vecput(htab->table, pos * sizeof(void*),
					sizeof(void *), &tlst);
			lst = tmpl;
		}
	}
	ft_vecdel((void**)&tmp);
	return (htab);
}

t_htab			*ft_htab_shrink(t_htab *htab)
{
	t_vector	*tmp;

	tmp = htab->table;
	if (!(htab->table = ft_vecinit(htab->tabsize / 4 * sizeof(void*))))
	{
		ft_htab_free(htab);
		perror("ft_htab_grow: vector reallocation failed");
		return (NULL);
	}
	return (htab_rehash_copy(htab, tmp));
}

t_htab			*ft_htab_grow(t_htab *htab)
{
	t_vector	*tmp;

	tmp = htab->table;
	if (!(htab->table = ft_vecinit(htab->tabsize * sizeof(void*) * 4)))
	{
		ft_htab_free(htab);
		perror("ft_htab_grow: vector reallocation failed");
		return (NULL);
	}
	return (htab_rehash_copy(htab, tmp));
}

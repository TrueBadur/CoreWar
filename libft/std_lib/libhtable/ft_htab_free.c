/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_htab_free.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehugh-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 17:22:17 by ehugh-be          #+#    #+#             */
/*   Updated: 2019/07/22 21:23:29 by ehugh-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define FT_HTABLE_MISC
#include "htable.h"

/*
** Frees htab assuming that all data in it, keys as well as values, are already
** freed, so it doesn't manage those.
** @param htab - table to be freed
*/

void	ft_htab_free(t_htab *htab)
{
	t_list	*lst;
	size_t	i;

	i = 0;
	while (i < htab->tabsize)
	{
		lst = *(t_list**)(htab->table->data + i++ * sizeof(void*));
		ft_lstdel(&lst, NULL);
	}
	ft_vecdel((void*)&(htab->table));
	free(htab);
}

void	ft_htab_free_helper(t_htab *htab, void (*key_free)(void*),
		void (*val_free)(void*))
{
	char	*key;
	void	*val;

	if (!key_free && !val_free)
		return (ft_htab_free(htab));
	while (htab->next(htab, &key, &val))
	{
		if (key_free)
			key_free(key);
		if (val_free)
			val_free(val);
	}
	ft_htab_free(htab);
}

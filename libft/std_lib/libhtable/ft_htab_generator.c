/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_htab_generator.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehugh-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 17:28:16 by ehugh-be          #+#    #+#             */
/*   Updated: 2019/07/22 21:34:46 by ehugh-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define FT_HTABLE_MISC
#include "htable.h"

/*
** Iterates over htab placing one key value pair in corresponding double pointed
** variables at a time.
** @param htab - table to iterate over
** @param key - where to place pointer to key of pair
** @param value - where to place pointer to value of pair
** @return - 0 if iteration is complete and 1 if it is still going
*/

int			ft_htab_generator(t_htab *htab, char **key, void **value)
{
	t_list		*lst;
	t_bucket	*bckt;

	lst = htab->iterator_list;
	while (htab->iter < htab->tabsize)
	{
		if (!lst)
			lst = *(t_list**)(htab->table->data + htab->iter++ * sizeof(void*));
		if (lst)
		{
			bckt = lst->data;
			if (bckt)
			{
				if (value)
					*value = bckt->data;
				if (key)
					*key = bckt->key;
				htab->iterator_list = lst->next;
				return (1);
			}
		}
	}
	htab->iter = 0;
	return (0);
}

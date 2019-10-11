/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_avlsearch.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehugh-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 18:43:37 by ehugh-be          #+#    #+#             */
/*   Updated: 2019/07/10 17:06:19 by ehugh-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define FT_SOURCE_BTAVL
#include "btavl.h"

t_btavl	*ft_avlmin(t_btavl *tr)
{
	while (tr->left)
		tr = tr->left;
	return (tr);
}

t_btavl	*ft_avlmax(t_btavl *tr)
{
	while (tr->right)
		tr = tr->right;
	return (tr);
}

/*
** @param tr - tree to search through
** @param key - what key to find in tree
** @param ret_d - specifies what to return: data(1) or node(0) associated with
** 						key
** @return - if key is found then return ret_d associated with this key, NULL
** otherwise
*/

void	*ft_avlsearch(t_btavl *tr, void *key, int ret_d, int (f)(void*, void*))
{
	int cmp;

	if (!tr || (tr->key_type == OTHER && !f))
		return (NULL);
	cmp = ft_avl_keycmp(tr->key, key, tr->key_type, f);
	if (cmp == 0)
		return (ret_d ? tr->data : tr);
	if (cmp > 0)
		return (ft_avlsearch(tr->left, key, ret_d, f));
	else
		return (ft_avlsearch(tr->right, key, ret_d, f));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_avlrm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehugh-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 16:55:58 by ehugh-be          #+#    #+#             */
/*   Updated: 2019/07/10 15:18:44 by ehugh-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define FT_SOURCE_BTAVL
#include "btavl.h"

static t_btavl	*ft_avlrmmin(t_btavl *tr)
{
	t_btavl	*tmp;

	if (!tr->left)
		return (tr);
	tmp = ft_avlrmmin(tr->left);
	tr->left = tmp->right;
	tmp->right = ft_avlbal(tr);
	return (tmp);
}

t_btavl			*ft_avlrem(t_btavl *tr, void *key, void (*f)(void **),
		int (f_c)(void*, void*))
{
	t_btavl *tmp;
	int		cmp;

	if (!tr)
		return (NULL);
	cmp = ft_avl_keycmp(tr->key, key, tr->key_type, f_c);
	if (cmp == 0)
	{
		f(&(tr->data));
		if (!tr->right)
		{
			tmp = tr->left;
			free(tr);
			return (tmp);
		}
		tmp = ft_avlrmmin(tr->right);
		tmp->left = tr->left;
		free(tr);
		return (ft_avlbal(tmp));
	}
	else if (cmp == 1)
		tr->left = ft_avlrem(tr->left, key, f, f_c);
	else
		tr->right = ft_avlrem(tr->right, key, f, f_c);
	return (ft_avlbal(tr));
}

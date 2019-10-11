/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_avlins.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehugh-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 15:28:41 by ehugh-be          #+#    #+#             */
/*   Updated: 2019/07/10 16:24:42 by ehugh-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define FT_SOURCE_BTAVL
#include "btavl.h"


/*
** @param tr - libavl tree to which insert new node
** @param node - node to insert
** @return - pointer to balanced libavl tree with inserted node
*/

t_btavl	*ft_avlins(t_btavl *tr, t_btavl *node, int (f)(void*, void*))
{
	int	cmp;
	if (!node)
		return (tr);
	if (!tr)
		return (node);
	if (tr->key_type != node->key_type)
		return (NULL);
	cmp = ft_avl_keycmp(tr->key, node->key, tr->key_type, f);
	if (cmp == 0)
		return (tr);
	if (cmp > 0)
		tr->left = ft_avlins(tr->left, node, f);
	else
		tr->right = ft_avlins(tr->right, node, f);
	return (ft_avlbal(tr));
}

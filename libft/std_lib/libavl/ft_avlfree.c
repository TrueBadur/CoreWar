/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_avlfree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehugh-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 15:36:52 by ehugh-be          #+#    #+#             */
/*   Updated: 2018/12/06 17:56:38 by ehugh-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "btavl.h"

/*
** Frees the tree and its data. Keys aren't freed
** @param tr - tree to be freed
** @return - NULL pointer to be assigned to where tree was stored before
*/

t_btavl	*ft_avlfree(t_btavl *tr)
{
	return (ft_avlfree_custom(tr, NULL));
}

/*
** Frees the tree but data is freed with given function
*/

t_btavl	*ft_avlfree_custom(t_btavl *tr, void (free_data)(void*))
{
	if (!tr)
		return (NULL);
	if (tr->left)
		ft_avlfree_custom(tr->left, free_data);
	if (tr->right)
		ft_avlfree_custom(tr->right, free_data);
	if (!free_data)
		free(tr->data);
	else
		free_data(tr->data);
	free(tr);
	return (NULL);
}

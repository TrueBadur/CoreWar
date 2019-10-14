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
** @param tr - tree to be freed
** @return - NULL pointer to be assigned to where tree was stored before
*/

t_btavl	*ft_avlfree(t_btavl *tr)
{
	return (ft_avlfree_custom(tr, NULL));
}

t_btavl	*ft_avlfree_custom(t_btavl *tr, void (f)(void*))
{
	if (!tr)
		return (NULL);
	if (tr->left)
		ft_avlfree_custom(tr->left, f);
	if (tr->right)
		ft_avlfree_custom(tr->right, f);
	if (!f)
		free(tr->data);
	else
		f(tr->data);
	free(tr);
	return (NULL);
}

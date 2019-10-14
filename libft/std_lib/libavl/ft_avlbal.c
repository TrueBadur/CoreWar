/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_avlbal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehugh-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 13:52:36 by ehugh-be          #+#    #+#             */
/*   Updated: 2018/12/06 18:02:00 by ehugh-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define FT_SOURCE_BTAVL
#include "btavl.h"

t_btavl	*ft_avlbal(t_btavl *tr)
{
	ft_avlfixh(tr);
	if (ft_avlbfact(tr) == 2)
	{
		if (ft_avlbfact(tr->right) < 0)
			tr->right = ft_avlrr(tr->right);
		return (ft_avlrl(tr));
	}
	if (ft_avlbfact(tr) == -2)
	{
		if (ft_avlbfact(tr->left) > 0)
			tr->left = ft_avlrl(tr->left);
		return (ft_avlrr(tr));
	}
	return (tr);
}

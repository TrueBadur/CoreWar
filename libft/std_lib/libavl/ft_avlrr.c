/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_avlrr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehugh-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 13:30:48 by ehugh-be          #+#    #+#             */
/*   Updated: 2018/12/07 02:36:14 by ehugh-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define FT_SOURCE_BTAVL
#include "btavl.h"

t_btavl	*ft_avlrr(t_btavl *tr)
{
	t_btavl *tmp;

	if (!tr)
		return (NULL);
	tmp = tr->left;
	tr->left = tmp->right;
	tmp->right = tr;
	ft_avlfixh(tr);
	ft_avlfixh(tmp);
	return (tmp);
}

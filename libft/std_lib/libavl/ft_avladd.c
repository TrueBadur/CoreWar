/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_avladd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehugh-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 14:12:51 by ehugh-be          #+#    #+#             */
/*   Updated: 2018/12/04 15:58:41 by ehugh-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "btavl.h"

void	ft_avladd(t_btavl **tr, t_btavl *leaf, int (*f)(void *, void *, size_t))
{
	if (!tr)
		return ;
	if (!*tr)
	{
		*tr = leaf;
		return ;
	}
	if (f((*tr)->data, leaf->data, leaf->size) < 0)
		ft_avladd(&((*tr)->left), leaf, f);
	else
		ft_avladd(&((*tr)->right), leaf, f);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_avlfixh.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehugh-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 13:19:22 by ehugh-be          #+#    #+#             */
/*   Updated: 2018/12/07 02:35:11 by ehugh-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define FT_SOURCE_BTAVL
#include "btavl.h"

void	ft_avlfixh(t_btavl *tr)
{
	unsigned char rh;
	unsigned char lh;

	if (!tr)
		return ;
	rh = ft_avlh(tr->right);
	lh = ft_avlh(tr->left);
	tr->h = ((rh > lh) ? rh : lh) + 1;
}

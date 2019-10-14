/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtrx_identity.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehugh-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 07:22:29 by ehugh-be          #+#    #+#             */
/*   Updated: 2019/01/12 12:21:16 by ehugh-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mtrx.h"

t_mtrx	*ft_mtrx_ident(int w, unsigned char el_size)
{
	t_mtrx	*ret;
	int		t;

	if (!w)
		return (NULL);
	ret = ft_mtrx_init(w, w, el_size);
	t = w;
	if (el_size == MTRX_DOUBLE)
		while (t--)
			((double *)ret->mtrx)[t * ret->w + t] = 1.0f;
	else
		while (t--)
			((int *)ret->mtrx)[t * ret->w + t] = 1;
	return (ret);
}

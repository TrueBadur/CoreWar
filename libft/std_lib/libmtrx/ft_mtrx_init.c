/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtrx_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehugh-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 22:27:24 by ehugh-be          #+#    #+#             */
/*   Updated: 2019/01/11 03:29:44 by ehugh-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mtrx.h"

t_mtrx	*ft_mtrx_init(int w, int h, unsigned char el_size)
{
	t_mtrx	*ret;
	char	t;

	if (!(ret = malloc(sizeof(t_mtrx))))
		return (NULL);
	if (el_size == MTRX_INT)
		t = sizeof(int);
	else if (el_size == MTRX_DOUBLE)
		t = sizeof(double);
	else
		t = sizeof(float);
	if (!(ret->mtrx = malloc(w * h * t)))
	{
		free(ret);
		return (NULL);
	}
	ret->w = w;
	ret->h = h;
	ret->el_size = el_size;
	ft_bzero(ret->mtrx, w * h * t);
	return (ret);
}

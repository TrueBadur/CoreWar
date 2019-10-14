/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vecshrink.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehugh-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 17:58:28 by ehugh-be          #+#    #+#             */
/*   Updated: 2018/12/04 03:50:56 by ehugh-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_vector	*ft_vecremove(t_vector *vec, size_t strt, size_t s)
{
	if (!vec)
		return (t_vector*)(NULL);
	if (strt > vec->len)
		return (vec);
	if (strt + s > vec->len)
		vec->len = strt;
	else
	{
		ft_memmove(vec->data + strt, vec->data + strt + s, vec->len - strt - s);
		vec->len -= s;
	}
	return (ft_vecshrink(vec, 0));
}

t_vector	*ft_vecshrink(t_vector *vec, unsigned int offset)
{
	void *tmp;

	if (!vec)
		return (t_vector*)(NULL);
	if (!offset && (vec->len >= vec->cap / 4 || vec->len == 0))
		return (vec);
	tmp = vec->data;
	if (!(vec->data = malloc(vec->cap / 2)))
	{
		free(tmp);
		free(vec);
		return (t_vector*)(NULL);
	}
	if (offset)
	{
		ft_memcpy(vec->data, tmp + offset, vec->len - offset);
		vec->len -= vec->offset;
		vec->offset = 0;
	}
	else
		ft_memcpy(vec->data, tmp, vec->len);
	free(tmp);
	vec->cap /= 2;
	return (vec);
}

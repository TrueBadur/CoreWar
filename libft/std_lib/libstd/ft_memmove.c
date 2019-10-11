/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehugh-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 17:01:53 by ehugh-be          #+#    #+#             */
/*   Updated: 2018/12/06 19:36:36 by ehugh-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*dst_c;
	char	*src_c;

	if (dst == src)
		return (dst);
	dst_c = (char*)dst;
	src_c = (char*)src;
	if (dst > src)
	{
		while (len--)
			dst_c[len] = src_c[len];
	}
	else
	{
		while (len--)
			*dst_c++ = *src_c++;
	}
	return (dst);
}

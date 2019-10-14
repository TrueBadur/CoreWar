/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehugh-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 22:22:28 by ehugh-be          #+#    #+#             */
/*   Updated: 2018/11/26 23:23:18 by ehugh-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, void const *src, int c, size_t n)
{
	int				i;
	unsigned char	*dst_c;
	unsigned char	*src_c;

	i = 0;
	dst_c = (unsigned char *)dst;
	src_c = (unsigned char *)src;
	while ((size_t)i < n)
	{
		*(dst_c + i) = *(src_c + i);
		if (*(src_c + i) == (unsigned char)c)
			return (dst + i + 1);
		i++;
	}
	return (NULL);
}

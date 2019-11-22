/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehugh-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 17:01:53 by ehugh-be          #+#    #+#             */
/*   Updated: 2019/11/22 11:36:19 by ehugh-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	if (dst == src)
		return (dst);
	if (dst > src)
	{
		while (len >= sizeof(void*))
		{
			len -= sizeof(void*);
			*((void**)(dst + len)) = *((void**)(src + len));
		}
		while (len--)
			*((char*)(dst + len)) = *((char*)(src + len));
	}
	else
	{
		while (len >= sizeof(void*))
		{
			*((void **)dst) = *((void **)src);
			dst += sizeof(void*);
			src += sizeof(void*);
			len -= sizeof(void*);
		}
		while (len--)
			*(char*)dst++ = *(char*)src++;
	}
	return (dst);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehugh-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 20:20:32 by ehugh-be          #+#    #+#             */
/*   Updated: 2018/11/28 15:55:45 by ehugh-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	while (*dst && i < size)
	{
		dst++;
		i++;
	}
	if (*dst)
		return (i + ft_strlen(src));
	while (++i < size && *src)
		*dst++ = *src++;
	*dst = '\0';
	return (--i + ft_strlen(src));
}

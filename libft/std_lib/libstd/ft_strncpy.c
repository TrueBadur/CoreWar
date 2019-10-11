/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epouros <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 14:10:49 by epouros           #+#    #+#             */
/*   Updated: 2018/11/21 17:54:05 by ehugh-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, char const *src, size_t len)
{
	size_t	cnt;
	char	*ret;

	ret = dst;
	cnt = 0;
	while (cnt < len)
	{
		if (*src)
		{
			*dst = *src;
			src++;
		}
		else
			*dst = '\0';
		dst++;
		cnt++;
	}
	return (ret);
}

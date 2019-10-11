/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehugh-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 23:20:04 by ehugh-be          #+#    #+#             */
/*   Updated: 2018/11/26 21:05:58 by ehugh-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(void const *s, int c, size_t n)
{
	unsigned char *s_c;

	s_c = (unsigned char *)s;
	while (n--)
	{
		if (*(s_c) == (unsigned char)c)
			return (s_c);
		s_c++;
	}
	return (NULL);
}

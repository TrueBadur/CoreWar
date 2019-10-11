/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehugh-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 02:22:22 by ehugh-be          #+#    #+#             */
/*   Updated: 2018/11/23 02:39:58 by ehugh-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char *ret;

	ret = NULL;
	while (*s)
	{
		if (*s == (char)c)
			ret = (char *)s;
		s++;
	}
	if (*s == (char)c)
		ret = (char*)s;
	return (ret);
}

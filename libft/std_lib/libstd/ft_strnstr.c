/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehugh-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 03:40:15 by ehugh-be          #+#    #+#             */
/*   Updated: 2018/11/27 16:03:56 by ehugh-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*str_c;
	char	*to_find_c;
	size_t	i;

	str_c = (char *)haystack;
	to_find_c = (char *)needle;
	i = len;
	while (1)
	{
		if (*needle == '\0')
			return (str_c);
		if (!len)
			return (NULL);
		if (*haystack == 0)
			return (NULL);
		else if (*haystack++ != *needle++)
		{
			haystack = ++str_c;
			needle = to_find_c;
			len = i--;
		}
		if (!len--)
			return (NULL);
	}
}

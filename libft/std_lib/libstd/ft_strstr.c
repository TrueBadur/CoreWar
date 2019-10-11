/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehugh-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 18:15:15 by ehugh-be          #+#    #+#             */
/*   Updated: 2018/11/23 02:58:44 by ehugh-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	char *str_c;
	char *to_find_c;

	str_c = (char *)haystack;
	to_find_c = (char *)needle;
	while (1)
	{
		if (*needle == 0)
			return (str_c);
		else if (*haystack == 0)
			return (NULL);
		else if (*haystack++ != *needle++)
		{
			haystack = ++str_c;
			needle = to_find_c;
		}
	}
}

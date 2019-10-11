/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehugh-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 07:53:02 by ehugh-be          #+#    #+#             */
/*   Updated: 2018/11/23 22:33:11 by ehugh-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char *ret;

	if (!s)
		return (NULL);
	if (!(ret = malloc(len + 1)))
		return (NULL);
	ret = ft_strncpy(ret, s + start, len);
	*(ret + len) = '\0';
	return (ret);
}

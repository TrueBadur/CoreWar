/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehugh-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 08:58:34 by ehugh-be          #+#    #+#             */
/*   Updated: 2019/07/11 16:17:01 by ehugh-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	len;

	if (!s)
		return (NULL);
	while (*s && ft_isspace(*s))
		s++;
	len = ft_strlen(s);
	while (len > 0 && (ft_isspace(*(s + len - 1))))
		len--;
	if (len <= 0)
		return (ft_strnew(1));
	return (ft_strsub(s, 0, len));
}

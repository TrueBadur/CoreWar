/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehugh-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 06:40:35 by ehugh-be          #+#    #+#             */
/*   Updated: 2018/11/24 00:02:04 by ehugh-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*ret;
	char	*ret_c;
	int		i;

	if (!s || !f)
		return (NULL);
	i = 0;
	if (!(ret = malloc(ft_strlen(s) + 1)))
		return (NULL);
	ret_c = ret;
	while (*s)
	{
		*ret++ = f(i++, *s++);
	}
	*ret = '\0';
	return (ret_c);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehugh-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 08:11:14 by ehugh-be          #+#    #+#             */
/*   Updated: 2018/12/03 18:09:23 by ehugh-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ret;
	int		i;
	int		j;

	if (!s1 && !s2)
		return (NULL);
	i = (s1) ? ft_strlen(s1) : 0;
	j = (s2) ? ft_strlen(s2) : 0;
	if (!(ret = malloc(i + j + 1)))
		return (NULL);
	*ret = '\0';
	if (i)
		ft_strncpy(ret, s1, i + 1);
	if (j)
		ft_strlcat(ret, s2, i + j + 1);
	return (ret);
}

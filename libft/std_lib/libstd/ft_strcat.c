/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strcat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehugh-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 19:03:18 by ehugh-be          #+#    #+#             */
/*   Updated: 2018/11/22 19:29:39 by ehugh-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	char	*s1_c;

	s1_c = s1;
	while (*s1_c)
		s1_c++;
	while (*s2)
		*s1_c++ = *s2++;
	*s1_c = '\0';
	return (s1);
}

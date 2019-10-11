/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehugh-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 05:43:05 by ehugh-be          #+#    #+#             */
/*   Updated: 2018/11/23 08:10:13 by ehugh-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char *ret;

	if (size + 1 == 0)
		return (NULL);
	if (!(ret = malloc(sizeof(char) * (size + 1))))
		return (NULL);
	ft_bzero(ret, size + 1);
	return (ret);
}

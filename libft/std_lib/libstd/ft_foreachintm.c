/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_foreachintm.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehugh-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 14:28:56 by ehugh-be          #+#    #+#             */
/*   Updated: 2018/11/28 14:37:39 by ehugh-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	*ft_foreachintm(const int *arr, size_t len, int (*f)(int))
{
	int		*ret;
	size_t	i;

	if (!arr)
		return (NULL);
	if (!(ret = malloc(sizeof(int) * len)))
		return (NULL);
	i = 0;
	while (i < len)
	{
		ret[i] = f(arr[i]);
		i++;
	}
	return (ret);
}

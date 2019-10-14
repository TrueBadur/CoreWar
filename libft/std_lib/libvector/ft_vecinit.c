/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vecinit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehugh-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 13:26:38 by ehugh-be          #+#    #+#             */
/*   Updated: 2018/12/04 03:23:06 by ehugh-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_vector	*ft_vecinit(size_t cap)
{
	t_vector *ret;

	if (!cap || !(ret = malloc(sizeof(t_vector))))
		return (NULL);
	if (!(ret->data = malloc(cap)))
	{
		free(ret);
		return (NULL);
	}
	ft_bzero(ret->data, cap);
	ret->len = 0;
	ret->cap = cap;
	ret->offset = 0;
	return (ret);
}

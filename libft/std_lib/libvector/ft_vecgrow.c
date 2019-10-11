/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vecpush.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehugh-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 15:52:30 by ehugh-be          #+#    #+#             */
/*   Updated: 2018/12/29 23:16:52 by ehugh-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_vector	*ft_vecgrow(t_vector *vec, size_t s)
{
	void	*data_c;

	if (!vec)
		return (NULL);
	s = (s > vec->cap) ? s : vec->cap * 2;
	data_c = vec->data;
	if (!(vec->data = malloc(s)))
	{
		free(data_c);
		free(vec);
		return (NULL);
	}
	vec->cap = s;
	ft_memcpy(vec->data, data_c, vec->len);
	free(data_c);
	return (vec);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec_put.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehugh-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 16:37:21 by ehugh-be          #+#    #+#             */
/*   Updated: 2019/11/09 18:38:33 by ehugh-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Copies size bytes from the place pointed by data in vector starting from pos
** position. No checks of overriding old data is made.
** @param vec - vector where to put data
** @param pos - position in vector from where to place data
** @param size - size of data to be putted
** @param data - pointer to data which will be copied in vector
** @return - pointer to vector with data putted in it
*/

t_vector	*ft_vecput(t_vector *vec, size_t pos, size_t size, void *data)
{
	while (pos + size > vec->cap)
		if (!(vec = ft_vecgrow(vec, vec->cap * 2)))
			return (NULL);
	ft_memcpy(vec->data + pos, data, size);
	if (pos + size > vec->len)
		vec->len = pos + size;
	return (vec);
}


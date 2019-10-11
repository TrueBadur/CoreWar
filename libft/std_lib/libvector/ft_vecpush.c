/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vecpush.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbartole <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 17:58:28 by ehugh-be          #+#    #+#             */
/*   Updated: 2019/07/11 15:10:34 by mbartole         ###   ########.fr       */
/*   Updated: 2019/05/28 18:30:20 by ehugh-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Add data of size s to the end of the vector resizing vector if needed.
** @param vec - vector to push data into
** @param data - data to be added to vector
** @param s - size of data to be added
** @return vector with added data it may be new vector
*/

t_vector	*ft_vecpush(t_vector *vec, void *data, size_t s)
{
	unsigned int	it;

	if (!vec)
		return (t_vector*)(NULL);
	if (!data || !s)
		return (vec);
	it = vec->cap;
	while (s > it - vec->len)
		it *= 2;
	if ((it > vec->cap) && !(vec = ft_vecgrow(vec, it)))
		return (NULL);
	ft_memcpy(vec->data + vec->len, data, s);
	vec->len += s;
	vec->cap = it;
	return (vec);
}

/*
** Add data of size less or equals to long into vec (may be useful to insert
** constants or enums to vectors without need to create additional variable)
**
** @param vec	-	vector to push data into
** @param data	-	data to be added to vector
** @param s		-	size of data to be added
** @return		-	vector with added data it may be new vector
*/

t_vector	*ft_vecpush_small(t_vector *vec, long data, size_t s)
{
	return (ft_vecpush(vec, &data, s));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blomo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 22:07:46 by ehugh-be          #+#    #+#             */
/*   Updated: 2019/11/13 19:18:01 by blomo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

#define DGT_CAR_IND(x) ((int)(((t_car**)(vec->data))[x]->id / place) % 10)

t_vector		*counting_sort(t_vector *vec, size_t size, int place,
		t_mngr *mngr)
{
	t_vector	*tmp;
	int			count[11];
	int			max;
	int			i;

	max = 9;
	ft_bzero(count, sizeof(count));
	i = -1;
	while (++i < size)
		count[DGT_CAR_IND(i)]++;
	i = 0;
	while (++i <= max)
		count[i] += count[i - 1];
	i = size;
	while (--i > -1)
	{
		mngr->rxsort_out = ft_vecput(mngr->rxsort_out,
				(count[DGT_CAR_IND(i)] - 1) * sizeof(void*),
				sizeof(void*), &((t_car**)(vec->data))[i]);
		count[DGT_CAR_IND(i)]--;
	}
	tmp = mngr->rxsort_out;
	mngr->rxsort_out = vec;
	vec->len = 0;
	return (tmp);
}

t_vector		*vm_radixsort(t_vector *vec, size_t size, t_mngr *mngr)
{
	int			max;
	int			place;

	max = -vec->offset;
	place = 1;
	while (max / place > 0)
	{
		vec = counting_sort(vec, size, place, mngr);
		place *= 10;
	}
	return (vec);
}

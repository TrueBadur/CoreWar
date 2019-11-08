/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehugh-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 22:07:46 by ehugh-be          #+#    #+#             */
/*   Updated: 2019/11/08 18:39:44 by ehugh-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

//int getMax(int array[], int n)
//{
//	int max = array[0];
//	for (int i = 1; i < n; i++)
//		if (array[i] > max)
//			max = array[i];
//	return max;
//}
//void countingSort(int array[], int size, int place)
//{
//	int output[size + 1];
//	int max = (array[0] / place) % 10;
//	for (int i = 1; i < size; i++)
//	{
//		if (((array[i] / place) % 10) > max)
//			max = (array[0] / place) % 10;
//	}
//	int count[max + 1];
//	for (int i = 0; i < max; ++i)
//		count[i] = 0;
//	for (int i = 0; i < size; i++)
//		count[(array[i] / place) % 10]++;
//	for (int i = 1; i < max; i++)
//		count[max - i - 1] += count[i - 1];
//	for (int i = size - 1; i >= 0; i--)
//	{
//		output[count[(array[i] / place) % 10] - 1] = array[i];
//		count[(array[i] / place) % 10]--;
//	}
//	for (int i = 0; i < size; i++)
//		array[i] = output[i];
//}

#define DGT_CAR_IND(x) ((int)(((t_car**)(vec->data))[x]->id / place) % 10)

t_vector	*counting_sort(t_vector *vec, size_t size, int place, t_mngr *mngr)
{
	t_vector	*tmp;
	int count[11];
	int max;
	int i;

	max = DGT_CAR_IND(0);
	i = 0;
	while (++i < size)
		if (DGT_CAR_IND(i) > max)
			max = DGT_CAR_IND(i);
	ft_bzero(count, sizeof(count));
	i = -1;
	while (++i < size)
		count[DGT_CAR_IND(i)]++;
	i = 0;
	while (++i < max)
		count[max - i - 1] += count[i - 1];
	i = size;
	while (--i)
	{
		ft_vecput(mngr->rxsort_out, (count[DGT_CAR_IND(i)] - 1) * sizeof(void*),
				  sizeof(void*), ((t_car**)(vec->data))[i]);
		t_car **t = mngr->rxsort_out->data;
		t_car **t1 = vec->data;
		count[DGT_CAR_IND(i)]--;
	}
	tmp = mngr->rxsort_out;
	mngr->rxsort_out = vec;
	vec->len = 0;
	return (tmp);
}

t_vector	*vm_radixsort(t_vector *vec, size_t size, t_mngr *mngr)
{
	int max;
	int place;

	max = mngr->num_cars;
	place = 1;
	while (max / place > 0)
	{
		vec = counting_sort(vec, size, place, mngr);
		t_car **tmp = vec->data;
		place *= 10;
	}
	vec->offset = ((t_car*)(vec->data + vec->len - sizeof(void*)))->id;
	return (vec);
}

//void radixsort(t_vector *vec, int size)
//{
//	int max = getMax(array, size);
//	for (int place = 1; max / place > 0; place *= 10)
//		countingSort(array, size, place);
//}


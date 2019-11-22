/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_timsort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehugh-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 12:08:30 by ehugh-be          #+#    #+#             */
/*   Updated: 2019/11/22 13:11:42 by ehugh-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sort.h"
#include "corewar.h"

static unsigned short	get_minrun(size_t len)
{
	unsigned char	r;

	r = 0;
	while (len >= 64)
	{
		r |= len & 1u;
		len >>= 1u;
	}
	return ((unsigned short)(len + r));
}

t_timsort				*init_timsort(void *data, size_t size, size_t el_size,
		int (compare)(void*, void*))
{
	t_timsort *ts;

	if (!(ts = malloc(sizeof(t_timsort))))
		return (NULL);
	ts->dta = data;
	ts->elsz = el_size;
	ts->size = size;
	ts->cmp = compare;
	ts->minrun = get_minrun(EL_NUM);
	if (!(ts->rn_szs = malloc(sizeof(t_int2) * (EL_NUM / ts->minrun + 2))))
		return (NULL);
	ts->rn_szs[0] = (t_int2){0, 0};
	ts->rns_s = 0;
	return (ts);
}


int						ft_timsort(void *data, size_t size, size_t el_size,
		int (compare)(void*, void*))
{
	t_timsort	*ts;
	int			i;
	t_int2		cur_run;

	if (size % el_size)
		return (1);
	if (size / el_size == 1)
		return (0);
	if (!(ts = init_timsort(data, size, el_size, compare)))
		return (1);
	i = EL_NUM;
	cur_run = ts->rn_szs[0];
	while (i > 0)
	{
		cur_run = get_run(ts, cur_run, i);
		i -= VEC2_RNG(cur_run);
		ts->rn_szs[ts->rns_s++] = cur_run;
		if (merge_collapse(ts))
			return (1);
		cur_run = (t_int2){ts->rn_szs[ts->rns_s - 1].y,
					ts->rn_szs[ts->rns_s - 1].y};
	}
	while (ts->rns_s > 1)
		merge_runs(ts, 2);
	free(ts->rn_szs);
	free(ts);
	return (0);
}

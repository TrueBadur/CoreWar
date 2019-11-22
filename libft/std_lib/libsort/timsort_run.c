/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timsort_run.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehugh-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 11:16:34 by ehugh-be          #+#    #+#             */
/*   Updated: 2019/11/22 13:16:57 by ehugh-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sort.h"

int			count_run(t_timsort *tsort, size_t offset)
{
	size_t	i;
	int		asc;
	int		tmp;

	i = offset;
	if (tsort->size / tsort->elsz - offset < 2)
		return (1);
	asc = (tsort->cmp(tsort->dta + offset * tsort->elsz, tsort->dta +
	(offset + 1) * tsort->elsz) <= 0);
	while (++i < (tsort->size / tsort->elsz) - 1 && i - offset < tsort->minrun)
	{
		tmp = tsort->cmp(tsort->dta + i * tsort->elsz, tsort->dta +
													(i + 1) * tsort->elsz);
		if ((asc && tmp > 0) || (!asc && tmp < 1))
			break ;
	}
	return ((i + 1 - offset) * (asc ? 1 : -1));
}

t_int2		reverse_run(t_timsort *ts, t_int2 rng)
{
	int i;
	int len;

	i = -1;
	len = ft_abs(VEC2_RNG(rng));
	while (++i < len / 2)
		ft_memswap(ts->dta + rng.x * ts->elsz + i * ts->elsz,
			ts->dta + rng.x * ts->elsz + (len - i - 1) * ts->elsz, ts->elsz);
	return ((t_int2){rng.x, rng.y + ft_abs(VEC2_RNG(rng)) * 2});
}

int			boost_run(t_timsort *ts, int st, int cur, int end)
{
	char	tmp[ts->elsz];
	void	*ins_place;

	while (cur < end)
	{
		ins_place = ft_bisect_right(ts->dta + st * ts->elsz,
	ts->dta + cur * ts->elsz, (t_uint2) {ts->elsz, cur - st}, ts->cmp);
		if (ins_place != ts->dta + cur * ts->elsz)
		{
			ft_memcpy(tmp, ts->dta + cur * ts->elsz, ts->elsz);
			ft_memmove(ins_place + ts->elsz, ins_place,
					ts->dta + ts->elsz * cur - ins_place);
			ft_memcpy(ins_place, tmp, ts->elsz);
		}
		cur++;
	}
	return (cur);
}

t_int2		get_run(t_timsort *ts, t_int2 cur_run, int i)
{
	cur_run.y += count_run(ts, EL_NUM - i);
	if (VEC2_RNG(cur_run) < 0)
		cur_run = reverse_run(ts, cur_run);
	if (VEC2_RNG(cur_run) < ts->minrun && VEC2_RNG(cur_run) < i)
		cur_run.y = boost_run(ts, cur_run.x, cur_run.y,
							cur_run.x + (ts->minrun < i ? ts->minrun : i));
	return (cur_run);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timsort_merge.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehugh-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 11:13:50 by ehugh-be          #+#    #+#             */
/*   Updated: 2019/11/22 11:27:56 by ehugh-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sort.h"

int		merge_lo(t_timsort *ts, t_int2 a, t_int2 b)
{
	int		i_a;
	int		i_b;
	int		i;
	void	*tmp;

	i_a = a.x;
	i_b = b.x;
	if (!(tmp = malloc(VEC2_RNG(a) * ts->elsz)))
		return (1);
	ft_memmove(tmp, ts->dta + a.x * ts->elsz, ts->elsz * VEC2_RNG(a));
	i = a.x;
	while (i_a < a.y && i_b < b.y)
		if (ts->cmp(tmp + (i_a - a.x) * ts->elsz, ts->dta + i_b * ts->elsz) > 0)
			ft_memmove(ts->dta + i++ * ts->elsz,
					ts->dta + i_b++ * ts->elsz, ts->elsz);
		else
			ft_memmove(ts->dta + i++ * ts->elsz, tmp + (i_a++ - a.x)
													* ts->elsz, ts->elsz);
	if (i_a < a.y)
		ft_memmove(ts->dta + i * ts->elsz,
				tmp + (i_a - a.x) * ts->elsz, ts->elsz * (a.y - i_a));
	free(tmp);
	return (0);
}

int		merge_hi(t_timsort *ts, t_int2 a, t_int2 b)
{
	int		i_a;
	int		i_b;
	int		i;
	void	*tmp;

	i_a = a.y - 1;
	i_b = b.y - 1;
	if (!(tmp = malloc(VEC2_RNG(b) * ts->elsz)))
		return (1);
	ft_memmove(tmp, ts->dta + b.x * ts->elsz, ts->elsz * VEC2_RNG(b));
	i = b.y;
	while (i_a >= a.x && i_b >= b.x)
	{
		if (ts->cmp(tmp + (i_b - b.x) * ts->elsz, ts->dta + i_a * ts->elsz) < 0)
			ft_memmove(ts->dta + --i * ts->elsz,
					ts->dta + i_a-- * ts->elsz, ts->elsz);
		else
			ft_memmove(ts->dta + --i * ts->elsz,
					tmp + (i_b-- - b.x) * ts->elsz, ts->elsz);
	}
	if (i_b >= b.x)
		ft_memmove(ts->dta + a.x * ts->elsz, tmp,
				ts->elsz * (i_b - b.x + 1));
	free(tmp);
	return (0);
}

int		merge_runs(t_timsort *ts, int offst)
{
	if (VEC2_RNG(ts->rn_szs[ts->rns_s - offst]) <=
		VEC2_RNG(ts->rn_szs[ts->rns_s - offst + 1]))
	{
		if (merge_lo(ts, ts->rn_szs[ts->rns_s - offst],
					ts->rn_szs[ts->rns_s - offst + 1]))
			return (1);
	}
	else if (merge_hi(ts, ts->rn_szs[ts->rns_s - offst],
				ts->rn_szs[ts->rns_s - offst + 1]))
		return (1);
	ts->rn_szs[ts->rns_s - offst].y = ts->rn_szs[ts->rns_s - offst + 1].y;
	ts->rns_s--;
	return (0);
}

int		merge_collapse(t_timsort *ts)
{
	if (ts->rns_s < 2)
		return (0);
	while ((ts->rns_s > 2 && VEC2_RNG(ts->rn_szs[ts->rns_s - 3]) <=
VEC2_RNG(ts->rn_szs[ts->rns_s - 2]) + VEC2_RNG(ts->rn_szs[ts->rns_s - 1]))
		|| (ts->rns_s > 1 && VEC2_RNG(ts->rn_szs[ts->rns_s - 2]) <=
								VEC2_RNG(ts->rn_szs[ts->rns_s - 1])))
	{
		if (ts->rns_s > 2 && VEC2_RNG(ts->rn_szs[ts->rns_s - 3]) <
							VEC2_RNG(ts->rn_szs[ts->rns_s - 1]))
		{
			if (merge_runs(ts, 3))
				return (1);
		}
		else if (merge_runs(ts, 2))
			return (1);
	}
	return (0);
}

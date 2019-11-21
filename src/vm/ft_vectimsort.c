/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vectimsort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehugh-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 12:08:30 by ehugh-be          #+#    #+#             */
/*   Updated: 2019/11/21 17:16:31 by ehugh-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

#define EL_NUM (ts->size / ts->elsz)

#define VEC2_RNG(a) (a.y - a.x)
typedef struct			s_timsort
{
	unsigned char	minrun;
	t_int2			*rn_szs;
	int				(*compare)(void*, void*);
	void			*data;
	size_t			elsz;
	size_t			size;
	size_t			rns_s;
}						t_timsort;

static unsigned short	get_minrun(size_t len)
{
	unsigned char	r;

	r = 0;
	while (len >= 64) {
		r |= len & 1u;
		len >>= 1u;
	}
	return ((unsigned short)(len + r));
}

int		count_run(t_timsort *tsort, int offset)
{
	int i;
	int asc;
	int tmp;

	i = offset;
	asc = tsort->compare(tsort->data + offset * tsort->elsz, tsort->data +
	(offset + 1) * tsort->elsz) <= 0;
	while (++i < tsort->size / tsort->elsz && i - offset < tsort->minrun)
	{
		tmp = tsort->compare(tsort->data + i * tsort->elsz, tsort->data +
		(i + 1) * tsort->elsz);
		if ((asc && tmp > 0) || (!asc && tmp < 1))
				break;
	}
	return ((i + 1 - offset) * (asc ? 1 : -1));
}

void 	ft_memswap(void **a, void **b, size_t size)
{
	void 	*tmp8;
	char 	*tmp1;
	int		i;

	i = 0;
	while (size - i >= sizeof(void*))
	{
		tmp8 = *(a + i);
		*(a + i) = *(b + i);
		*(b + i) = tmp8;
		i += sizeof(void*);
	}
	while (size - i)
	{
		tmp1 = *(a + i);
		*(a + i) = *(b + i);
		*(b + i) = tmp1;
		i++;
	}
}

void	*ft_memmove1(void *dst, const void *src, size_t len)
{
	if (dst == src)
		return (dst);
	if (dst > src)
	{
		while (len >= sizeof(void*))
		{
			len -= sizeof(void*);
			*((void**)(dst + len)) = *((void**)(src + len));
		}
		while (len--)
			*((char*)(dst + len)) = *((char*)(src + len));
	}
	else
	{
		while (len >= sizeof(void*))
		{
			*((void **)dst) = *((void **)src);
			dst += sizeof(void*);
			src += sizeof(void*);
			len -= sizeof(void*);
		}
		while (len--)
			*(char*)dst++ = *(char*)src++;
	}
}

t_int2		reverse_run(t_timsort *ts, t_int2 rng)
{
	int i;
	int len;

	i = -1;
	len = ft_abs(VEC2_RNG(rng));
	while (++i < len / 2)
		ft_memswap(ts->data + rng.x * ts->elsz+ i * ts->elsz,
				   ts->data + rng.x * ts->elsz + (len - i - 1) * ts->elsz,
				   ts->elsz);
	return ((t_int2){rng.x, rng.y + ft_abs(VEC2_RNG(rng)) * 2});
}

void	*ft_bisect_right(void *data, void *val, t_uint2 els_eln,
		int (compare)(void*, void*))
{
	unsigned	start;
	unsigned	end;
	unsigned	mid;
	int			tmp;

	start = 0;
	end = els_eln.y;
	while (end - start > 1)
	{
		mid = (start + end) / 2;
		tmp = compare(data + els_eln.x * mid, val);
		if (tmp < 0)
			start = mid;
		else
			end = mid;
	}
	tmp = compare(data + els_eln.x * start, val);
	if (tmp < 0)
		return (data + end * els_eln.x);
	else if (compare(data + els_eln.x * end, val) < 0)
		return (data + (end + 1) * els_eln.x);
	else
		return (data + start * els_eln.x);
}

int		boost_run(t_timsort *ts, int st, int cur, int end)
{
	char	tmp[ts->elsz];

	while (cur < end)
	{
		void *ins_place = ft_bisect_right(ts->data + st * ts->elsz,
ts->data + cur * ts->elsz, (t_uint2){ts->elsz, cur - st}, ts->compare);
		if (ins_place != ts->data + cur * ts->elsz)
		{
			ft_memcpy(tmp, ts->data + cur * ts->elsz, ts->elsz);
			ft_memmove1(ins_place + ts->elsz, ins_place,
						ts->data + ts->elsz * cur - ins_place);
			ft_memcpy(ins_place, tmp, ts->elsz);
		}
		cur++;
	}
	return (cur);
}

void	merge_lo(t_timsort *ts, t_int2 a, t_int2 b)
{
	int		i_a;
	int		i_b;
	int		i;
	void	*tmp;

	i_a = a.x;
	i_b = b.x;
	tmp = malloc(VEC2_RNG(a) * ts->elsz);
	ft_memmove1(tmp, ts->data + a.x * ts->elsz, ts->elsz * VEC2_RNG(a));
	i = a.x;
	while (i_a < a.y && i_b < b.y)
	{
		if (ts->compare(tmp + (i_a - a.x) * ts->elsz,
						ts->data + i_b * ts->elsz) > 0)
			ft_memmove1(ts->data + i++ * ts->elsz,
						ts->data + i_b++ * ts->elsz, ts->elsz);
		else
			ft_memmove1(ts->data + i++ * ts->elsz,
					tmp + (i_a++ - a.x) * ts->elsz, ts->elsz);
	}
	if (i_a < a.y)
		ft_memmove1(ts->data + i * ts->elsz,
				tmp + (i_a - a.x) * ts->elsz, ts->elsz * (a.y - i_a));
	free(tmp);
}

void	merge_hi(t_timsort *ts, t_int2 a, t_int2 b)
{
	int		i_a;
	int		i_b;
	int		i;
	void	*tmp;

	i_a = a.y - 1;
	i_b = b.y - 1;
	tmp = malloc(VEC2_RNG(b) * ts->elsz);
	ft_memmove1(tmp, ts->data + b.x * ts->elsz, ts->elsz * VEC2_RNG(b));
	i = b.y;
	while (i_a >= a.x && i_b >= b.x)
	{
		if (ts->compare(tmp + (i_b - b.x) * ts->elsz, ts->data + i_a * ts->elsz)
		< 0)
			ft_memmove1(ts->data + --i * ts->elsz,
					ts->data + i_a-- * ts->elsz, ts->elsz);
		else
			ft_memmove1(ts->data + --i * ts->elsz,
					tmp + (i_b-- - b.x) * ts->elsz, ts->elsz);
	}
	if (i_b >= b.x)
		ft_memmove1(ts->data + a.x * ts->elsz, tmp, ts->elsz * (i_b - b.x + 1));
	free(tmp);
}

void	merge_runs(t_timsort *ts, int offst)
{
	if (VEC2_RNG(ts->rn_szs[ts->rns_s - offst]) <=
		VEC2_RNG(ts->rn_szs[ts->rns_s - offst + 1]))
		merge_lo(ts, ts->rn_szs[ts->rns_s - offst],
				 ts->rn_szs[ts->rns_s - offst + 1]);
	else
		merge_hi(ts, ts->rn_szs[ts->rns_s - offst],
				 ts->rn_szs[ts->rns_s - offst + 1]);
	ts->rn_szs[ts->rns_s - offst].y = ts->rn_szs[ts->rns_s - offst + 1].y;
	ts->rns_s--;
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
			merge_runs(ts, 3);
		else
			merge_runs(ts, 2);
	}
}

t_timsort *init_timsort(void *data, size_t size, size_t el_size,
		int (compare)(void*, void*))
{
	t_timsort *ts;

	ts = malloc(sizeof(t_timsort));
	ts->data = data;
	ts->elsz = el_size;
	ts->size = size;
	ts->compare = compare;
	ts->minrun = get_minrun(EL_NUM);
	ts->rn_szs = malloc(sizeof(t_int2) * (EL_NUM / ts->minrun + 1));
	ts->rn_szs[0] = (t_int2){0, 0};
	ts->rns_s = 0;
	return (ts);
}

t_int2	get_run(t_timsort *ts, t_int2 cur_run, int i)
{
	cur_run.y += count_run(ts, EL_NUM - i);
	if (VEC2_RNG(cur_run) < 0)
		cur_run = reverse_run(ts, cur_run);
	if (VEC2_RNG(cur_run) < ts->minrun && VEC2_RNG(cur_run) < i)
		cur_run.y = boost_run(ts, cur_run.x, cur_run.y,
							  cur_run.x + (ts->minrun < i ? ts->minrun : i));
	return (cur_run);
}

void	ft_vectimsort(void *data, size_t size, size_t el_size,
		int (compare)(void*, void*))
{
	t_timsort	*ts;
	int			i;
	t_int2		cur_run;

	if (size % el_size)
		return ;
	ts = init_timsort(data, size, el_size, compare);
	i = EL_NUM;
	cur_run = ts->rn_szs[0];
	while (i > 0)
	{
		cur_run = get_run(ts, cur_run, i);
		i -= VEC2_RNG(cur_run);
		ts->rn_szs[ts->rns_s++] = cur_run;
		merge_collapse(ts);
		cur_run = (t_int2){ts->rn_szs[ts->rns_s - 1].y,
					 ts->rn_szs[ts->rns_s - 1].y};
	}
	while (ts->rns_s > 1)
		merge_runs(ts, 2);
	free(ts->rn_szs);
	free(ts);
}

int cmp(void* a, void* b)
{
	return (((t_int2*)a)->x - ((t_int2*)b)->x);
}

#include <time.h>
#include <stdlib.h>

#define TEST_SIZE 4586

int main()
{
	t_int2 tmp[TEST_SIZE];
	t_int2 tmp_back[TEST_SIZE];

	size_t rnd = time(NULL);
	ft_printf("Seed = %d\n", rnd);
	srand(rnd);   // Initialization, should only be called once.
	for (int i = 0; i < TEST_SIZE; i++){
		tmp[i].x = rand() % 1000 - 500;
		tmp[i].y = rand() % 1000 - 500;
	}
	ft_memcpy(&tmp_back, tmp, sizeof(tmp));
	ft_vectimsort(&tmp, sizeof(tmp), sizeof(t_int2), cmp);
	ft_printf("sort_finished\n");
	for (int i = 0; i < TEST_SIZE; i++)
	{
		int flag = 0;
		int j = 0;
		if (i > 0 && tmp[i].x < tmp[i - 1].x)
			ft_printf("Elements %d and %d are not in order [%d], [%d]\n",
					i, i - 1, tmp[i].x, tmp[i - 1].x);
		for (; j < TEST_SIZE; j++)
		{
			if (tmp_back[i].x == tmp[j].x && tmp_back[i].y == tmp[j].y)
			{
				flag = 1;
				break ;
			}
		}
		if (flag)
			continue ;
		else
			ft_printf("Element %d [%d, %d] not into final array\n",i, tmp_back[i].x, tmp_back[i].y);
	}
}

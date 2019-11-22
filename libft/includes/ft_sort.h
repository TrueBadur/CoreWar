
#ifndef FT_SORT_H
#define FT_SORT_H

#include "libstd.h"
#include "t_vec.h"

#define EL_NUM (ts->size / ts->elsz)
#define VEC2_RNG(a) ((a).y - (a).x)

typedef struct			s_timsort
{
	unsigned char	minrun;
	t_int2			*rn_szs;
	int				(*cmp)(void*, void*);
	void			*dta;
	size_t			elsz;
	size_t			size;
	size_t			rns_s;
}						t_timsort;

int		ft_vectimsort(void *data, size_t size, size_t el_size,
						 int (compare)(void*, void*));
void	*ft_bisect_right(void *data, void *val, t_uint2 els_eln,
						 int (compare)(void*, void*));
int	merge_lo(t_timsort *ts, t_int2 a, t_int2 b);
int		merge_collapse(t_timsort *ts);
int		merge_runs(t_timsort *ts, int offst);
t_int2	get_run(t_timsort *ts, t_int2 cur_run, int i);

#endif //COREWAR_FT_SORT_H

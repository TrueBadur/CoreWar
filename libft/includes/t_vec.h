/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_vec.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehugh-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 13:41:24 by ehugh-be          #+#    #+#             */
/*   Updated: 2019/11/06 21:58:25 by jleann           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_VEC_H
# define T_VEC_H
# include <stdlib.h>

typedef struct		s_vector2
{
	int				x;
	int				y;
}					t_int2;

typedef struct
{
	unsigned		x;
	unsigned		y;
}					t_uint2;

typedef struct
{
	double			x;
	double			y;
}					t_double2;

typedef struct		s_vector3
{
	int				x;
	int				y;
	int				z;
}					t_int3;

typedef struct
{
	unsigned		x;
	unsigned		y;
	unsigned		z;
}					t_uint3;

typedef struct		s_vector3_f
{
	float			x;
	float			y;
	float			z;
}					t_float3;

typedef struct
{
	double			x;
	double			y;
	double			z;
}					t_double3;

typedef struct		s_vector4
{
	int				x;
	int				y;
	int				z;
	int				w;
}					t_int4;

typedef union
{
	long			l;
	double			d;
}					t_dtol;

typedef struct		s_vector4_f
{
	float			x;
	float			y;
	float			u;
	float			v;
}					t_float4;

struct				s_color
{
	unsigned char	a;
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
};

typedef union		u_color4
{
	int				i_col;
	struct s_color	c_col;
}					t_ucol4;

typedef struct		s_vector
{
	void			*data;
	unsigned int	cap;
	unsigned int	len;
	unsigned int	offset;
}					t_vector;

t_vector			*ft_vecinit(size_t cap);
void				ft_vecdel(void **vect);
t_vector			*ft_vecpush(t_vector *vec, void *data, size_t s);
t_vector			*ft_vecpush_small(t_vector *vec, long data, size_t s);
t_vector			*ft_vecgrow(t_vector *vec, size_t s);
t_vector			*ft_vecshrink(t_vector *vec, unsigned int offset);
t_vector			*ft_vecremove(t_vector *vec, size_t strt, size_t s);
int					ft_vecbinsearch_int(t_vector *vec, int val);
t_vector			*ft_vecput(t_vector *vec, size_t pos, size_t size,
		void *data);
void				ft_vecquicksort(t_vector *vec,
							int(*comp)(void *, void *), size_t ssize);
typedef struct		s_string
{
	char			*data;
	size_t			len;
	size_t			capacity;
	int				info;
}					t_string;

void				ft_print_string(t_string *str);
void				ft_fd_print_string(t_string *str, int fd);

void				ft_free_string(t_string **str);

int					ft_string_fit(t_string **str);

int					ft_string_push_back(t_string **str, char c);
int					ft_string_push_back_s(t_string **str_ptr, char *str);
int					ft_string_push_back_n_s(t_string **str_ptr, char *str,
						size_t n);
int					ft_string_push_back_n_c(t_string **str_ptr,
						long n, char c);

int					ft_string_set_value(t_string **str, size_t n, char filler,
						char value);
t_string			*ft_make_string(size_t init_size);
t_ucol4				col_add(t_ucol4 a, t_ucol4 b);
t_ucol4				col_dif(t_ucol4 a, t_ucol4 b);
t_ucol4				col_div_val(t_ucol4 a, int val);
t_ucol4				col_mult_val(t_ucol4 a, int val);
t_ucol4				col_lerp(t_ucol4 st, t_ucol4 end, unsigned step,
						unsigned max);

#endif

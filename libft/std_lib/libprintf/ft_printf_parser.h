/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehugh-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 22:40:21 by ehugh-be          #+#    #+#             */
/*   Updated: 2019/01/16 23:44:33 by ehugh-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_PARSER_H
# define FT_PRINTF_PARSER_H

# include <stdarg.h>
# include "std_lib/libft.h"
# include "ft_printf.h"
# include "ft_printf_utils.h"

# define DEF_F_PRCSN 6
# define DEFAULT_INT_PRECISION 1
# define DEFAULT_STRING_PRECISION 2147483647

# define INT_TYPE_SPECIFIERS "dDiIuUcCsSrpkxXoObBn"
# define FLOAT_TYPE_SPECIFIERS "fFeEgG"
# define LONG_INT_TYPE_SPECS "sprSDUIO"

# define SET_DEFAULT_LENGTHS lengths[0] = 0; lengths[1] = 0; lengths[2] = 0
# define _128_COUNT lengths[3]
# define H_COUNT lengths[2]
# define L_COUNT lengths[1]
# define BIG_L_COUNT lengths[0]

typedef struct	s_complex_flags_data
{
	int was_star;
	int num;
	int was_dollar;
	int was_zero;
}				t_complex_flags_data;

typedef struct	s_fc
{
	long double	w;
	long double	w_d;
	long double	f;
	long double	f_d;
	int			f_lg;
	int			w_lg;
}				t_fc;

typedef union	u_bitld
{
	long double d;
	__uint128_t i;
}				t_bitld;

t_arg_data		*ft_printf_parser(const char **frmt, t_string **args);
int				ft_printf_parse_simple_flags(const char **frmt,
										t_arg_data *arg_data, int *lenghts);
int				ft_parse_len_specifier(const char **frmt, int *lenghts);
int				ft_printf_parse_modifiers(const char **frmt,
														t_arg_data *arg_data);
int				ft_printf_parse_comlex_flags(const char **frmt,
							t_arg_data *arg_data, t_string **args, int *n_arg);
int				ft_printf_parser_comlex_flags_proceeder(t_arg_data *arg_data,
				t_complex_flags_data *flags_data, t_string **args, int *n_arg);
void			ft_printf_arg_data_set_width_or_prec(t_arg_data *arg_data,
																		int n);
t_arg_sz		ft_printf_parser_get_arg_size(char c, int lengths[4]);
int				ft_set_int_arg_data(t_arg_data *arg_data, char c,
											t_string **args, int lengths[4]);
int				ft_set_float_arg_data(t_arg_data *arg_data, char c,
											t_string **args, int lengths[4]);
void			ft_set_invalid_arg_data(t_arg_data *arg_data, char c,
															t_string **args);

t_fc			*ft_fc_maker(t_arg_data *ad, long double *arg);
int				ft_get_exp(t_fc fc, t_arg_data *ad);
int				ft_check_nan(long double *n, t_arg_data *ad, t_string **str);
void			ft_push_all(t_fc *fc, t_arg_data *ad, t_string **str);
void			ft_push_part(t_fc *fc, int prc, t_string **str);
void			ft_enot(t_fc *fc);
void			ft_tor(t_fc *fc, t_arg_data *ad);
void			ft_dog(t_fc *fc, t_arg_data *ad);
long double		ft_find_whole(long double flt);
int				ft_find_whole_size(long double flt, long double *dec);
long double		ft_check_digit(long double n, int *p, int prec);

#endif

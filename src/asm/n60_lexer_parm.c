/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   L60_lexer_parm.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 17:39:02 by wgorold           #+#    #+#             */
/*   Updated: 2019/10/30 13:50:40 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

int		add_token_parm_label(t_lexdata *dat, char token_type, int idx_srt)
{
	char	*data;
	int		tmp;

	data = ft_strnew(dat->end - dat->srt - idx_srt);
	if (!data)
		return (ERR_LEX__ID_MALLOC_STR);
	ft_strncpy(data, dat->cur_line + dat->srt + idx_srt,
		dat->end - dat->srt - idx_srt);
	if ((tmp = add_token_str(dat, token_type, data)))
		return (tmp);
	return (0);
}

int		check_atoi(t_lexdata *dat, int *to_set)
{
	int idx;

	if (dat->debug_atoi)
		ft_printf("ATOI_check [%2d, %2d] =%.*s\n", dat->srt, dat->end,
			dat->end - dat->srt, dat->cur_line + dat->srt);
	if (dat->end == dat->srt)
		return (ERR_LEX__ID_EMPTY_PARAM);
	if (*(dat->cur_line + dat->srt) == '-')
		idx = 0;
	else
		idx = -1;
	while (++idx + dat->srt < dat->end)
		if (*(dat->cur_line + dat->srt + idx) < 48
			|| *(dat->cur_line + dat->srt + idx) > 57)
			return (ERR_LEX__ID_ATOI);
	*to_set = ft_atoi(dat->cur_line + dat->srt);
	return (0);
}

int		process_dir(t_lexdata *dat, char *line)
{
	int err;
	int	val;

	if (line[1] == LABEL_CHAR)
	{
		if ((err = add_token_parm_label(dat, TOKEN_TYPE_P_D_L, 2)))
			return (err);
		if (dat->debug_happend)
			ft_printf("\t\t\t\t\t\t\t\thappend= parm_dir_label\n");
		return (0);
	}
	else
	{
		dat->srt += 1;
		if ((err = check_atoi(dat, &val)))
			return (err);
		if ((err = add_token_data(dat, TOKEN_TYPE_P_D_I, val)))
			return (err);
		if (dat->debug_happend)
			ft_printf("\t\t\t\t\t\t\t\thappend= parm_dir_int\n");
		return (0);
	}
}

int		process_indir(t_lexdata *dat, char *line)
{
	int err;
	int	val;

	if (line[0] == LABEL_CHAR)
	{
		if ((err = add_token_parm_label(dat, TOKEN_TYPE_P_I_L, 1)))
			return (err);
		if (dat->debug_happend)
			ft_printf("\t\t\t\t\t\t\t\thappend= parm_ind_label\n");
		return (0);
	}
	else
	{
		if ((err = check_atoi(dat, &val)))
			return (err);
		if ((err = add_token_data(dat, TOKEN_TYPE_P_I_I, val)))
			return (err);
		if (dat->debug_happend)
			ft_printf("\t\t\t\t\t\t\t\thappend= parm_ind_int\n");
		return (0);
	}
}

int		add_parm(t_lexdata *dat)
{
	char	*line;
	int		tmp;
	int		val;
	int		err;

	line = dat->cur_line + dat->srt;
	if (*line == 'r')
	{
		dat->srt += 1;
		if ((err = check_atoi(dat, &val)))
			return (err);
		if ((tmp = add_token_data(dat, TOKEN_TYPE_P_R, val)))
			return (tmp);
		if (dat->debug_happend)
			ft_printf("\t\t\t\t\t\t\t\thappend= parm_reg\n");
		return (0);
	}
	else if (*line == DIRECT_CHAR && (err = process_dir(dat, line)))
		return (err);
	else if ((err = process_indir(dat, line)))
		return (err);
	return (0);
}

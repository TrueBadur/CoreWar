/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   L60_lexer_parm.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 17:39:02 by jleann            #+#    #+#             */
/*   Updated: 2019/10/17 16:30:17 by wgorold          ###   ########.fr       */
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
	ft_strncpy(data, dat->cur_line + dat->srt + idx_srt, dat->end - dat->srt - idx_srt);
	if ((tmp = add_token_str(dat, token_type, data)))
		return (tmp);
	return (0);
}

int 	check_atoi(int *to_set, char *line)
{
	int ord;
	int sig;
	int to_check;

	*to_set = ft_atoi(line);
	to_check = *to_set;
	sig = 1;
	if (to_check < 0)
	{
		ft_printf("check_atoi= '-' vs %c\n", *line);
		if (*line != '-')
			return (1);
		else
		{
			line += 1;
			sig = -1;
		}
	}
	if (*to_set != 0)
	{
		while (*line == '0')
			line += 1;
	}
	ord = 10;
	while (to_check / ord)
		ord *= 10;
	while (ord > 10)
	{
		ord /= 10;
		ft_printf("check_atoi[%d, %d, %d]= %d vs %d\n", ord, to_check, sig * to_check / ord, sig * (to_check / ord) % 10, *line - 48);
		if (sig * (to_check / ord) % 10 != (*line - 48))
			return (1);
		else
			line += 1;
	}
	ft_printf("check_atoi= %d vs %d\n", to_check % 10, *line - 48);
	if (sig * to_check % 10 != (*line - 48))
		return (1);
	return (0);
}

int		add_parm(t_lexdata *dat)
{
	char	*line;
	int		tmp;
	int		val;

	line = dat->cur_line + dat->srt;
	if (*line == 'r')
	{
		if (check_atoi(&val, line + 1))
			return (ERR_LEX__ID_ATOI);
		if ((tmp = add_token_data(dat, TOKEN_TYPE_P_R, val)))
			return (tmp);
		if (dat->debug_happend)
					ft_printf("\t\t\t\t\t\t\t\thappend= parm_reg\n");
		return (0);
	}
	else if (*line == DIRECT_CHAR)
	{
		if (line[1] == LABEL_CHAR) // label
		{
			if ((tmp = add_token_parm_label(dat, TOKEN_TYPE_P_D_L, 2)))
				return (tmp);
			if (dat->debug_happend)
					ft_printf("\t\t\t\t\t\t\t\thappend= parm_dir_label\n");
			return (0);
		}
		else
		{
			if (check_atoi(&val, line + 1))
				return (ERR_LEX__ID_ATOI);
			if ((tmp = add_token_data(dat, TOKEN_TYPE_P_D_I, val)))
				return (tmp);
			if (dat->debug_happend)
					ft_printf("\t\t\t\t\t\t\t\thappend= parm_dir_int\n");
			return (0);
		}
	}
	else
	{
		if (line[0] == LABEL_CHAR) // label
		{

			if ((tmp = add_token_parm_label(dat, TOKEN_TYPE_P_I_L, 1)))
				return (tmp);
			if (dat->debug_happend)
					ft_printf("\t\t\t\t\t\t\t\thappend= parm_ind_label\n");
			return (0);
		}
		else
		{
			if (check_atoi(&val, line))
				return (ERR_LEX__ID_ATOI);
			if ((tmp = add_token_data(dat, TOKEN_TYPE_P_I_I, val)))
				return (tmp);
			if (dat->debug_happend)
					ft_printf("\t\t\t\t\t\t\t\thappend= parm_ind_int\n");
			return (0);
		}
	}
	return (0);
}

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

int		set_data_parm_int(t_lexdata *dat, int id_r)
{
	int				*data;

	data = (int *)malloc(sizeof(int));
	if (!data)
		return (ERROR_LEX_MALLOC);
	*data = id_r;
	((t_token *)(dat->token_list.end->content))->data = data;
	return (0);
}

int		set_data_parm_label(t_lexdata *dat, int idx_srt)
{
	char	*data;
	
	data = ft_strnew(dat->end - dat->srt - idx_srt);
	if (!data)
		return (ERROR_LEX_MALLOC_STR);
	ft_strncpy(data, dat->cur_line + dat->srt + idx_srt, dat->end - dat->srt - idx_srt);
	((t_token *)(dat->token_list.end->content))->data = data;
	return (0);
}

int		add_parm(t_lexdata *dat)
{
	char	*line;
	int		tmp;

	line = dat->cur_line + dat->srt;
	if (*line == 'r')
	{
		if ((tmp = add_token(dat, PARAM_ID, PARAM_REG_ID, 0)))
			return (tmp);
		if ((tmp = set_data_parm_int(dat, ft_atoi(line + 1))))
			return (tmp);
		if (dat->debug_happend)
					ft_printf("\t\t\t\t\t\t\t\thappend= parm_reg\n");
		return (0);
	}
	else if (*line == DIRECT_CHAR)
	{
		if (line[1] == LABEL_CHAR) // label
		{
			if ((tmp = add_token(dat, PARAM_ID, PARAM_DIR_ID, PARAM_LABEL)))
				return (tmp);
			if ((tmp = set_data_parm_label(dat, 2)))
				return (tmp);
			if (dat->debug_happend)
					ft_printf("\t\t\t\t\t\t\t\thappend= parm_dir_label\n");
			return (0);
		}
		else
		{
			if ((tmp = add_token(dat, PARAM_ID, PARAM_DIR_ID, PARAM_INT)))
				return (tmp);
			if ((tmp = set_data_parm_int(dat, ft_atoi(line + 1))))
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
			if ((tmp = add_token(dat, PARAM_ID, PARAM_IND_ID, PARAM_LABEL)))
				return (tmp);
			if ((tmp = set_data_parm_label(dat, 1)))
				return (tmp);
			if (dat->debug_happend)
					ft_printf("\t\t\t\t\t\t\t\thappend= parm_ind_label\n");
			return (0);
		}
		else
		{
			if ((tmp = add_token(dat, PARAM_ID, PARAM_IND_ID, PARAM_INT)))
				return (tmp);
			if ((tmp = set_data_parm_int(dat, ft_atoi(line))))
				return (tmp);
			if (dat->debug_happend)
					ft_printf("\t\t\t\t\t\t\t\thappend= parm_ind_int\n");
			return (0);
		}
	}
	
	return (0);
}

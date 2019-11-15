/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   n32_lexer_token_decode.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 17:39:02 by wgorold           #+#    #+#             */
/*   Updated: 2019/10/30 18:21:52 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

void	process_token_param(char tkn_typ, char *sub, char *val)
{
	if (tkn_typ == TOKEN_TYPE_P_R)
	{
		*sub = PARAM_REG_ID;
	}
	else if (tkn_typ == TOKEN_TYPE_P_D_I)
	{
		*sub = PARAM_DIR_ID;
		*val = PARAM_INT;
	}
	else if (tkn_typ == TOKEN_TYPE_P_I_I)
	{
		*sub = PARAM_IND_ID;
		*val = PARAM_INT;
	}
	else if (tkn_typ == TOKEN_TYPE_P_D_L)
	{
		*sub = PARAM_DIR_ID;
		*val = PARAM_LABEL;
	}
	else if (tkn_typ == TOKEN_TYPE_P_I_L)
	{
		*sub = PARAM_IND_ID;
		*val = PARAM_LABEL;
	}
}

void	process_token_type(char tkn_typ, char *type, char *sub, char *val)
{
	if (tkn_typ == TOKEN_TYPE_INST)
		*type = INST_ID;
	else if (tkn_typ == TOKEN_TYPE_DELIM)
		*type = DELIM_ID;
	else if (tkn_typ == TOKEN_TYPE_END)
		*type = ENDL_ID;
	else if (tkn_typ == TOKEN_TYPE_LABEL)
		*type = LABEL_ID;
	else if (tkn_typ == TOKEN_TYPE_P_R)
	{
		*type = PARAM_ID;
		*sub = PARAM_REG_ID;
	}
	else if (tkn_typ == TOKEN_TYPE_P_D_I || tkn_typ == TOKEN_TYPE_P_I_I
			|| tkn_typ == TOKEN_TYPE_P_D_L || tkn_typ == TOKEN_TYPE_P_I_L)
	{
		*type = PARAM_ID;
		process_token_param(tkn_typ, sub, val);
	}
	else
		ft_printf("process_token_type failed: token_type=%d\n", tkn_typ);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   n13_lexer_debug_type.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 17:39:02 by wgorold           #+#    #+#             */
/*   Updated: 2019/10/30 18:21:45 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

char	*back_str_type(int id_label)
{
	if (id_label == LABEL_ID)
		return ("LABEL_ID");
	if (id_label == INST_ID)
		return ("INST_ID");
	if (id_label == PARAM_ID)
		return ("PARAM_ID");
	if (id_label == DELIM_ID)
		return ("DELIM_ID");
	if (id_label == ENDL_ID)
		return ("ENDL_ID");
	return (NULL);
}

char	*back_str_sub_type(int id_label)
{
	if (id_label == PARAM_REG_ID)
		return ("PARAM_REG_ID");
	if (id_label == PARAM_DIR_ID)
		return ("PARAM_DIR_ID");
	if (id_label == PARAM_IND_ID)
		return ("PARAM_IND_ID");
	return (NULL);
}

char	*back_str_val_type(int id_label)
{
	if (id_label == PARAM_LABEL)
		return ("PARAM_LABEL");
	if (id_label == PARAM_INT)
		return ("PARAM_INT");
	return (NULL);
}

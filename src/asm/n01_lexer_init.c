/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   n01_lexer_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 17:39:02 by wgorold           #+#    #+#             */
/*   Updated: 2019/10/30 18:21:39 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

void	init_stack_list(t_list *lst)
{
	lst->begin = NULL;
	lst->end = NULL;
	lst->len = 0;
}

void	setup_dat(t_lexdata *dat)
{
	dat->debug_fd = 0;
	dat->debug_gnl = 0;
	dat->debug_comment = 0;
	dat->debug_name = 0;
	dat->debug_atoi = 0;
	dat->debug_happend = 0;
	dat->debug_out = 0;
	dat->debug_done = 0;
	init_stack_list(&(dat->lines));
	init_stack_list(&(dat->token_list));
	init_stack_list(&(dat->label_list));
	dat->fd = -1;
	dat->champ_name = NULL;
	dat->champ_comment = NULL;
	dat->cur_line = NULL;
	dat->err_line = -1;
	dat->labels_num = 0;
	dat->srt = -1;
	dat->end = -1;
	dat->cur_idx = -1;
}

int		init_dat(t_lexdata **dat)
{
	*dat = (t_lexdata *)malloc(sizeof(t_lexdata));
	if (!*dat)
		return (ERR_LEX__ID_MALLOC_DAT);
	setup_dat(*dat);
	return (0);
}

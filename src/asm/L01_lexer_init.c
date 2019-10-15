/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   L01_lexer_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 17:39:02 by jleann            #+#    #+#             */
/*   Updated: 2019/10/15 21:29:49 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

void 	init_stack_list(t_list *lst)
{
	lst->begin = NULL;
	lst->end = NULL;
	lst->len = 0;
}

void		init_dat(t_lexdata *dat)
{
	dat->debug_fd = 0;
	dat->debug_gnl = 0;
	dat->debug_comment = 1;
	dat->debug_name = 1;
	
	dat->fd = -1;
	init_stack_list(&(dat->lines));
	init_stack_list(&(dat->token_list));
	init_stack_list(&(dat->label_list));
}
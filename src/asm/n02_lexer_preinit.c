/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   n02_lexer_preinit.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 17:39:02 by wgorold           #+#    #+#             */
/*   Updated: 2019/10/30 18:21:41 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

int		get_fd(char *fname, t_lexdata *dat)
{
	int fd;

	if (fname && (fd = open(fname, O_RDONLY)) > 0)
	{
		dat->fd = fd;
		if (dat->debug_fd)
			ft_printf("lexer_fd = %d\n", fd);
		return (0);
	}
	return (ERR_LEX__ID_FD);
}

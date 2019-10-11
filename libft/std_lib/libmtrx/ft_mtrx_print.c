/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtrx_print.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehugh-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 04:31:51 by ehugh-be          #+#    #+#             */
/*   Updated: 2019/01/14 22:13:15 by ehugh-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mtrx.h"
#include <stdio.h>

void	ft_mtrx_print(t_mtrx *m)
{
	int i;

	i = -1;
	ft_putstr("matrix ");
	ft_putnbr(m->w);
	ft_putstr(" x ");
	ft_putnbr(m->h);
	ft_putendl(":");
	while (++i < m->w * m->h)
	{
		if (i % m->w == 0 && i > 0)
			ft_putendl("");
		ft_putnbr((int)((double *)m->mtrx)[i]);
		ft_putstr(".");
		ft_putnbr((int)((((double *)m->mtrx)[i] - (int)((double *)m->mtrx)[i]) *
					10000000000));
		ft_putstr(" ");
	}
	ft_putendl("");
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtrx_mlt_destr.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehugh-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 00:17:35 by ehugh-be          #+#    #+#             */
/*   Updated: 2019/01/11 03:57:59 by ehugh-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mtrx.h"

t_mtrx	*ft_mtrx_mlt_destr(t_mtrx *m1, t_mtrx *m2)
{
	t_mtrx *ret;

	if (!m1 || !m2)
		return (NULL);
	ret = ft_mtrx_mlt(m1, m2);
	ft_mtrx_destroy(&m2);
	ft_mtrx_destroy(&m1);
	return (ret);
}

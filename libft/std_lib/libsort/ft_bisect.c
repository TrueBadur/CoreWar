/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bisect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehugh-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 11:06:59 by ehugh-be          #+#    #+#             */
/*   Updated: 2019/11/22 11:07:36 by ehugh-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sort.h"

void	*ft_bisect_right(void *data, void *val, t_uint2 els_eln,
						int (compare)(void*, void*))
{
	unsigned	start;
	unsigned	end;
	unsigned	mid;
	int			tmp;

	start = 0;
	end = els_eln.y;
	while (end - start > 1)
	{
		mid = (start + end) / 2;
		tmp = compare(data + els_eln.x * mid, val);
		if (tmp < 0)
			start = mid;
		else
			end = mid;
	}
	tmp = compare(data + els_eln.x * start, val);
	if (tmp < 0)
		return (data + end * els_eln.x);
	else if (compare(data + els_eln.x * end, val) < 0)
		return (data + (end + 1) * els_eln.x);
	else
		return (data + start * els_eln.x);
}

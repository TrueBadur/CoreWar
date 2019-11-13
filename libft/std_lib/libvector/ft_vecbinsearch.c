/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vecbinsearch.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehugh-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 19:33:00 by ehugh-be          #+#    #+#             */
/*   Updated: 2019/11/06 20:48:50 by ehugh-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_vec.h"

/*
** @param vec - sorted valid int vector that would be searched through
** @param val - value that will be looked for
** @return - index of the vector where value is stored or negative if value
** haven't been found
*/

static int ft_standart_cmp(void* a, void *b)
{
	return (a - b);
}

int	ft_vecbinsearch(t_vector *vec, void *val, int (*compare)(void*, void*))
{
	int ret;
	int tmp;
	int st;
	int end;

	st = 0;
	end = (vec->len / sizeof(int)) - 1;
	if (!compare)
		compare = ft_standart_cmp;
	while (end - st > 1)
	{
		ret = (st + end) / 2;
		tmp = compare(val, ((void**)vec->data)[ret]);
		if (!tmp)
			return (ret);
		else if (tmp < 0)
			end = ret;
		else
			st = ret;
	}
	if (!compare(((void**)vec->data)[st], val))
		return (st);
	else if (!compare(((void**)vec->data)[end], val))
		return (end);
	return (-1);
}

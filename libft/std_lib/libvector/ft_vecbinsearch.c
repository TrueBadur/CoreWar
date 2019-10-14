/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vecbinsearch.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehugh-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 19:33:00 by ehugh-be          #+#    #+#             */
/*   Updated: 2019/06/07 19:48:07 by ehugh-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_vec.h"

/*
** @param vec - sorted valid int vector that would be searched through
** @param val - value that will be looked for
** @return - index of the vector where value is stored or negative if value
** haven't been found
*/

int	ft_vecbinsearch_int(t_vector *vec, int val)
{
	int ret;
	int tmp;
	int st;
	int end;

	st = 0;
	end = (vec->len / sizeof(int)) - 1;
	while (end - st > 1)
	{
		ret = (st + end) / 2;
		tmp = ((int*)vec->data)[ret];
		if (val == tmp)
			return (ret);
		else if (val < tmp)
			end = ret;
		else
			st = ret;
	}
	if (((int*)vec->data)[st] == val)
		return (st);
	else if (((int*)vec->data)[end] == val)
		return (end);
	return (-1);
}

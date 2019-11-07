/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vecquicksort.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehugh-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 21:59:10 by jleann            #+#    #+#             */
/*   Updated: 2019/11/07 18:16:35 by ehugh-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <stddef.h>
#include "libft.h"

void	ft_memswap(void *a, void *b, size_t size)
{
	void	*tmp;

	(void)size
	tmp = *(void**)a;
	*(void**)a = *(void**)b;
	*(void**)b = tmp;
//	ft_memcpy(tmp, a, size);
//	ft_memcpy(a, b, size);
//	ft_memcpy(b, tmp, size);
}

uint32_t	partition(void *data, t_int2 begened,
						int(*comp)(void *, void *), size_t ssize)
{
	long	j;
	void 		*target = data + ssize * begened.y;
	long 	i = begened.x - 1;

	j = begened.x;
	while(j <= begened.y - 1)
	{
		if (comp(target, data + ssize * j) >= 0)
		{
			i++;
			ft_memswap(data + ssize * i, data + ssize * j, ssize);
		}
		j++;
	}
	ft_memswap(data + ssize * (i + 1), target, ssize);

	return (i + 1);
}

void	ft_vecquicksort(t_vector *vec, int(*comp)(void *, void *), size_t ssize)
{
	int			stack[vec->len / ssize];
	int 		top;
	int 		begin;
	int 		end;
	int			p;

	top = 0;
	ft_bzero(stack, sizeof(int) * (vec->len / ssize));
	stack[top] = 0;
	stack[++top] = (int)(vec->len / ssize - 1);
	while (top >= 0)
	{
		end = stack[top--];
		begin = stack[top--];
		if ((p = partition(vec->data, (t_int2){begin, end}, comp, ssize)) - 1 > begin)
		{
			stack[++top] = begin;
			stack[++top] = (uint32_t)(p - 1);
		}
		if (p + 1 < end)
		{
			stack[++top] = (uint32_t)(p + 1);
			stack[++top] = end;
		}
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memswap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehugh-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 10:55:52 by ehugh-be          #+#    #+#             */
/*   Updated: 2019/11/22 10:55:52 by ehugh-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void 	ft_memswap(void **a, void **b, size_t size)
{
	void 	*tmp8;
	char 	*tmp1;
	int		i;

	i = 0;
	while (size - i >= sizeof(void*))
	{
		tmp8 = *(a + i);
		*(a + i) = *(b + i);
		*(b + i) = tmp8;
		i += sizeof(void*);
	}
	while (size - i)
	{
		tmp1 = *(a + i);
		*(a + i) = *(b + i);
		*(b + i) = tmp1;
		i++;
	}
}

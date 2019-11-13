/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_avl_keycmp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehugh-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 21:39:45 by ehugh-be          #+#    #+#             */
/*   Updated: 2019/07/09 21:39:45 by ehugh-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "btavl.h"

int	ft_avl_keycmp(void *a, void *b, t_avl_k_t keytype,
		int (key_compare)(void*, void*))
{
	if (keytype < STRING)
	{
		if (a == b)
			return (0);
		else if (a > b)
			return (1);
		else
			return (-1);
	}
	else if (keytype == STRING)
		return (ft_strcmp(a, b));
	else
		return (key_compare(a, b));
}


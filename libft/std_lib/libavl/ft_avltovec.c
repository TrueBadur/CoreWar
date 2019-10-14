/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_avltovec.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehugh-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 01:47:09 by ehugh-be          #+#    #+#             */
/*   Updated: 2019/09/04 19:34:57 by ehugh-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "btavl.h"

t_vector	*ft_avltovec(t_btavl *tr, t_vector *vec)
{
	if (!tr || !vec)
		return (NULL);
	if (tr->left)
		ft_avltovec(tr->left, vec);
	ft_vecpush(vec, &tr->key, sizeof(int));
	if (tr->right)
		ft_avltovec(tr->right, vec);
	return (vec);
}

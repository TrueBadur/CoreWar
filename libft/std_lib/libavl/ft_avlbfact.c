/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_avlbfact.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehugh-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 13:15:04 by ehugh-be          #+#    #+#             */
/*   Updated: 2018/12/07 02:34:30 by ehugh-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "btavl.h"

/*
** @param node - tree to get balance factor
** @return - value less equal or greater then 0 if height of the right subtree
** of the node is smaller equal or greater then left subtree fo the node.
*/

int	ft_avlbfact(t_btavl *node)
{
	if (!node)
		return (0);
	return (ft_avlh(node->right) - ft_avlh(node->left));
}

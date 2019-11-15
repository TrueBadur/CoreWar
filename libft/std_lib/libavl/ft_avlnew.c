/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_avlnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehugh-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 12:57:52 by ehugh-be          #+#    #+#             */
/*   Updated: 2019/07/09 21:35:02 by ehugh-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "btavl.h"

/*
** Creates new node with int as a key and stores given pointer to data without
** 	copying data
** @param data
** @param key
** @param size
** @return
*/

t_btavl	*ft_avlnew_nc(void *data, void *key, size_t size, t_avl_k_t kt)
{
	t_btavl	*ret;

	if (!(ret = malloc(sizeof(t_btavl))) || (kt >= STRING && key == NULL))
		return (NULL);
	ret->size = size;
	if (!data)
		ret->size = 0;
	ret->data = data;
	ret->key = key;
	ret->left = NULL;
	ret->right = NULL;
	ret->key_type = kt;
	ret->h = 1;
	return (ret);
}

/*
** Copies given data of size 'size' to the newly created avl tree node with
** 'key' as int key of this node and returns pointer to this node
** @param data - data to be copied in node
** @param key - key for the node
** @param size - size of data to be copied
** @return - pointer to newly create avl tree node
*/

t_btavl	*ft_avlnew(void *data, void *key, size_t size, t_avl_k_t kt)
{
	t_btavl	*ret;

	if ((kt >= STRING && key == NULL) || !(ret = malloc(sizeof(t_btavl))))
		return (NULL);
	if (!data && !(ret->data = NULL))
		ret->size = 0;
	else if (!(ret->data = malloc(size)))
	{
		free(ret);
		return (NULL);
	}
	else
	{
		ft_memcpy(ret->data, data, size);
		ret->size = size;
	}
	ret->key = key;
	ret->left = NULL;
	ret->right = NULL;
	ret->key_type = kt;
	ret->h = 1;
	ret->copy = 1;
	return (ret);
}

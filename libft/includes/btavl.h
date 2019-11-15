/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btavl.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehugh-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 16:44:14 by ehugh-be          #+#    #+#             */
/*   Updated: 2019/11/15 18:54:12 by ehugh-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BTAVL_H
# define BTAVL_H
# include "libstd.h"
# include "t_vec.h"
# define TO_AVL_KEY(x) ((void*)((long)(x)))

typedef enum		e_avl_key_type
{
	NUM32,
	NUM64,
	STRING,
	OTHER
}					t_avl_k_t;

typedef struct		s_btavl
{
	void			*data;
	size_t			size;
	void			*key;
	struct s_btavl	*left;
	struct s_btavl	*right;
	char			copy;
	t_avl_k_t		key_type;
	unsigned char	h;
}					t_btavl;

# ifdef FT_SOURCE_BTAVL

void				ft_avlfixh(t_btavl *tr);
t_btavl				*ft_avlrr(t_btavl *tr);
t_btavl				*ft_avlrl(t_btavl *tr);
t_btavl				*ft_avlbal(t_btavl *tr);
int					ft_avl_keycmp(void *a, void *b, t_avl_k_t kt,
		int (f)(void*, void*));
# endif

/*
** Copies given data of size 'size' to the newly created avl tree node with
** 'key' as int key of this node and returns pointer to this node
*/
t_btavl				*ft_avlnew(void *data, void *key, size_t size,
		t_avl_k_t kt);
/*
** The same as previous but don't copies the data, but stores pointer to it
*/
t_btavl				*ft_avlnew_nc(void *data, void *key, size_t size,
		t_avl_k_t kt);
/*
** Returns height of given tree
*/
unsigned char		ft_avlh(t_btavl *tr);
/*
** Returns balance factor of given tree
*/
int					ft_avlbfact(t_btavl *node);

t_btavl				*ft_avlins(t_btavl *tr, t_btavl *node,
		int (f)(void*, void*));
t_btavl				*ft_avlrem(t_btavl *tr, void *key, void (*f)(void **),
							int (f_c)(void*, void*));
t_btavl				*ft_avlfree(t_btavl *tr);
void				*ft_avlsearch(t_btavl *tr, void *key, int ret_d,
						int (f)(void*, void*));
t_btavl				*ft_avlmin(t_btavl *tr);
t_btavl				*ft_avlmax(t_btavl *tr);
t_vector			*ft_avltovec(t_btavl *tr, t_vector *vec);
t_btavl				*ft_avlfree_custom(t_btavl *tr, void (free_data)(void*));

#endif

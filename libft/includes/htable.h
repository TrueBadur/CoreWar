/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   htable.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehugh-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 20:22:47 by ehugh-be          #+#    #+#             */
/*   Updated: 2019/09/04 19:04:05 by ehugh-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HTABLE_H
# define HTABLE_H

# include "libft.h"
# include <stdio.h>
# include <errno.h>
# define HTAB_MIN_SIZE 3

typedef struct		s_bucket
{
	char		*key;
	void		*data;
}					t_bucket;

/*
** add - is alias for ft_htab_add()
** isin - is alias for ft_htab_isin()
*/

typedef struct		s_htable
{
	t_vector		*table;
	int				count;
	size_t			tabsize;
	t_list			*iterator_list;
	size_t			iter;
	void			*(*get)(struct s_htable*, char *key);
	int				(*isin)(struct s_htable*, char *key);
	struct s_htable	*(*add)(struct s_htable *self, char *key, void *data);
	void			*(*pop)(struct s_htable**, char *key);
	struct s_htable	*(*rem)(struct s_htable*, char *key,
						void (*del)(void*));
	int				(*next)(struct s_htable*, char **key, void **value);
}					t_htab;

# ifdef FT_HTABLE_MISC

unsigned long		hash(char *str);
t_list				*htab_get_lst(t_htab *htab, char *key);
t_list				*htab_get_lst_strt(t_vector *table, size_t pos);
t_htab				*ft_htab_grow(t_htab *htab);
t_htab				*ft_htab_shrink(t_htab *htab);

# endif

/*
** Initialises htab with size 4 * count.
** Init with key aka char*, value aka void*
** @param count
** @param ...
** @return
*/
t_htab				*ft_htab_init(int count, ...);
t_htab				*ft_htab_init_empty(size_t count);
/*
** Checks if key is in htable.
** @param self - htable to check in
** @param key - key to check for
** @return - 1 in case if key already in htable or 0 if not.
*/
int					ft_htab_isin(t_htab *self, char *key);
/*
** Add or replace key-value pair in htab. Be careful: it will replace data if
** key already in array, what may cause leaks.
** @param self - (t_htab*) Table in which to add key-value pair.
** @param key - (char*) String that will be the key of the given value
** @param data - (void*) value that will be stored in table
** @return - Return the same htab or NULL if something went wrong. errno set to
** corresponding value.
*/
t_htab				*ft_htab_add(t_htab *self, char *key, void *data);
void				*ft_htab_get(t_htab *htab, char *key);
void				*ft_htab_pop(t_htab **self, char *key);
t_htab				*ft_htab_rem(t_htab *self, char *key, void (*del)(void*));
/*
** Frees htab assuming that all data in it, keys as well as values, are already
** freed, so it doesn't manage those.
** @param htab - table to be freed
*/
void				ft_htab_free(t_htab *htab);
void				ft_htab_free_helper(t_htab *htab, void (*key_free)(void*),
		void (*val_free)(void*));
int					ft_htab_generator(t_htab *htab, char **key, void **value);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_list.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehugh-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 15:50:32 by ehugh-be          #+#    #+#             */
/*   Updated: 2019/09/04 16:26:55 by ehugh-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIST_H
#ifndef LIBFT_T_LIST_H
#define LIBFT_T_LIST_H
# include "libstd.h"

typedef struct		s_list
{
	void			*data;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

/*
** Creates new node of type t_list copying given data of content_size size
** to newly allocated memory. If content_size is less then size of pointer,
** memory isn't allocated instead value is stored in pointer.
** @param content data to be put in lists node.
** @param content_size size of data to be put.
** @return pointer to list node of type t_list or NULL if memory allocation
** failed.
*/
t_list				*ft_lstnew(void const *content, size_t content_size);
/*
** Frees one t_list node and it's data and set pointer to list node to NULL.
** @param alst pointer to pointer to list node.
** @param del function to free data in list node. If NULL free() is used.
*/
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
/* Similar to ft_lstdelone but follows list to the end freeing all nodes and
** data
*/
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
t_list				*ft_lstfind_n(t_list *lst, int num);
t_list				*ft_lstfindlast(t_list *lst);
t_list				*ft_lstfind_v(t_list *lst, void *val, size_t s);
void				ft_lstaddlast(t_list **alst, t_list *new);
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_list				*ft_lstcopy(t_list *lst);
int					ft_lstlen(t_list *lst);
void				*ft_lstpop(t_list **lst);
#endif //LIBFT_T_LIST_H
#endif
#include "ft_list.h"
#include "ft_ls.h"
#include "arg_parser.h"
#include "ft_string.h"

void        swap_nodes(t_list *lst, t_list_node *l, t_list_node *r)
{

	if (l->prev)
		l->prev->next = r;
	else
		lst->begin = r;
	if (r->next)
		r->next->prev = l;
	else
		lst->end = l;
	l->next = r->next;
	r->next = l;
	r->prev = l ->prev;
	l->prev = r;
}

void		lst_sort(t_list *files_list,int (*f)(void *, void *), char rev)
{
	t_list_node *tmp;
	t_list_node *pmt;

	tmp = files_list->end;
	while (tmp) {
		pmt = files_list->begin;
		while (pmt->next) {
			if (f(pmt->content, pmt->next->content) * (rev ? -1 : 1) > 0)
				swap_nodes(files_list, pmt, pmt->next);
			else
				pmt = pmt->next;
		}
		tmp = tmp->prev;
	}
}
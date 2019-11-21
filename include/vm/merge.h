/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 16:24:31 by wgorold           #+#    #+#             */
/*   Updated: 2019/11/21 21:44:24 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MERGE_H
# define MERGE_H
# include "corewar.h"
# define SILENT_NMS 1

int			show(void *data);
int			show_sub(void *data);
void		show_cs_from_back(t_list_node *node, t_list_node *end);
int			nms_cnt_lst_end(t_list *control, t_list_node *begin);
int			nms_cnt_lst(t_list *control, t_list *to_sort,
			int (*f)(void *left, void *right));
int			weave(t_list_node **yarn, t_list_node **left_clew,
			t_list_node **right_clew, int yarn_state);
void		swap_clew(t_list_node *yarn, t_list_node *left_clew,
			t_list_node *right_clew, int *yarn_state);
void		update_node(t_list_node *left, t_list_node *right, t_list *trash);
t_list_node *merge(t_list_node *left, t_list_node *right, t_list *trash,
			int (*f)(void *left, void *right));
void		free_list_without_content(t_list *lst);
int			free_nms(t_list *control, t_list *trash, int code);
int			nms(t_list *to_sort, int (*f)(void *left, void *right));

#endif

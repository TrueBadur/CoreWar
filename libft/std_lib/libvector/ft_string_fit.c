/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shapka                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggerardy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 17:25:22 by ggerardy          #+#    #+#             */
/*   Updated: 2019/01/23 15:11:50 by ehugh-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** In case of allocated for string memory is greater then actual string
** function reallocates memory to fit the string.
** @param str_ptr - pointer to string to be fit
** @return - returns 1 if fitting gone well, 0 if allocation failed and -1 if
** t_string is NULL
*/

int	ft_string_fit(t_string **str_ptr)
{
	t_string *str;

	if (!str_ptr || !*str_ptr)
		return (-1);
	str = *str_ptr;
	if (str->len == str->capacity - 1)
		return (1);
	str->data = ft_realloc(str->data, str->capacity,
			str->len == 0 ? 2 : str->len + 1);
	if (!str->data)
	{
		ft_free_string(str_ptr);
		return (0);
	}
	str->data[str->len] = 0;
	str->capacity = str->len == 0 ? 2 : str->len + 1;
	return (1);
}

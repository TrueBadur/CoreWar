/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shapka                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggerardy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 17:25:22 by ggerardy          #+#    #+#             */
/*   Updated: 2018/12/13 02:06:03 by ggerardy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void		*ft_realloc(void *old_data, size_t prev_size, size_t new_size)
{
	void	*new_data;
	size_t	i;

	if (!old_data)
		return (0);
	new_data = ft_memalloc(new_size);
	if (!new_data)
	{
		free(old_data);
		return (0);
	}
	i = 0;
	while (i < prev_size && i < new_size)
	{
		((char*)new_data)[i] = ((char*)old_data)[i];
		++i;
	}
	free(old_data);
	return (new_data);
}

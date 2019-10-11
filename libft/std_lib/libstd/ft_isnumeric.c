/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnumeric.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehugh-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 17:05:08 by ehugh-be          #+#    #+#             */
/*   Updated: 2019/07/09 17:05:08 by ehugh-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Check if given string consists only from digits
** @param line - line to be checked
** @return - 1 if there are only digits in line, 0 otherwise
*/

int	ft_isnumeric(char *line)
{
	while(*line != '\0')
	{
		if (!ft_isdigit(*line))
			return (0);
		line++;
	}
	return (1);
}

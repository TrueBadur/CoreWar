/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehugh-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 11:48:55 by ehugh-be          #+#    #+#             */
/*   Updated: 2018/11/24 02:31:16 by ehugh-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

/*
** @param str - string to try to convert to int
** @return - int corresponding to one in string or 0 if something went wrong
**
** Skips space characters then while characters in string is numerical make int.
** Once non numerical symbol is reached stops and returning current value.
** If first nonspace character isn't numerical returns 0;
** In case of int overflow behavior is undefined.
*/

int		ft_atoi(const char *str)
{
	int				answer;
	int				pos;
	unsigned int	d;

	answer = 0;
	pos = 1;
	while (*str == ' ' || *str == '\t' || *str == '\r' || *str == '\n' || *str
			== '\v' || *str == '\f')
		str++;
	if (*str == '-')
	{
		pos = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (1)
	{
		if ((d = *str - '0') > 9)
			break ;
		answer = answer * 10 + d;
		str++;
	}
	return (answer * pos);
}

/*
** @param str - string to convert to int
** @param ans - pointer to integer where to store converted int
** @return - returns -1 if int overflow or int underflow had happened, 1 if
** nonnumeric symbol was reached and 0 if only numerical symbols were read.
**
** Skips space characters then while characters in string is numerical make int.
** Once non numerical symbol or end is reached stops and returning current
** 		value.
*/

char	ft_atoi_safe(const char *str, int *ans)
{
	long			answer;
	char			pos;
	unsigned char	d;

	answer = 0;
	pos = 1;
	while (ft_isspace(*str))
		str++;
	str += (*str == '-') && (pos = -1) ? 1 : 0;
	str += (*str == '+') ? 1 : 0;
	while (1)
	{
		if ((d = *str - '0') > 9)
			break ;
		if (answer * 10 > INT_MAX)
			return ((*ans = 0) - 1);
		answer = answer * 10 + d;
		str++;
	}
	*ans = answer * pos;
	return (*str);
}

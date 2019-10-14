/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shapka.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggerardy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 17:25:22 by ggerardy          #+#    #+#             */
/*   Updated: 2018/11/29 16:09:36 by ggerardy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi_m(const char **str)
{
	int sign;
	int res;

	res = 0;
	while (**str && ft_isspace(**str))
		(*str)++;
	sign = (**str == '-') ? -1 : 1;
	if (**str == '+' || **str == '-')
		(*str)++;
	while (**str && ft_isdigit(**str))
	{
		res = res * 10 + (*(*str)++ - '0') * sign;
	}
	return (res);
}

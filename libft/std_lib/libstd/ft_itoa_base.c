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
#include <stdlib.h>

char		*ft_itoa_base(__int128_t n, int rad)
{
	static char		base[] = "0123456789ABCDEF";
	__int128_t		nb;
	int				len;
	char			*ret;

	len = 2 + (n < 0);
	nb = n;
	while (!(nb < rad && nb > -rad))
	{
		len++;
		nb /= rad;
	}
	if (!(ret = (char *)malloc(sizeof(char) * len)))
		return (NULL);
	ret[--len] = '\0';
	nb = (n < 0) ? -1 : 1;
	while (n || len)
	{
		ret[--len] = base[n % rad * nb];
		n /= rad;
	}
	if (nb < 0)
		ret[0] = '-';
	return (ret);
}

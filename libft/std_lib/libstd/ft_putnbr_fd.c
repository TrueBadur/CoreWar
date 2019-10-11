/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehugh-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 17:45:20 by ehugh-be          #+#    #+#             */
/*   Updated: 2018/11/20 21:43:49 by ehugh-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int		tmp;
	int		nb;
	char	nbr;

	tmp = 1;
	if (n < 0)
	{
		write(fd, "-", 1);
		tmp = -1;
	}
	nb = n;
	while (!(nb < 10 && nb > -10))
	{
		tmp *= 10;
		nb /= 10;
	}
	while (n != 0 || tmp != 0)
	{
		nbr = n / tmp + '0';
		write(fd, &nbr, 1);
		n %= tmp;
		tmp /= 10;
	}
}

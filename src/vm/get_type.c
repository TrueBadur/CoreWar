/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_type.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blomo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 17:14:19 by blomo             #+#    #+#             */
/*   Updated: 2019/10/17 17:41:19 by blomo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "checkop.h"

int get_dir(t_mngr *mngr, int poz, int size)
{
    unsigned char buffer[4];
    int i;
    int c;

    ft_bzero(buffer,4);
    c = 0;
    i = 4;
    while (--size >= 0)
        buffer[i] = mngr->arena[(poz + c++) % MEM_SIZE];
    return (*(int*)buffer);
}

inline char check_reg(int reg)
{
    return ((char)(reg >= 0 && reg <= 15 ? 1 : 0));
}

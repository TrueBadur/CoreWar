/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_type.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blomo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 17:14:19 by blomo             #+#    #+#             */
/*   Updated: 2019/10/23 19:58:18 by blomo            ###   ########.fr       */
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
    i = 3;
    c = 0;
    while (--size >= 0)
    {
        buffer[i] = mngr->arena[(poz + c++) % MEM_SIZE];
        i--;
    }
    return (*(int*)buffer);
}

inline char check_reg(int reg)
{
    return ((char)(reg >= 0 && reg <= 15 ? 1 : 0));
}

int get_indir(t_mngr *mngr, t_car *car, int pos)
{
    int reg;
    int in_dir;

    in_dir = get_dir(mngr,car->pos + pos ,2) % IDX_MOD;
    reg = get_dir(mngr, car->pos + in_dir, 4);
    return(reg);
}

int get_reg(t_mngr *mngr,t_car *car, int pos)
{
    int reg;
    int arg;

    arg = 0;
    reg = mngr->arena[(car->pos + pos) % MEM_SIZE] - 1;
    if (check_reg(reg))
        arg = *(int *)car->regs[reg].reg;
    return(arg);
}

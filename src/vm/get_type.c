/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_type.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blomo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 17:14:19 by blomo             #+#    #+#             */
/*   Updated: 2019/10/24 15:52:52 by blomo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "checkop.h"

int get_dir(t_mngr *mngr, int pos, int size)
{
    char buffer[size];
    int c;

    c = -1;
    while (++c < size)
        buffer[size - c - 1] = (char)mngr->arena[(pos + c) % MEM_SIZE];
    return (size == 2 ? *(short*)buffer : *(int*)buffer);
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

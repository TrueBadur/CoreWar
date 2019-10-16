/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blomo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 15:05:59 by blomo             #+#    #+#             */
/*   Updated: 2019/10/16 21:23:18 by blomo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int get_dir(t_mngr *mngr, int poz, int size)
{
    unsigned char buffer[4];
    int i;
    int c;
    int nbr;

    c = 0;
    i = 4;
    while (--size >= 0 && --i >= 0)
        buffer[i] = mngr->arena[(poz + c++) % MEM_SIZE];
    while(--i >= 0)
        buffer[i] = 0;
    return (*(int*)buffer);
}

void make_live(t_mngr *mngr, t_car *car)
{
    int dir;
    car->eval_in = 10; // number cycle for job
    dir = get_dir(mngr, car->pos + 1, 4);
    car->live_cycle = mngr->cycle;
    if(ft_abs(dir) < MAX_PLAYERS && mngr->chmps[dir])
        mngr->winer = dir;
    mngr->live_num++;
}

void make_ld(t_mngr *mngr, t_car *car)
{
    int arg2;
    char
}




void make_st(t_mngr *mngr, t_car *car)
{

}

void make_add(t_mngr *mngr, t_car *car)
{
    int reg1;
    int reg2;
    int reg3;

    reg1 = mngr->arena[(car->pos + 2 + poz) % MEM_SIZE];
    reg2 = mngr->arena[(car->pos + 3 + poz) % MEM_SIZE];
    reg3 = mngr->arena[(car->pos + 4 + poz) % MEM_SIZE];
    *(int*)car->regs[reg3] = *(int*)car->regs[reg1] + *(int*)car->regs[reg2];
    if(*(int*)car->regs[reg3] == 0)
        car->carry = 1;
    else
        car->carry = 0;
}
void make_sub(t_mngr *mngr, t_car *car)
{

}
void make_and(t_mngr *mngr, t_car *car)
{

}
void make_or(t_mngr *mngr, t_car *car)
{

}
void make_xor(t_mngr *mngr, t_car *car)
{

}
void make_zjmp(t_mngr *mngr, t_car *car)
{

}
void make_ldi(t_mngr *mngr, t_car *car)
{

}
void make_sti(t_mngr *mngr, t_car *car)
{

}
void make_fork(t_mngr *mngr, t_car *car)
{

}
void make_lld(t_mngr *mngr, t_car *car)
{

}
void make_lldi(t_mngr *mngr, t_car *car)
{

}
void make_lfork(t_mngr *mngr, t_car *car)
{

}
void make_aff(t_mngr *mngr, t_car *car)
{

}
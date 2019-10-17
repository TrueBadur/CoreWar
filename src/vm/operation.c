/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blomo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 15:05:59 by blomo             #+#    #+#             */
/*   Updated: 2019/10/17 15:01:35 by blomo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "checkop.h"
#define TYPE1(x) (x >> 2) & 3
#define TYPE2(x) (x >> 4) & 3
#define TYPE3(x) (x >> 6) & 3

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

    car->eval_in = 10;
    dir = get_dir(mngr, car->pos + 1, 4);
    car->live_cycle = mngr->cycle;
    if(ft_abs(dir) < MAX_PLAYERS && mngr->chmps[dir])
        mngr->winer = dir;
    mngr->live_num++;
}

char *read_type(char byte)
{
    char *type;

    type = (char*)malloc(sizeof(char) * 4);
    type[2] = TYPE1(byte);
    type[1] = TYPE2(byte);
    type[0] = TYPE3(byte);
    return (type);
}

int check_reg(int reg)
{

}
void make_ld(t_mngr *mngr, t_car *car)
{
    int dir;
    int reg;
    int ind;
    char *type;

    type = read_type(mngr->arena[(car->pos + 1) % MEM_SIZE]);
    if(type[0] == 2)
    {
        dir = get_dir(mngr, car->pos + 2, 4);
        reg = mngr->arena[(car->pos + 6) % MEM_SIZE];
        if (reg > 16 || reg < 0)
        {
            car->eval_in = 1;
            free(type);
            return ;
        }
        *(int *)car->regs[reg].reg = dir;
        if (dir == 0)
            car->carry = 1;
        else
            car->carry = 0;
        car->eval_in = 5;
    }
    else if(type[0] == 3)
    {
        ind = get_dir(mngr, car->pos + 2, 2) % IDX_MOD;
        dir = get_dir(mngr, car->pos + ind, 4);
        reg = mngr->arena[(car->pos + 4) % MEM_SIZE];
        if (reg > 16 || reg < 0)
        {
            car->eval_in = 1;
            free(type);
            return ;
        }
        *(int *)car->regs[reg].reg = dir;
        if (dir == 0)
            car->carry = 1;
        else
            car->carry = 0;
        car->eval_in = 5;
    }
    free(type);
}




void make_st(t_mngr *mngr, t_car *car)
{

}

void make_add(t_mngr *mngr, t_car *car)
{
    int reg1;
    int reg2;
    int reg3;

    reg1 = mngr->arena[(car->pos + 2) % MEM_SIZE];
    reg2 = mngr->arena[(car->pos + 3) % MEM_SIZE];
    reg3 = mngr->arena[(car->pos + 4) % MEM_SIZE];
    if ((reg1 > 16 || reg1 < 0) && (reg2 > 16 || reg2 < 0) && (reg3 > 16 || reg3 < 0)) {
        car->eval_in = 1;
        return;
    }
    *(int*)car->regs[reg3].reg = *(int*)car->regs[reg1].reg + *(int*)car->regs[reg2].reg;
    if(*(int*)car->regs[reg3].reg == 0)
        car->carry = 1;
    else
        car->carry = 0;
    car->eval_in = 10;
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
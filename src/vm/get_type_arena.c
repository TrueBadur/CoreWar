/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_type_arena.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blomo <blomo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 17:02:20 by blomo             #+#    #+#             */
/*   Updated: 2019/11/13 20:36:09 by blomo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "checkop.h"

int			get_addr_arena(int adr)
{
	return ((adr < 0) ? (adr % MEM_SIZE) + MEM_SIZE : (adr % MEM_SIZE));
}

int			get_dir(t_mngr *mngr, int *pos, int size)
{
	char	buffer[size];
	int		c;

	c = -1;
	while (++c < size)
		buffer[size - c - 1] = (char)mngr->arena[get_addr_arena(*pos + c)];
	*pos += size;
	return (size == 2 ? *(short*)buffer : *(int*)buffer);
}

inline char	check_reg(int reg)
{
	return ((char)(reg >= 0 && reg <= 15 ? 1 : 0));
}

void		copy_reg_to_arena(t_mngr *mngr, t_car *car, int reg1, int reg2)
{
	unsigned int	c;

	c = -1;
	while (++c < REG_SIZE)
		mngr->arena[get_addr_arena(reg2 + c)] =
		car->regs[reg1].reg[REG_SIZE - 1 - c];
}

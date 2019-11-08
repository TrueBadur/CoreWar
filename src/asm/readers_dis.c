/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readers_dis.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleann <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 02:46:11 by jleann            #+#    #+#             */
/*   Updated: 2019/11/02 02:46:13 by jleann           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <errno.h>
#include "disassembler.h"

int			read_int32(int fd)
{
	int		ret;
	char	tmp[4];
	char	tmp2[4];

	ret = read(fd, tmp, 4);
	if (ret != -1 && ret != 4)
		raise_error_dis(UNEXPECTED_EOF_ERR);
	else if (ret == -1)
	{
		perror(strerror(errno));
		exit(1);
	}
	tmp2[0] = tmp[3];
	tmp2[1] = tmp[2];
	tmp2[2] = tmp[1];
	tmp2[3] = tmp[0];
	return (*((int *)tmp2));
}

void		read_arr(int fd, void *target, size_t size)
{
	int	ret;

	ret = read(fd, target, size);
	if (ret != -1 && ret != size)
		raise_error_dis(UNEXPECTED_EOF_ERR);
	else if (ret == -1)
	{
		perror(strerror(errno));
		exit(1);
	}
}

int			read_int32_mem(char *mem, size_t *ind, size_t cap)
{
	char	res[4];

	if (*ind + 4 > cap)
		raise_error_dis(UNEXPECTED_EOF_ERR);
	res[0] = mem[*ind + 3];
	res[1] = mem[*ind + 2];
	res[2] = mem[*ind + 1];
	res[3] = mem[*ind + 0];
	*ind += 4;
	return (*((int *)res));
}

short		read_int16_mem(char *mem, size_t *ind, size_t cap)
{
	char	res[2];

	if (*ind + 2 > cap)
		raise_error_dis(UNEXPECTED_EOF_ERR);
	res[0] = mem[*ind + 1];
	res[1] = mem[*ind + 0];
	*ind += 2;
	return (*((short *)res));
}

char		read_int8_mem(char *mem, size_t *ind, size_t cap)
{
	char	res;

	if (*ind + 1 > cap)
		raise_error_dis(UNEXPECTED_EOF_ERR);
	res = mem[*ind];
	*ind += 1;
	return (res);
}

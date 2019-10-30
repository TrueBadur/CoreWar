/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   writer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleann <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 18:32:50 by jleann            #+#    #+#             */
/*   Updated: 2019/10/26 18:32:51 by jleann           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "writer.h"
#include <unistd.h>
#include <fcntl.h>

void	write_uint16_to_bin(int fd, uint16_t num)
{
	uint8_t buff[2];

	buff[1] = ((uint8_t *)(&num))[0];
	buff[0] = ((uint8_t *)(&num))[1];
	write(fd, buff, 2);
}

void	write_uint32_to_bin(int fd, uint32_t num)
{
	write_uint16_to_bin(fd, ((uint16_t *)(&num))[1]);
	write_uint16_to_bin(fd, ((uint16_t *)(&num))[0]);
}

void	write_champ(t_champdata *champdata, t_argdata *args)
{
	int fd;

	if ((fd = (open(args->ofname,
			O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU | S_IRWXG | S_IRWXO))) == -1)
	{
		ft_fdprintf(STDERR_FILENO, "Cannot create file(((\n");
		exit(2);
	}
	write_uint32_to_bin(fd, 0xea83f3);
	write(fd, champdata->champ_name, 128);
	write(fd, "\0\0\0\0", 4);
	write_uint32_to_bin(fd, champdata->size);
	write(fd, champdata->champ_comment, 2048);
	write(fd, "\0\0\0\0", 4);
	write(fd, champdata->exec_code, champdata->size);
	close(fd);
}

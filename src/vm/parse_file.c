/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blomo <blomo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 10:04:59 by blomo             #+#    #+#             */
/*   Updated: 2019/10/14 10:05:21 by blomo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		byte_atoi(const unsigned char *bytecode, size_t size)
{
	int		result;
	char	sign;
	int		i;

	result = 0;
	sign = (char)(bytecode[0] & 0x80);
	i = 0;
	while (size)
	{
		if (sign)
			result += ((bytecode[size - 1] ^ 0xFF) << (i++ * 8));
		else
			result += bytecode[size - 1] << (i++ * 8);
		size--;
	}
	if (sign)
		result = ~(result);
	return (result);
}

int		get4byte(int fd)
{
	size_t	size;
	char buffer[4];

	size = read(fd, &buffer, 4);
	if (size < 4)
		printf("error size of file");
	return (byte_atoi(buffer, 4));
}

char		*get_str(int fd, size_t len)
{
	int	size;
	char	*buffer;
	if (!(buffer = (char*)malloc(sizeof(char) * len)))
		printf("error");
	size = read(fd, buffer, len);
	if (size == -1 || size < (size_t)len)
		printf("error");
	return (buffer);
}


unsigned char	*get_code(int fd, size_t len)
{
	int	size;
	unsigned char	*buffer;
	unsigned char	byte;

	if (!(buffer = (char*)malloc(sizeof(char)*(len))))
		printf("error");
	size = read(fd, buffer, len);
	if (size == -1 || size < (size_t)len || read(fd, &byte, 1) != 0)
		printf("error");
	// printf("%s\n",buffer);
	return (buffer);
}


void pars_cor(char *file, t_mngr *mngr)
{
	int fd;

	if ((fd = open(file, O_RDONLY)) < 0)
		printf("error open file");
	if (get4byte(fd) != 0xea83f3)
		printf("bad magic constant\n");
	mngr->chmps->name = get_str(fd, 128);
	if (get4byte(fd) != 0)
		printf("no null byte");
	mngr->chmps->code_size = get4byte(fd);

	if ((mngr->chmps->code_size < 0) || (mngr->chmps->code_size> 683))
		printf("bad code size");
	mngr->chmps->comment = get_str(fd, 2048);
	if (get4byte(fd) != 0)
		printf("no null byte");
	mngr->chmps->code = get_code(fd, (size_t)mngr->chmps->code_size);
}




void		pars_file(char *str, t_mngr *mngr)
{
	int i;

	i = strlen(str);
	i = i - 4;
	if (i>0 && !strcmp(str+i, ".cor"))
		pars_cor(str,mngr);
	else
		printf("error\n");
}


void validate_input(t_mngr *mngr, int argc,char **argv)
{
	int i;

	i = 1;
	while (argc > i)
	{
		pars_file(argv[i], mngr);
		i++;
	}
}

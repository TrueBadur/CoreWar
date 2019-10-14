/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehugh-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 10:04:59 by blomo             #+#    #+#             */
/*   Updated: 2019/10/14 23:21:58 by ehugh-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		byte_atoi( unsigned char *bytecode, size_t size)
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
	unsigned char buffer[4];

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

	if (!(buffer = (unsigned char*)malloc(sizeof(unsigned char)*(len))))
		printf("error");
	size = read(fd, buffer, len);
	if (size == -1 || size < (size_t)len || read(fd, &byte, 1) != 0)
		printf("error");
	// printf("%s\n",buffer);
	return (buffer);
}


void parse_cor(char *file, t_mngr *mngr, int nbr)
{
	int fd;
    mngr->chmps[nbr] = (t_chmp *) malloc(sizeof(t_chmp));
	if ((fd = open(file, O_RDONLY)) < 0)
        safe_exit(mngr, INVALID_N);
	if (get4byte(fd) != 0xea83f3)
        safe_exit(mngr, INVALID_N);
    mngr->chmps[nbr]->name = get_str(fd, 128);
	if (get4byte(fd) != 0)
        safe_exit(mngr, INVALID_N);
	mngr->chmps[nbr]->size = get4byte(fd);
	if ((mngr->chmps[nbr]->size < 0) || (mngr->chmps[nbr]->size > 682))
        safe_exit(mngr, INVALID_N);
	mngr->chmps[nbr]->moto = get_str(fd, 2048);
	if (get4byte(fd) != 0)
        safe_exit(mngr, INVALID_N);
    mngr->chmps[nbr]->code = get_code(fd, (size_t)mngr->chmps[nbr]->size);
    mngr->chmp_num++;
}




void		parse_file(char *str, t_mngr *mngr, int nbr)
{
	int i;
	int c;

	c = 0;
    if(str == NULL)
        safe_exit(mngr, INVALID_N);
    if(mngr->chmps[nbr] != NULL)
        safe_exit(mngr, INVALID_N);
	i = ft_strlen(str);
	i = i - 4;
	if (i > 0 && !ft_strcmp(str+i, ".cor") && mngr->chmps[nbr] == NULL)
		parse_cor(str, mngr, nbr);
	else
        safe_exit(mngr, INVALID_N);
}




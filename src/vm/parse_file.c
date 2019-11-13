/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blomo <blomo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 10:04:59 by blomo             #+#    #+#             */
/*   Updated: 2019/11/13 20:25:30 by blomo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int					get4byte(t_mngr *mngr, int fd)
{
	size_t			size;
	unsigned char	buffer[4];
	int				i;

	i = 4;
	size = 0;
	while (--i >= 0)
		size += read(fd, &buffer[i], 1);
	if (size < 4)
		safe_exit(mngr, FEW_BYTE, NULL);
	return (*(int*)buffer);
}

char				*get_str(int fd, size_t len, t_mngr *mngr)
{
	int				size;
	char			*buffer;

	if (!(buffer = (char*)malloc(sizeof(char) * (len + 1))))
		safe_exit(mngr, MALLOC_ERROR, NULL);
	size = read(fd, buffer, len);
	buffer[size] = '\0';
	if (size == -1 || size < (size_t)len)
		safe_exit(mngr, READ_ERROR, NULL);
	return (buffer);
}

unsigned char		*get_code(t_mngr *mngr, int fd, size_t len)
{
	int				size;
	unsigned char	*buffer;
	unsigned char	byte;

	if (!(buffer = (unsigned char*)malloc(sizeof(unsigned char) * (len))))
		safe_exit(mngr, MALLOC_ERROR, NULL);
	size = read(fd, buffer, len);
	if (size == -1 || size < (size_t)len || read(fd, &byte, 1) != 0)
		safe_exit(mngr, READ_ERROR, NULL);
	return (buffer);
}

void				parse_cor(char *file, t_mngr *mngr, int nbr)
{
	int				fd;

	if ((fd = open(file, O_RDONLY)) < 0)
		safe_exit(mngr, OPEN_ERROR, NULL);
	if (!(mngr->chmps[nbr] = (t_chmp *)malloc(sizeof(t_chmp))))
		safe_exit(mngr, MALLOC_ERROR, NULL);
	mngr->chmps[nbr]->id = nbr;
	if (get4byte(mngr, fd) != COREWAR_EXEC_MAGIC)
		safe_exit(mngr, INVALID_EXEC_MAGIC, NULL);
	mngr->chmps[nbr]->name = get_str(fd, 128, mngr);
	if (get4byte(mngr, fd) != 0)
		safe_exit(mngr, NO_ZERO_BYTE, NULL);
	mngr->chmps[nbr]->size = get4byte(mngr, fd);
	if ((mngr->chmps[nbr]->size < 0) || (mngr->chmps[nbr]->size > 682))
		safe_exit(mngr, INVALID_SIZE_BYTE_CHAMPION, NULL);
	mngr->chmps[nbr]->moto = get_str(fd, COMMENT_LENGTH, mngr);
	if (get4byte(mngr, fd) != 0)
		safe_exit(mngr, NO_ZERO_BYTE, NULL);
	mngr->chmps[nbr]->code = get_code(mngr, fd, (size_t)mngr->chmps[nbr]->size);
	mngr->chmp_num++;
}

void				parse_file(char *str, t_mngr *mngr, int nbr)
{
	int				i;

	if (str == NULL)
		safe_exit(mngr, INVALID_ARGUMENT_NAME, NULL);
	if (mngr->chmps[nbr] != NULL)
		safe_exit(mngr, INVALID_ARRAY_CHAMPION, NULL);
	i = ft_strlen(str);
	i = i - 4;
	if (i > 0 && !ft_strcmp(str + i, ".cor") && mngr->chmps[nbr] == NULL)
		parse_cor(str, mngr, nbr);
	else
		safe_exit(mngr, INVALID_FILE_EXTENSION, NULL);
}

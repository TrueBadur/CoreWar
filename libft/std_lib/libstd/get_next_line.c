/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehugh-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 12:51:25 by ehugh-be          #+#    #+#             */
/*   Updated: 2019/07/10 18:44:00 by ehugh-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"
#include <stdio.h>

static int		ft_gnlsub(t_vector *vec, int offset, char **line)
{
	if (!(*line = malloc(offset + 1)))
		return (-1);
	ft_memcpy(*line, vec->data + vec->offset, offset);
	*(*line + offset) = '\0';
	vec->offset += offset + 1;
	return (1);
}

static int		ft_checkbuf(t_vector *vec, char **line, int offset, int rr)
{
	int		i;
	char	*src;

	if (!vec)
		return (0);
	i = 0;
	src = (char *)vec->data + vec->offset + offset;
	while (1)
	{
		if (src + i >= ((char *)vec->data) + vec->len)
		{
			if (rr < BUFF_SIZE)
				return (ft_gnlsub(vec, offset + i, line));
			if (vec->len - vec->offset < vec->cap / 3 && vec->cap > BUFF_SIZE)
				vec = ft_vecshrink(vec, vec->offset);
			return (0);
		}
		if (src[i] == '\n')
			return (ft_gnlsub(vec, offset + i, line));
		i++;
	}
}

static int		ft_readtobuf(t_vector *vec, char **line, int fd)
{
	int rr;
	int	tmp;
	int	i;

	i = 0;
	while (1)
	{
		if (vec->len && vec->len < vec->cap / 4 && vec->cap > BUFF_SIZE)
			if (!(vec = ft_vecshrink(vec, 0)))
				return (-1);
		if (vec->cap - vec->len < BUFF_SIZE)
			if (!(vec = ft_vecgrow(vec, vec->cap * 2)))
				return (-1);
		rr = read(fd, (vec->data + vec->len), BUFF_SIZE);
		if (rr < 0 || rr == 0)
			return (rr);
		vec->len += rr;
		i += rr;
		if ((tmp = ft_checkbuf(vec, line, i - rr, rr)))
			return (tmp);
	}
}

static t_vector	*ft_checkfd(t_btavl **tr, int key)
{
	t_vector	*tmp;
	t_btavl		*tmtr;

	if (!tr)
		return (NULL);
	if (!(tmp = ft_avlsearch(*tr, TO_AVL_KEY(key), 1, NULL)))
	{
		if (!(tmp = ft_vecinit(BUFF_SIZE)))
			return (NULL);
		if (!(tmtr = ft_avlnew(tmp, TO_AVL_KEY(key), sizeof(t_vector), NUM32)))
		{
			free(tmp);
			return (NULL);
		}
		*tr = ft_avlins(*tr, tmtr, NULL);
		free(tmp);
		return (t_vector *)(tmtr->data);
	}
	return (t_vector *)(tmp);
}

int				get_next_line(const int fd, char **line)
{
	static t_btavl	*tree = NULL;
	int				tmp;
	t_vector		*vector;

	if (!line || fd < 0)
		return (-1);
	*line = NULL;
	vector = ft_checkfd(&tree, fd);
	if ((tmp = ft_checkbuf(vector, line, 0, BUFF_SIZE)))
	{
		if (tmp == -1)
			ft_avlrem(tree, TO_AVL_KEY(fd), &ft_vecdel, NULL);
		return (tmp);
	}
	tmp = ft_readtobuf(vector, line, fd);
	if (tmp != 1 || (unsigned)vector->offset > vector->len)
	{
		if ((unsigned)vector->offset < vector->len)
			tmp = ft_gnlsub(vector, vector->len - vector->offset, line);
		tree = ft_avlrem(tree, TO_AVL_KEY(fd), &ft_vecdel, NULL);
	}
	return (tmp);
}

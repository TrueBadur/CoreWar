#include <stdio.h>
#include <errno.h>
#include "disassembler.h"

int		read_int32(int fd)
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
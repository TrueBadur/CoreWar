/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disassembler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleann <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 18:29:01 by jleann            #+#    #+#             */
/*   Updated: 2019/10/26 18:29:02 by jleann           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "read_args.h"
#include "ft_printf.h"
#include "disassembler.h"
#include "op.h"

void	raise_error_dis(const char *str)
{
	ft_printf("%s\n", str);
	exit(1);
}

void	*check_header(int fd, t_headdata *headdata)
{
	int		res;
	void	*exec_code;

	if (read_int32(fd) != COREWAR_EXEC_MAGIC)
		raise_error_dis(WRONG_FILE_FORMAT_ERR);
	read_arr(fd, headdata->champ_name, PROG_NAME_LENGTH);
	if (read_int32(fd) != 0)
		raise_error_dis(WRONG_FILE_FORMAT_ERR);
	headdata->size = read_int32(fd);
	read_arr(fd, headdata->champ_comment, COMMENT_LENGTH);
	if (read_int32(fd) != 0)
		raise_error_dis(WRONG_FILE_FORMAT_ERR);
	exec_code = ft_memalloc(headdata->size);
	read_arr(fd, exec_code, headdata->size);
	return (exec_code);
}

void	disassemble(t_argdata *args)
{
	int			fd;
	t_headdata	data;
	void		*exec_code;
	t_list		cmd_lst;

	if ((fd = open(args->fname, O_RDONLY)) == -1)
		raise_error_dis(CONNOT_OPEN_FILE_ERR);
	ft_bzero(&data, sizeof(t_headdata));
	exec_code = check_header(fd ,&data);
	generate_commands_dis(&data, exec_code, &cmd_lst);
	write_commands_dis(&data, &cmd_lst, args->ofname);
}

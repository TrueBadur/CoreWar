/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disassembler.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleann <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 16:17:16 by jleann            #+#    #+#             */
/*   Updated: 2019/10/30 16:17:17 by jleann           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISASSEMBLER_H
# define DISASSEMBLER_H

# include "read_args.h"
# include "ft_list.h"
# include "lexer.h"

# define CONNOT_OPEN_FILE_ERR "Cannot open file!"
# define UNEXPECTED_EOF_ERR "Unexpected end of file!"
# define WRONG_FILE_FORMAT_ERR "Wrong file format!"
# define SIZE_MISMATCH_ERR "Size mismatch!"

typedef struct		s_headdata
{
	short			filler2;
	char			champ_comment[COMMENT_LENGTH];
	uint32_t		size;
	short			filler1;
	char			champ_name[PROG_NAME_LENGTH];
	uint32_t		magic;
}					t_headdata;

typedef struct		s_command
{
	char			cmd_type;
	t_token			*params[3];
	size_t			pos_in_file;
}					t_command;

void		disassemble(t_argdata *args);
void		write_commands_dis(t_headdata *data, t_list *cmd_lst, char *ofname);
void		generate_commands_dis(t_headdata *data,
							  void *exec_code, t_list *cmd_lst);
void		raise_error_dis(const char *str);
int			read_int32(int fd);
void		read_arr(int fd, void *target, size_t size);

#endif

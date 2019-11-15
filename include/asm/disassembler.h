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
# define INVALID_PAR_TYPE_ERR "Invalid parameter type!"
# define INVALID_CMD_TYPE_ERR "Invalid command type!"

typedef struct		s_headdata
{
	char			champ_comment[COMMENT_LENGTH];
	uint32_t		size;
	char			champ_name[PROG_NAME_LENGTH];
}					t_headdata;

typedef struct		s_param
{
	char			type;
	int				data;
}					t_param;

typedef struct		s_command
{
	char			cmd_type;
	char			par_types;
	t_param			params[3];
}					t_command;

void				disassemble(t_argdata *args);
void				write_commands_dis(t_headdata *data, t_list *cmd_lst,
										char *ofname);
void				generate_commands_dis(t_headdata *data,
										void *exec_code, t_list *cmd_lst);
void				raise_error_dis(const char *str);
int					read_int32(int fd);
void				read_arr(int fd, void *target, size_t size);
char				read_int8_mem(char *mem, size_t *ind, size_t cap);
short				read_int16_mem(char *mem, size_t *ind, size_t cap);
int					read_int32_mem(char *mem, size_t *ind, size_t cap);

#endif

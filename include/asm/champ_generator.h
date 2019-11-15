/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   champ_generator.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleann <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 16:18:39 by jleann            #+#    #+#             */
/*   Updated: 2019/10/30 16:18:40 by jleann           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHAMP_GENERATOR_H
# define CHAMP_GENERATOR_H

# include "lexer.h"
# include "ft_list.h"

typedef struct		s_champdata
{
	t_list			commands;
	char			champ_name[PROG_NAME_LENGTH + 1];
	char			champ_comment[COMMENT_LENGTH + 1];
	void			*exec_code;
	size_t			size;
}					t_champdata;

typedef struct		s_command
{
	char			cmd_type;
	t_token			*params[3];
	t_token			*label;
	size_t			pos_in_file;
}					t_command;

t_champdata			*run_champgenerator(t_lexdata *data);
void				free_champdata(t_champdata *data);
void				generate_code(t_champdata *data);
void				generate_commands(t_champdata *cdata, t_lexdata *ldata);
void				raise_error_sem(const char *str, t_token *token);
t_token				*eat(t_list_node **lst, char type);
size_t				calc_command_size(t_command *cmd);

# define UNEXPECTED_TOKEN_AT_ERR "Unexpected token, "
# define UNEXPECTED_EOF_ERR "Unexpected end of file, "
# define INVALID_PAR_TYPE_ERR "Invalid parameter type, "
# define NO_CHAMP_NAME_PROVIDED_ERR "No champ name provided!"
# define NO_CHAMP_COMMENT_PROVIDED_ERR "No champ comment provided!"
# define NO_CHAMP_CODE_PROVIDED_ERR "No champ code provided!"
# define T_REG_CODE 1U
# define T_DIR_CODE 2U
# define T_IND_CODE 3U

#endif

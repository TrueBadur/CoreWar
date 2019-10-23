//
// Created by Jasper Leann on 11/10/2019.
//

#ifndef COREWAR_LEXER_H
# define COREWAR_LEXER_H
# define CMD_START '.'
# define ARG_CMD_START '"'

# define ERROR_LEX_NAME_START 1
# define ERROR_LEX_MALLOC_STR 2
# define ERROR_LEX_SHORT_ARG_CMD_NAME 3
# define ERROR_LEX_NAME_END_INVALIDE 4
# define ERROR_LEX_NULL_NODE 5
# define ERROR_LEX_FD 6
# define ERROR_LEX_UNDEFINE_CMD 7
# define ERROR_LEX_NOT_LABEL_CHAR 8
# define ERROR_LEX_INST_NOT_FOUND 9
# define ERROR_LEX_MALLOC 10
# define ERROR_LEX_LABEL_UPDATE 11
# define ERROR_LEX_GNL 12
# define ERROR_LEX_MALLOC_DAT 13

#define BEGIN_ID 0
#define LABEL_ID 1
#define CMD_ID 2
#define ENDL_ID 3
#define PARAM_ID 4
#define DELIM_ID 5
#define END_ID 6

#define INST_ID 7
#define PARAM_REG_ID 1
#define PARAM_DIR_ID 2
#define PARAM_IND_ID 4

#define PARAM_LABEL 11
#define PARAM_INT 12

#define TOKEN_TYPE_INST 0
#define TOKEN_TYPE_DELIM 1
#define TOKEN_TYPE_END 2
#define TOKEN_TYPE_P_R 3
#define TOKEN_TYPE_P_D_I 4
#define TOKEN_TYPE_P_I_I 5
#define TOKEN_TYPE_LABEL 6
#define TOKEN_TYPE_P_D_L 7
#define TOKEN_TYPE_P_I_L 8

# include "ft_list.h"
# include "libft.h"
//# include "libft_full.h"
# include <fcntl.h>
# include "op.h"

typedef struct		s_token
{
	char	token_type;
	char	type;
	char 	sub_type;
	char 	val_type;
	void	*label;
	int		data;
	int 	line_num;
	int 	pos_num;
}					t_token;

typedef struct		s_lexdata
{
	char			debug_fd;
	char			debug_gnl;
	char			debug_comment;
	char			debug_name;
	char			debug_happend;
	char			debug_out;
    char			debug_done;
	char			debug_err;

	int				fd;
	t_list			token_list;
	char			*champ_name;
	char 			*champ_comment;
	t_list			label_list;
	t_list			lines;

	char			*cur_line;
	int				srt;
	int				end;
}					t_lexdata;

int					run_lexer(char *fname, t_lexdata **dat);
void				free_lexdata(t_lexdata *data);
int					add_line(t_lexdata *dat, char *line);
void 				init_stack_list(t_list *lst);
int					init_dat(t_lexdata **dat);
int					get_fd(char *fname, t_lexdata *dat);
int					error_case(t_lexdata *dat, int error_case);
int					process_cmd(t_lexdata *dat, char *cur, int id_cmd);
int					end_line(char cur);
int					check_comment(t_lexdata *dat, char *cur);
int					short_name(char *line, char **to_set);
int					long_name(t_lexdata *dat, char *start, t_list *lines, char **to_set);
void				debug_cmd_name(t_lexdata *dat, int id_cmd);
void				free_list(t_list *lst);
int					add_label(t_lexdata *dat);
void				debug_token_list(t_lexdata *dat);
int					allowed_char(char cur);
int					not_skip_char(char cur);
int					add_inst(t_lexdata *dat);
int					add_parm(t_lexdata *dat);
int					add_token(t_lexdata *dat, char token_type, int data, char *label);
int					add_token_sep(t_lexdata *dat);
int					add_token_endline(t_lexdata *dat);
int					add_token_nodata(t_lexdata *dat, char token_type);
int					add_token_data(t_lexdata *dat, char token_type, int data);
int					add_token_str(t_lexdata *dat, char token_type, char *label);
int					update_label(t_lexdata *dat);
void				debug_token(t_token *tkn, int idx);
void				debug_label_list(t_lexdata *dat);

#endif //COREWAR_LEXER_H

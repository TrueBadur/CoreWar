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

# include "ft_list.h"
# include "libft.h"
//# include "libft_full.h"
# include <fcntl.h>
# include "op.h"

typedef struct		s_token
{
	char	type;
	void	*data;
	int 	line_num;
	int 	pos_num;
}					t_token;

typedef struct		s_lexdata
{
	char			debug_fd;
	char			debug_comment;
	char			debug_name;

	t_list	token_list;
	char	*champ_name;
	char 	*champ_comment;
	t_list	label_list;
}					t_lexdata;

t_lexdata	*run_lexer(char *fname);
void		free_lexdata(t_lexdata *data);

#endif //COREWAR_LEXER_H

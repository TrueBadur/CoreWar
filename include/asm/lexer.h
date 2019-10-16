//
// Created by Jasper Leann on 11/10/2019.
//

#ifndef COREWAR_LEXER_H
#define COREWAR_LEXER_H

#include "ft_list.h"

typedef struct		s_token
{
	char	type;
	char 	sub_type;
	char 	val_type;
	void	*data;
	int 	line_num;
	int 	pos_num;
}					t_token;

typedef struct		s_lexdata
{
	t_list	token_list;
	char	*champ_name;
	char 	*champ_comment;
	t_list	label_list;
}					t_lexdata;

t_lexdata	*run_lexer(char *fname);
void		free_lexdata(t_lexdata *data);

#endif //COREWAR_LEXER_H

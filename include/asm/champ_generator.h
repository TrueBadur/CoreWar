//
// Created by Jasper Leann on 11/10/2019.
//

#ifndef COREWAR_CHAMP_GENERATOR_H
#define COREWAR_CHAMP_GENERATOR_H

#include "lexer.h"
#include "ft_list.h"

typedef struct		s_champdata
{
	t_list	commands;
	t_list	label_list;
	char 	*champ_name;
	char 	*champ_comment;
}					t_champdata;

t_champdata		*run_champgenerator(t_lexdata *data);
void			free_champdata(t_champdata *data);

#endif //COREWAR_CHAMP_GENERATOR_H

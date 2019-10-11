//
// Created by Jasper Leann on 11/10/2019.
//

#include "champ_generator.h"
#include <libstd.h>

t_list			read_tokens(t_lexdata *data)
{

}

t_champdata		*run_champgenerator(t_lexdata *data)
{
	t_champdata	*res;

	res = ft_memalloc(sizeof(t_champdata));
	res->champ_name = data->champ_name;
	res->champ_comment = data->champ_comment;
	res->commands = read_tokens(data);
	return (res);
}

void			free_champdata(t_champdata *data)
{

}

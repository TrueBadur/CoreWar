/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   champ_generator.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleann <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 18:28:14 by jleann            #+#    #+#             */
/*   Updated: 2019/10/26 18:28:19 by jleann           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libstd.h"
#include "champ_generator.h"
#include "lexer.h"

t_champdata	*run_champgenerator(t_lexdata *data)
{
	t_champdata	*res;

	res = ft_memalloc(sizeof(t_champdata));
	if (!data->champ_name)
		raise_error_sem(NO_CHAMP_NAME_PROVIDED_ERR, NULL);
	if (!data->champ_comment)
		raise_error_sem(NO_CHAMP_COMMENT_PROVIDED_ERR, NULL);
	if (data->token_list.len == 0)
		raise_error_sem(NO_CHAMP_CODE_PROVIDED_ERR, NULL);
	ft_strcpy(res->champ_name, data->champ_name);
	ft_strcpy(res->champ_comment, data->champ_comment);
	generate_commands(res, data);
	generate_code(res);
	return (res);
}

void		raise_error_sem(const char *str, t_token *token)
{
	if (token)
		ft_printf("%s at: (%d, %d)\n", str, token->line_num, token->pos_num);
	else
		ft_printf("%s\n", str);
	exit(2);
}

void		free_champdata(t_champdata *data)
{
	t_list_node	*tmp;
	t_list_node	*tmpn;

	free(data->exec_code);
	tmp = data->commands.begin;
	while (tmp)
	{
		tmpn = tmp->next;
		free(tmp->content);
		free(tmp);
		tmp = tmpn;
	}
	free(data);
}

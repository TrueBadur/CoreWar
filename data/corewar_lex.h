/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_lex.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: PhilippNox <PhilippNox@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 14:44:40 by wgorold           #+#    #+#             */
/*   Updated: 2019/10/11 04:58:13 by PhilippNox       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_LEX
# define COREWAR_LEX

# define LABEL "LABEL"
# define DIRECT_LABEL "DIRECT_LABEL"
# define REGISTER "REGISTER"
// etc.

/*
** type 			= 1				= 3				//тип токена числом
** str_type 		= "LABEL"		= "REGISTER"	//тип токена стракой
** raw_data     	= "loop:"		= "r1"			//данные из файла строкой
** data				= "loop"		= NULL			//очищенная строка
** num_data			= 0				= 1				//чистые числовые данные
*/

typedef struct		s_token
{
	unsigned char	type;
	char			*str_type;
	char			*raw_data;
	char			*data;
	int				num_data;
}					t_token;

#endif

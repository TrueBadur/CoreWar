/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehugh-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 16:27:53 by ehugh-be          #+#    #+#             */
/*   Updated: 2019/10/14 16:24:08 by ehugh-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef COREWAR_COREWAR_H
#define COREWAR_COREWAR_H

#include <libft.h>
#include "op.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
typedef enum 	e_exit_codes
{
	SUCCESS,
	MALLOC_ERROR,
    FEW_PARAMETR,
    NOTVALIDN,
}				t_eexcode;

typedef struct	s_chmp
{
	size_t 		size;
	char		*name;
	char 		*moto;
	int			code_size;
	char        *code;
	int			id;
}				t_chmp;

typedef struct	s_mngr
{
	t_vector	*flags; //TODO make flags
	t_chmp		*chmps[MAX_PLAYERS];
	t_vector	*carrieges;  //TODO chose storage structure for carriges
	char 		*arena;
	int			chmp_num;
	int 		cycle;
	int			arena_size;
	int			live_num;
	int			cycles_to_die;
	int			num_checks;
}				t_mngr;

void			validate_input(t_mngr *mngr, int argc, char **argv);
void			game_main(t_mngr *mngr);
void			safe_exit(t_mngr *mngr, enum e_exit_codes code);
void			init_arena(t_mngr *mngr);
void		    pars_file(char *str, t_mngr *mngr, int nbr);

#endif //COREWAR_COREWAR_H

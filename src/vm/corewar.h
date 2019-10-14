/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blomo <blomo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 16:27:53 by ehugh-be          #+#    #+#             */
/*   Updated: 2019/10/14 09:41:46 by blomo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef COREWAR_COREWAR_H
#define COREWAR_COREWAR_H
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

enum 			e_exit_codes
{
	SUCCESS,
	MALLOC_ERROR,
};

typedef struct	s_chmp
{
	size_t 		size;
	char		*name;
	char 		*moto;
	char		*comment;
	int			code_size;
	char		*code;
	int			id;
}				t_chmp;

typedef struct	s_mngr
{
	t_chmp		*chmps;
	char 		*arena;
	int			chmp_num;
	int 		cycle;
	int			arena_size;
	int			live_num;
	int			cycles_to_die;
	int			num_checks;
}				t_mngr;

void			validate_input(t_mngr *mngr, int argc, char **argv);
// void			champion_introduce(t_mngr *mngr);
// void			game_main(t_mngr *mngr);
// void			winer_anounce(t_mngr *mngr);
// void			safe_exit(t_mngr *mngr, enum e_exit_codes code);
// void			init_arena(t_mngr *mngr);

#endif

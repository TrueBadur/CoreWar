/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehugh-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 16:27:53 by ehugh-be          #+#    #+#             */
/*   Updated: 2019/10/11 16:45:40 by ehugh-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef COREWAR_COREWAR_H
#define COREWAR_COREWAR_H

#include <libft.h>

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
	int			*code;
	int			id;
}				t_chmp;

typedef struct	s_mngr
{
	t_vector	*flags; //TODO make flags
	t_chmp		*chmps;
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
void			champion_introduce(t_mngr *mngr);
void			game_main(t_mngr *mngr);
void			winer_anounce(t_mngr *mngr);
void			safe_exit(t_mngr *mngr, enum e_exit_codes code);
void			init_arena(t_mngr *mngr);

#endif //COREWAR_COREWAR_H

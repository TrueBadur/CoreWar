/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blomo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 16:27:53 by ehugh-be          #+#    #+#             */
/*   Updated: 2019/10/30 14:37:38 by blomo            ###   ########.fr       */
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
#include <ncurses.h>
#include <stdlib.h>
#include <signal.h>

#define MAX_OP_TIME 1000
#define FLAG_DUMP ((unsigned int)1 << (unsigned int)4)
#define FLAG_V ((unsigned int)1 << (unsigned int)5)
#define FLAG_S ((unsigned int)1 << (unsigned int)6)
#define ARG_REG_S 1

#define PLAYER_SHIFT 1
#define P1 1
#define P2 2
#define P3 3
#define P4 4
#define PU 5
#define DEF 6
#define BLOOD 7
#define BRUTAL 8
#define RIP 9
#define DOOM 10
#define P1H 11
#define P2H 12
#define P3H 13
#define P4H 14
#define PUH 15

#define G_MOD_PAUSE_ALL 1
#define G_MOD_PAUSE_SELECT 2
#define G_MOD_NO_PAUSE 3

#define G_PHASE_MEM_CHANGE 1

#define IMG_NUM 4

#define COL_STEP 3
#define LIN_STEP 2
#define	COL_IN_LIN 64
#define	SHIFT_SCD_PANEL 7

#define SIDE_PANEL_LIN_LIM 90
#define SIDE_PANEL_COL_LIN 40

#define WIN_MAIN_BORDER 0
#define WIN_MAIN 1
#define WIN_CNTR_BORDER 2
#define WIN_CNTR 3
#define WIN_PLY_BORDER 4
#define WIN_PLY 5
#define WIN_G_CNTR_BORDER 6
#define WIN_G_CNTR 7
#define WIN_G_PLY_BORDER 8
#define WIN_G_PLY 9
#define WIN_D_IMG 10
#define WIN_D_BAN 11
#define WIN_D_STA 12
#define WIN_END_MAIN 13
#define WIN_END_LEFT 14
#define WIN_END_RIGHT 15

#define	WIN_SIZE_COL 261
#define WIN_SIZE_LIN 68

#define G_PHASE_INIT   1
#define G_PHASE_LETS   2
#define G_PHASE_MEM    3
#define G_PHASE_TTD    4
#define G_PHASE_RESHOW 5
#define G_PHASE_END    6

typedef enum	e_operation_codes
{
	OP_live = 1,
	OP_ld,
	OP_st,
	OP_add,
	OP_sub,
	OP_and,
	OP_or,
	OP_xor,
	OP_zjmp,
	OP_ldi,
	OP_sti,
	OP_fork,
	OP_lld,
	OP_lldi,
	OP_lfork,
	OP_aff
}				t_eop;

typedef enum 	e_exit_codes
{
	SUCCESS,
	MALLOC_ERROR,
    FEW_ARGUMENTS,
    INVALID_N,
    TOO_MANY_CHMPS,
    FEW_BYTE,
    READ_ERROR,
    OPEN_ERROR,
    INVALID_EXEC_MAGIC,
    NO_ZERO_BYTE,
    INVALID_SIZE_BYTE_CHAMPION,
    INVALID_FILE_EXTENSION,
    INVALID_ARRAY_CHAMPION,
    INVALID_ARGUMENT_NAME,
    CALL_DUMP
}				t_eexcode;

typedef struct	s_stats
{
	unsigned int	death_wave;
	int				last_death_wave_cycle;
	unsigned int	cars[MAX_PLAYERS + 1];
	unsigned int	dies[MAX_PLAYERS + 1];
	int				cycles_to_die;
	int				cycles_to_die_new;
	int 			cycle;
	int 			total;
	int 			total_die;
	unsigned char 	arena[MEM_SIZE];
	int 	        color[MEM_SIZE];
    unsigned char 	arena_old[MEM_SIZE];
    int         	color_old[MEM_SIZE];
	int				rate;
	char 			game_mod;
	void			(*images[IMG_NUM])(void);
	char 			phase_game;
}				t_stats;

typedef struct	s_register
{
	char 		reg[REG_SIZE];
}				t_reg;

typedef	struct	s_car
{
	t_reg 		regs[REG_NUMBER];
	size_t		id;
	int			live_cycle;
	int 		pos;
	short		byte_next_op;
	short		eval_in;
	char		carry;
	char		op_code;
	char        just_forked;
}				t_car;

typedef struct	s_chmp
{
	size_t 		size;
	char		*name;
	char 		*moto;
	char        *code;
	int			id;
}				t_chmp;

typedef struct	s_mngr
{
	t_list		*timeline[MAX_OP_TIME + 1]; //TODO replace with array of t_list
	t_chmp		*chmps[MAX_PLAYERS];
	t_vector	*cars;  //TODO chose storage structure for carriges
	t_vector	*dead_cars;
	unsigned char 		*arena;
	unsigned	flags; //TODO make flags
	int         dump_nbr;
	int			chmp_num;
	int 		cycle;
	int			live_num;
	int			cycles_to_die;
	int			cycles_delta;
	int			num_checks;
	int 		num_cars;
	int         winner;
	unsigned	next_id;
}				t_mngr;

void			validate_input(t_mngr *mngr, int argc, char **argv);
void			game_main(t_mngr *mngr);

void			safe_exit(t_mngr *mngr, enum e_exit_codes code);
void			init_arena(t_mngr *mngr);
void		    parse_file(char *str, t_mngr *mngr, int nbr);
void			make_one_turn(t_mngr *mngr);
void			proceed_cars(t_mngr *mngr, short cur_time);
/*
** ----------------------Working with timeline------------------------------- **
*/
void tl_put(t_mngr *mngr, short time, t_list_node *lst, int addlast);
void			tl_car_iter(t_mngr *mngr, void (*f)(t_mngr*, t_car*));

/*
** -----------------------------Operations----------------------------------- **
*/

/*
** -----------------------------Statistic------------------------------------ **
*/
void 	add_dies_stats(int reg);
void 	add_cars_stats(int reg);
void	refresh_stats();
t_stats	*get_stats(void);
void	show_time_to_die(t_mngr *mngr);
void	set_cycles_die(int to_set);
void	set_cycles_die_new(int to_set);
void	set_cycle(int to_set);
void	recalc_total();
void	show_nuke(WINDOW *win);
void	show_time_banner();
void	init_visu();
void	show_skull_one(WINDOW *win);
void	show_skull_two();
void	show_skull_three();
void	show_game_init(t_mngr *mngr);
void	show_champ_mem_init(t_mngr *mngr, int start, int size, int color);
void	show_pos_in_arena(t_mngr *mngr, int pos, int color);
void	update_mem(t_mngr *mngr, int id_ply);
void    show_area(t_mngr *mngr);
void	reshow_area(t_mngr *mngr);
void	rate_control(t_stats *st);
void	pause_or_wait_mem_change(t_stats *st);
void	show_scnd_panel(t_mngr *mngr);
void	show_side_panel_init(t_mngr *mngr, int idx_champ);
WINDOW	*get_win(int id);
WINDOW	**get_windows();
int		game_set_param(int from_user);
void	update_side_cntr(void);
void	clear_init_screen();
void	clear_mem_trig_screen();
void	clear_time_to_die_screen();
void	show_side_cntr();
void	game_panel_border();
void	pause_or_wait_reshow(t_stats *st);
void	pause_or_wait_time_to_die();
void	show_winner(t_mngr *mngr);
void	clear_time_end_screen();
void	resizeHandler(int sig);
int		checkSize();
void	set_right_size();
void	clean_all_win();

#endif //COREWAR_COREWAR_H

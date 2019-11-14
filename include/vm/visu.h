/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 16:27:53 by wgorold           #+#    #+#             */
/*   Updated: 2019/11/14 15:26:11 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISU_H
# define VISU_H

# include "corewar.h"
# include <ncurses.h>
# include <stdlib.h>
# include <signal.h>

# define COL_PLY_SHIFT 		1
# define COL_PLY_HIGH_SHIFT 11
# define P1 				1
# define P2 				2
# define P3 				3
# define P4 				4
# define PU 				5
# define DEF 				6
# define BLOOD 				7
# define BRUTAL 			8
# define RIP 				9
# define DOOM 				10
# define P1H 				11
# define P2H 				12
# define P3H 				13
# define P4H 				14
# define PUH 				15

# define G_MOD_PAUSE_ALL 	1
# define G_MOD_PAUSE_SELECT 2
# define G_MOD_NO_PAUSE 	3

# define LIN_STEP 			2
# define COL_IN_LIN 		64

# define WIN_MAIN_BORDER 	0
# define WIN_MAIN 			1
# define WIN_CNTR_BORDER 	2
# define WIN_CNTR 			3
# define WIN_PLY_BORDER 	4
# define WIN_PLY 			5
# define WIN_G_CNTR_BORDER 	6
# define WIN_G_CNTR 		7
# define WIN_G_PLY_BORDER 	8
# define WIN_G_PLY 			9
# define WIN_D_IMG 			10
# define WIN_D_BAN 			11
# define WIN_D_STA 			12
# define WIN_END_MAIN 		13
# define WIN_END_LEFT 		14
# define WIN_END_RIGHT 		15

# define WIN_SIZE_COL 		261
# define WIN_SIZE_LIN 		68

# define G_PHASE_INIT   	1
# define G_PHASE_LETS   	2
# define G_PHASE_MEM   		3
# define G_PHASE_TTD    	4
# define G_PHASE_RESHOW 	5
# define G_PHASE_END    	6

typedef struct		s_stats
{
	unsigned int	death_wave;
	int				last_death_wave_cycle;
	unsigned int	cars[MAX_PLAYERS + 1];
	unsigned int	dies[MAX_PLAYERS + 1];
	int				cycles_to_die;
	int				cycles_to_die_new;
	int				cycle;
	int				total;
	int				total_die;
	unsigned char	arena[MEM_SIZE];
	int				color[MEM_SIZE];
	unsigned char	arena_old[MEM_SIZE];
	int				color_old[MEM_SIZE];
	int				rate;
	char			game_mod;
	char			phase_game;
}					t_stats;

typedef struct		s_nwin
{
	WINDOW			*w;
}					t_nwin;

typedef struct		s_nwin_tab
{
	WINDOW			**ws;
}					t_nwin_tab;

void				add_dies_stats(t_mngr *mngr, int reg);
void				add_cars_stats(t_mngr *mngr, int reg);
void				refresh_stats(t_mngr *mngr);
t_stats				*get_stats(void);
void				show_time_to_die(t_mngr *mngr);
void				set_cycles_die(t_mngr *mngr);
void				set_cycles_die_new(t_mngr *mngr);
void				set_cycle(t_mngr *mngr);
void				recalc_total();
void				show_nuke(WINDOW *win);
void				show_time_banner();
void				init_visu();
void				show_skull_one(WINDOW *win);
void				show_game_init(t_mngr *mngr);
void				show_champ_mem_init(t_mngr *mngr, int start,
					int size, int color);
void				show_pos_in_arena(t_mngr *mngr, int pos, int color);
void				update_mem(t_mngr *mngr, int id_ply);
void				show_area(t_mngr *mngr);
void				reshow_area(t_mngr *mngr);
void				rate_control(t_stats *st);
void				pause_or_wait_mem_change(t_stats *st);
void				show_scnd_panel(t_mngr *mngr);
void				show_side_panel_init(t_mngr *mngr, int idx_champ);
WINDOW				*get_win(int id);
WINDOW				**get_windows();
int					game_set_param(int from_user);
void				update_side_cntr(void);
void				clear_init_screen();
void				clear_mem_trig_screen();
void				clear_time_to_die_screen();
void				show_side_cntr();
void				game_panel_border();
void				pause_or_wait_reshow(t_stats *st);
void				show_winner(t_mngr *mngr);
void				resize_handler(int sig);
int					check_size();
void				set_right_size();
void				clean_all_win();
void				show_champ_let_start(t_mngr *mngr);
void				start_visu(t_mngr *mngr);
void				show_champ_stats(t_mngr *mngr, WINDOW *win);

#endif

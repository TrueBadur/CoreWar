/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkop.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blomo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 20:40:28 by blomo             #+#    #+#             */
/*   Updated: 2019/11/15 15:44:03 by blomo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_CHECKOP_H
# define COREWAR_CHECKOP_H
# define OP_SIZE 1u
# define OP_CODE_SIZE 1u
# define OP_BASE (OP_SIZE + OP_CODE_SIZE)
# define ARG_CODE_SIZE (OP_CODE_SIZE * 8u / MAX_ARGS_NUMBER)
# define ARG1(x) ((x) >> ARG_CODE_SIZE * (MAX_ARGS_NUMBER - 1u) & 3u)
# define ARG2(x) ((x) >> ARG_CODE_SIZE * (MAX_ARGS_NUMBER - 2u) & 3u)
# define ARG3(x) ((x) >> ARG_CODE_SIZE * (MAX_ARGS_NUMBER - 3u) & 3u)

typedef struct		s_t_op
{
	unsigned char	op;
	unsigned char	a1;
	unsigned char	a2;
	unsigned char	a3;
}					t_t_op;

typedef void		(*t_fptr)(t_mngr*, t_car*, t_t_op*);

short				check_op(t_t_op *op);
t_fptr				get_op_func(int id);

void				make_live(t_mngr *mngr, t_car *car, t_t_op *op);
void				make_ld_lld(t_mngr *mngr, t_car *car, t_t_op *op);
void				make_st(t_mngr *mngr, t_car *car, t_t_op *op);
void				make_add_sub(t_mngr *mngr, t_car *car, t_t_op *op);
void				make_and_or_xor(t_mngr *mngr, t_car *car, t_t_op *op);
void				make_zjmp(t_mngr *mngr, t_car *car, t_t_op *op);
void				make_ldi_lldi(t_mngr *mngr, t_car *car, t_t_op *op);
void				make_sti(t_mngr *mngr, t_car *car, t_t_op *op);
void				make_fork_lfork(t_mngr *mngr, t_car *car, t_t_op *op);
void				make_aff(t_mngr *mngr, t_car *car, t_t_op *op);
char				check_reg(int reg);
t_car				*resurect_car(t_mngr *mngr);
void				print_live(t_mngr *mngr, t_car *car, int say, int arg);
void				print_addr(t_mngr *mngr, int pos, int adv);
void				print_st(t_car *car, int reg1, int reg2, t_t_op *op);
void				copy_reg_to_arena(t_mngr *mngr, t_car *car, int reg1,
					int reg2);
void				print_sti(t_car *car, int arg1, int arg2, int arg3);
int					get_args(t_mngr *mngr, t_car *car, t_t_op *op, t_int3 *arg);
int					get_indir(t_mngr *mngr, t_car *car, int *step, int mod);
int					get_reg(t_mngr *mngr, int *step);
int					get_dir(t_mngr *mngr, int *pos, int size);
int					get_addr_arena(int adr);
void				print_and_or_xor(t_int3	*args, int id, t_t_op *op);
void				print_ldi_lldi(t_int3 *args, int id, int pos, t_t_op *op);

#endif

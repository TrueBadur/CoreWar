#ifndef COREWAR_CHECKOP_H
#define COREWAR_CHECKOP_H
#define	OP_SIZE 1u
#define OP_CODE_SIZE 1u
#define OP_BASE (OP_SIZE + OP_CODE_SIZE)
#define	ARG_CODE_SIZE (OP_CODE_SIZE * 8u / MAX_ARGS_NUMBER)
#define	ARG1(x) ((x) >> ARG_CODE_SIZE * (MAX_ARGS_NUMBER - 1u) & 3u)
#define ARG2(x) ((x) >> ARG_CODE_SIZE * (MAX_ARGS_NUMBER - 2u) & 3u)
#define ARG3(x) ((x) >> ARG_CODE_SIZE * (MAX_ARGS_NUMBER - 3u) & 3u)
#define LIVE_VAL (OP_live << sizeof(char) & ARG1(DIR_CODE))
#define LD_VAL (OP_ld << sizeof(char) & ARG1(DIR_CODE) & ARG2(REG_CODE))
#define ST_VAL (OP_st << sizeof(char) & ARG1(REG_CODE) & ARG2(REG_CODE))
#define OP_TEST(val, op) (x & (op) == (op))

typedef struct	s_t_op
{
	unsigned char	op;
	unsigned char	a1;
	unsigned char	a2;
	unsigned char	a3;
}				t_t_op;

typedef void (*fptr)(t_mngr*, t_car*, t_t_op*);

short	check_op(t_t_op *op);
fptr	get_op_func(int id);

void make_live(t_mngr *mngr, t_car *car, t_t_op *op);
void make_ld_lld(t_mngr *mngr, t_car *car, t_t_op *op);
void make_st(t_mngr *mngr, t_car *car, t_t_op *op);
void make_add_sub(t_mngr *mngr, t_car *car, t_t_op *op);
void make_and_or_xor(t_mngr *mngr, t_car *car, t_t_op *op);
void make_zjmp(t_mngr *mngr, t_car *car, t_t_op *op);
void make_ldi_lldi(t_mngr *mngr, t_car *car, t_t_op *op);
void make_sti(t_mngr *mngr, t_car *car, t_t_op *op);
void make_fork_lfork(t_mngr *mngr, t_car *car, t_t_op *op);
void make_aff(t_mngr *mngr, t_car *car, t_t_op *op);
int get_dir(t_mngr *mngr, int poz, int size);
char check_reg(int reg);
int get_indir(t_mngr *mngr, t_car *car, int pos);
int get_reg(t_mngr *mngr,t_car *car, int pos);


#endif //COREWAR_CHECKOP_H


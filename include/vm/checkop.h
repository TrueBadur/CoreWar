#ifndef COREWAR_CHECKOP_H
#define COREWAR_CHECKOP_H
#define	OP_SIZE 1
#define OP_CODE_SIZE 1
#define	ARG_CODE_SIZE (OP_CODE_SIZE * 8 / MAX_ARGS_NUMBER)
#define	ARG1(x) (x >> ARG_CODE_SIZE * (MAX_ARGS_NUMBER - 1) & 3)
#define ARG2(x) (x >> ARG_CODE_SIZE * (MAX_ARGS_NUMBER - 2) & 3)
#define ARG3(x) (x >> ARG_CODE_SIZE * (MAX_ARGS_NUMBER - 3) & 3)
#define LIVE_VAL (OP_live << sizeof(char) & ARG1(DIR_CODE))
#define LD_VAL (OP_ld << sizeof(char) & ARG1(DIR_CODE) & ARG2(REG_CODE))
#define ST_VAL (OP_st << sizeof(char) & ARG1(REG_CODE) & ARG2(REG_CODE))
#define OP_TEST(val, op) (x & op == op)

typedef struct	s_op
{
	unsigned char	op;
	unsigned char	a_code;
}				t_op;

int		is_live(t_op op, short *ret);
int		is_ld(t_op op, short *ret);
int		is_st(t_op op, short *ret);
int		is_add_sub(t_op op, short *ret);
int		is_and_or_xor(t_op op, short *ret);

#endif //COREWAR_CHECKOP_H

NAME = corewar

ASM_OUT = asm
VM_OUT = corewar

SRC_DIR = src
ASM_SRC_DIR = asm
VM_SRC_DIR = vm
VISU_SRC_DIR = visu

SRC_ASM = $(wildcard $(SRC_DIR)/$(ASM_SRC_DIR)/*.c)
SRC_VM = $(wildcard $(SRC_DIR)/$(VM_SRC_DIR)/*.c)
SRC_VISU = $(wildcard $(SRC_DIR)/$(VISU_SRC_DIR)/*.c)
SRC_SHARED = $(wildcard $(SRC_DIR)/*.c)

OBJ_DIR = obj
OBJ_ASM = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC_ASM))
OBJ_VM = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC_VM))
OBJ_VISU = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC_VISU))
OBJ_SHARED = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC_SHARED))
OBJ = $(OBJ_ASM) $(OBJ_VM) $(OBJ_SHARED) $(OBJ_VISU)

INCLUDE_DIR = "include"
ASM_INCLUDE_DIR = $(INCLUDE_DIR)/asm
VM_INCLUDE_DIR = $(INCLUDE_DIR)/vm
SHARED_INCLUDE_DIR = $(INCLUDE_DIR)

LIB_DIR = libft
LIB_PATH = $(LIB_DIR)/lib
LIB_INCLUDE = $(LIB_DIR)/includes

NCURSES = -lncurses

CC_FLAGS = -Wall -Wextra -O3

.PHONY: all $(NAME) clean fclean re

all: $(NAME)

$(OBJ_DIR)/$(ASM_SRC_DIR)/%.o:$(SRC_DIR)/$(ASM_SRC_DIR)/%.c
	@gcc $(CC_FLAGS) -I$(LIB_INCLUDE) -I$(ASM_INCLUDE_DIR) -I$(SHARED_INCLUDE_DIR) -o $@ -c $<

$(OBJ_DIR)/$(VM_SRC_DIR)/%.o:$(SRC_DIR)/$(VM_SRC_DIR)/%.c
	@gcc $(CC_FLAGS) -I$(LIB_INCLUDE) -I$(VM_INCLUDE_DIR) -I$(SHARED_INCLUDE_DIR) -o $@ -c $<

$(OBJ_DIR)/$(VISU_SRC_DIR)/%.o:$(SRC_DIR)/$(VISU_SRC_DIR)/%.c
	@gcc $(CC_FLAGS) -I$(LIB_INCLUDE) -I$(VM_INCLUDE_DIR) -I$(SHARED_INCLUDE_DIR) -o $@ -c $<

$(OBJ_DIR)/%.o:$(SRC_DIR)/%.c
	@gcc $(CC_FLAGS) -I$(LIB_INCLUDE) -I$(SHARED_INCLUDE_DIR) -o $@ -c $<

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)/$(ASM_SRC_DIR) $(OBJ_DIR)/$(VM_SRC_DIR) $(OBJ_DIR)/$(VISU_SRC_DIR)

$(NAME): $(OBJ_DIR) $(OBJ)
	@make -C $(LIB_DIR)
	@gcc $(CC_FLAGS)  -L $(LIB_PATH) -l ft -o $(ASM_OUT) $(OBJ_ASM) $(OBJ_SHARED) -I$(LIBFT_INC_DIR) -I$(SHARED_INCLUDE_DIR) -I$(ASM_INCLUDE_DIR)
	@gcc $(CC_FLAGS)  -L $(LIB_PATH) -l ft $(NCURSES) -o $(VM_OUT) $(OBJ_VM) $(OBJ_VISU) $(OBJ_SHARED) -I$(LIBFT_INC_DIR) -I$(SHARED_INCLUDE_DIR) -I$(VM_INCLUDE_DIR)

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -f $(ASM_OUT) $(VM_OUT)

re: fclean all
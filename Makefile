# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cpollich <cpollich@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/27 23:48:21 by cpollich          #+#    #+#              #
#    Updated: 2020/07/29 15:42:43 by cpollich         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ASM_NAME	=	asm
VM_NAME		=	corewar

ASM_DIR		=	./Assembler
VM_DIR		=	./Virtual\ Machine
TEST_DIR	=	./Tests

VM_SRC_DIR	=	$(VM_DIR)/src
VM_INC_DIR	=	$(VM_DIR)/header
VM_SRC		=	arena.c help_play.c operations.c operations_4.c play.c\
				help_func.c main.c operations_2.c operations_5.c virtual.c\
				help_parse.c op.c operations_3.c parse.c operations_6.c
VM_INC		=	op.h virtual.h
VM_SRCS	= $(addprefix $(VM_SRC_DIR)/,$(VM_SRC))
VM_INCS	= $(addprefix $(VM_INC_DIR)/,$(VM_INC))

ASM_INC_DIR	=	$(ASM_DIR)/inc
ASM_SRC_DIR =	$(ASM_DIR)/src
ASM_SRC		=	asm.c ft_read_until_ch.c get_type.c check_name.c\
				asm_parser.c memory_hero.c memory_op.c\
				letter_check.c check_opname.c parse_inst.c\
				read_arguments.c is_labelinst.c memory_vldop.c\
				args_patterns.c converter.c args_checker.c errors.c\
				translator.c operations.c byte_op.c
ASM_INC		= asm.h op.h
ASM_SRCS	= $(addprefix $(ASM_SRC_DIR)/,$(ASM_SRC))
ASM_INCS	= $(addprefix $(ASM_INC_DIR)/,$(ASM_INC))

all: $(ASM_NAME) $(VM_NAME)

$(ASM_NAME): $(ASM_SRCS) $(ASM_INCS)
	@echo "\033[35mCompiling ./asm\033[0m"
	@make -C $(ASM_DIR) $(ASM_NAME)
	@cp $(ASM_DIR)/$(ASM_NAME) .
	@echo "\033[1;32m./asm was built\033[0m"

$(VM_NAME): $(VM_SRCS) $(VM_INCS)
	@echo "\033[35mCompiling ./corewar\033[0m"
	@make -C $(VM_DIR) $(VM_NAME)
	@cp $(VM_DIR)/$(VM_NAME) .
	@echo "\033[1;32m./corewar was built\033[0m"

clean:
	@make -C $(ASM_DIR) clean
	@make -C $(VM_DIR) clean

fclean: clean
	@make -C $(ASM_DIR) fclean
	@make -C $(VM_DIR) fclean
	@rm -rf $(ASM_NAME) $(VM_NAME)

re: fclean all

norm:
	@make -C $(ASM_DIR) norm
	@make -C $(VM_DIR) norm

.PHONY: all clean fclean re norm

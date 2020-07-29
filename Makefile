# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cpollich <cpollich@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/27 23:48:21 by cpollich          #+#    #+#              #
#    Updated: 2020/07/29 13:48:55 by cpollich         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ASM_NAME	=	asm
VM_NAME		=	corewar

ASM_DIR		=	./Assembler
VM_DIR		=	./Virtual\ Machine

# VM_SRC_DIR	=	$(VM_DIR)/src
# VM_INC_DIR	=	$(VM_DIR)/header
# VM_OBJ_DIR	=	$(VM_DIR)/obj

# ASM_SRC_DIR	=	$(ASM_DIR)/src
# ASM_INC_DIR	=	$(ASM_DIR)/inc
# ASM_OBJ_DIR	=	$(ASM_DIR)/obj

all: $(ASM_NAME) $(VM_NAME)

$(ASM_NAME):
	@echo "\033[35mCompiling ./asm\033[0m"
	@make -C $(ASM_DIR) $(ASM_NAME)
	@cp $(ASM_DIR)/$(ASM_NAME) .
	@echo "\033[1;32m./asm was built\033[0m"

$(VM_NAME):
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

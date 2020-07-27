# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cpollich <cpollich@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/27 23:48:21 by cpollich          #+#    #+#              #
#    Updated: 2020/07/28 00:07:47 by cpollich         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ASM_NAME	=	asm
VM_NAME		=	corewar

ASM_DIR		=	./Assembler
VM_DIR		=	./Virtual\ Machine

all: $(ASM_NAME) $(VM_NAME)

$(ASM_NAME):
	@echo "\033[35mCompiling ./asm\033[0m"
	@make -C $(ASM_DIR)
	@scp $(ASM_DIR)/$(ASM_NAME) .
	@echo "\033[1;32m./asm was built\033[0m"

$(VM_NAME):
	@echo "\033[35mCompiling ./corewar\033[0m"
	@make -C $(VM_DIR)
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

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cpollich <cpollich@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/08 16:28:00 by cpollich          #+#    #+#              #
#    Updated: 2020/07/19 18:12:00 by cpollich         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

F				=	-Wall -Wextra -Werror
LIBFT_DIR		=	../libft
LIBFT_INC_DIR	=	$(LIBFT_DIR)/inc
INC_DIR			=	./inc
OP_INC_DIR		=	../inc
SRC_DIR			=	./src
OBJ_DIR			=	./obj

SRC				=	asm.c ft_read_until_ch.c get_type.c check_name.c\
					asm_parser.c fill_hero.c memory_hero.c memory_op.c\
					letter_check.c check_opname.c parse_inst.c\
					read_arguments.c is_labelinst.c memory_vldop.c\
					args_patterns.c
SRCS			=	$(addprefix $(SRC_DIR)/,$(SRC))

LIBFT			=	$(LIBFT_DIR)/libft.a

test: $(SRCS)
	gcc -g $(SRCS) -I$(INC_DIR) -I$(LIBFT_INC_DIR) -I$(OP_INC_DIR) $(LIBFT) -o test

fclean:
	rm -Rf test*

re: fclean test
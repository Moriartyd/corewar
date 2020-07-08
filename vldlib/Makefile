# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cpollich <cpollich@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/08 16:28:00 by cpollich          #+#    #+#              #
#    Updated: 2020/07/08 18:11:49 by cpollich         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

F				=	-Wall -Wextra -Werror
LIBFT_DIR		=	../libft
LIBFT_INC_DIR	=	$(LIBFT_DIR)/inc
INC_DIR			=	./inc
OP_INC_DIR		=	../inc
SRC_DIR			=	./src
OBJ_DIR			=	./obj

SRC				=	asm.c ft_read_until_ch.c
SRCS			=	$(addprefix $(SRC_DIR)/,$(SRC))

LIBFT			=	$(LIBFT_DIR)/libft.a

test: $(SRCS)
	gcc -g $F $(SRCS) -I$(INC_DIR) -I$(LIBFT_INC_DIR) -I$(OP_INC_DIR) $(LIBFT) -o test

fclean:
	rm -Rf test*

re: fclean test
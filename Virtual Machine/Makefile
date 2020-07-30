# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mriley <mriley@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/27 22:25:37 by cpollich          #+#    #+#              #
#    Updated: 2020/07/30 20:29:38 by mriley           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	corewar
F			=	-Wall -Wextra -Werror -g
LFT_DIR		=	./libft
PFT_DIR		=	./ft_printf
SRC_DIR		= 	./src
OBJ_DIR		= 	./obj
INC_DIR		=	./header

INC			= op.h virtual.h

LFT_INC	= ./libft/inc
PFT_INC	= ./ft_printf/inc

PFT	=	$(PFT_DIR)/libftprintf.a
LFT	=	$(LFT_DIR)/libft.a

SRC = arena.c help_play.c operations.c operations_4.c play.c\
		help_func.c main.c operations_2.c operations_5.c virtual.c\
		help_parse.c op.c operations_3.c parse.c operations_6.c

OBJ	= $(addprefix $(OBJ_DIR)/,$(SRC:%.c=%.o))
INCS = $(addprefix $(INC_DIR)/,$(INC))

all: $(NAME)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INCS)
	@gcc $F -c $< -I$(INC_DIR) -I$(LFT_INC) -I$(PFT_INC) -o $@

$(NAME): $(LFT) $(PFT) $(OBJ_DIR) $(OBJ) $(INCS)
	@gcc $F -I$(INC_DIR)  -I$(LFT_INC) -I$(PFT_INC)\
		-L $(LFT_DIR)/ -lft -L $(PFT_DIR)/ -lftprintf\
		$(OBJ) -o $(NAME)

$(PFT):
	@make -C $(PFT_DIR)
$(LFT):
	@make -C $(LFT_DIR)

clean:
	@make -C $(LFT_DIR) clean
	@make -C $(PFT_DIR) clean
	@/bin/rm -rf $(OBJ_DIR)

fclean: clean
	@make -C $(LFT_DIR) fclean
	@make -C $(PFT_DIR) fclean
	@/bin/rm -f $(NAME)

re: fclean all

norm:
	@norminette $(SRC_DIR) $(INC_DIR)
	@make -C $(PFT_DIR) norm
	@make -C $(LFT_DIR) norm

.PHONY: all clean fclean re norm

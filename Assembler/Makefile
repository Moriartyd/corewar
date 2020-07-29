# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cpollich <cpollich@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/08 16:28:00 by cpollich          #+#    #+#              #
#    Updated: 2020/07/29 15:16:59 by cpollich         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

F				=	-Wall -Wextra -Werror
NAME			=	asm
LIBFT_DIR		=	libft
LIBFT_INC_DIR	=	$(LIBFT_DIR)/inc
INC_DIR			=	./inc
SRC_DIR			=	./src
OBJ_DIR			=	./obj
INC_ASM			=	$(INC_DIR)/asm.h $(INC_DIR)/op.h

SRC				=	asm.c ft_read_until_ch.c get_type.c check_name.c\
					asm_parser.c memory_hero.c memory_op.c\
					letter_check.c check_opname.c parse_inst.c\
					read_arguments.c is_labelinst.c memory_vldop.c\
					args_patterns.c converter.c args_checker.c errors.c\
					translator.c operations.c byte_op.c

OBJS			=	$(addprefix $(OBJ_DIR)/,$(SRC:%.c=%.o))

LIBFT			=	$(LIBFT_DIR)/libft.a

all: $(NAME)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INC_ASM)
		@gcc $(F) -c $< -I$(INC_DIR) -I$(LIBFT_INC_DIR) -o $@

$(NAME): $(LIBFT) $(OBJ_DIR) $(OBJS) $(INC_ASM)
		@gcc $F -I $(LIBFT_INC_DIR) -I $(INC_DIR) -L $(LIBFT_DIR)/ -lft\
			-o $(NAME) $(OBJS)

$(LIBFT):
	@make -C libft

clean:
	@make -C libft clean
	@rm -Rf $(OBJ_DIR)

fclean: clean
	@make -C libft fclean
	@rm -f $(NAME)

norm:
	@norminette $(SRC_DIR) $(INC_DIR)
	@make -C $(LIBFT_DIR) norm

re: fclean all

.PHONY: all clean fclean re norm

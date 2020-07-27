# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cpollich <cpollich@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/02 18:27:40 by smanhack          #+#    #+#              #
#    Updated: 2020/07/28 00:06:10 by cpollich         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a

INC_DIR		= ./inc
SRC_DIR		= ./src
OBJ_DIR		= ./obj

LIBFT_LIB = $(LIBFT)/libft.a
LIBFT_H = $(LIBFT)

SRC	= f_cps.c ft_atoi.c ft_bzero.c ft_diouxx_up.c ft_isdigit.c ft_itoa.c ft_itoa_base_ull.c ft_itoa_ll.c ft_number_of_digits.c ft_printf.c ft_putchar.c ft_putstr.c ft_second.c ft_strchr.c ft_strcpy.c ft_strlen.c ft_strncpy.c ft_strnew.c ft_toupper.c ft_third.c doublf.c ldoublf.c ft_strjoin.c ft_memcpy.c ft_putnbr_endl.c ft_putnbr.c doublf_part_2.c doublf_part_3.c doublf_part_4.c \
doublf_part_5.c ldoublf_part_2.c ldoublf_part_3.c ldoublf_part_4.c ldoublf_part_5.c ldoublf_part_6.c ft_fourth.c ldoublf_part_7.c ft_itoa_base_uintmax_t.c ft_itoa_intmax_t.c ft_itoa_base_size_t.c ft_itoa_ssize_t.c ft_strstr.c ft_putendl.c ft_rainbow.c ft_strsub.c ft_strdup.c ft_strcmp.c bonus_part.c doublf2.c

OBJS	=	$(addprefix $(OBJ_DIR)/,$(SRC:%.c=%.o))
SRCS	=	$(addprefix $(SRC_DIR)/,$(SRC))

H = $(INC_DIR)/ft_printf.h $(INC_DIR)/libft.h $(INC_DIR)/ft_rainbow.h

FLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME): $(OBJ_DIR) $(OBJS) $(H)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o:$(SRC_DIR)/%.c
	@gcc $F -c $< -I$(INC_DIR) -o $@

clean:
	@rm -Rf $(OBJ_DIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all

norm:
	@norminette $(SRC_DIR) $(INC_DIR)

.PHONY: all clean fclean re norm
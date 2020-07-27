# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cpollich <cpollich@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/01 14:33:12 by cpollich          #+#    #+#              #
#    Updated: 2020/07/28 00:06:04 by cpollich         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

INC_DIR		= ./inc
SRC_DIR		= ./src
OBJ_DIR		= ./obj

HEAD		= $(INC_DIR)/libft.h

SRC		=	ft_memset.c ft_bzero.c					\
			ft_memcpy.c	ft_memccpy.c				\
			ft_memmove.c ft_memchr.c				\
			ft_memcmp.c	ft_strcmp.c 				\
			ft_strncmp.c ft_strcpy.c				\
			ft_strncpy.c ft_strlen.c				\
			ft_strdup.c	ft_strstr.c 				\
			ft_strnstr.c ft_atoi.c					\
			ft_strcat.c ft_strncat.c				\
			ft_strlcat.c ft_strchr.c				\
			ft_strrchr.c ft_isalpha.c				\
			ft_isdigit.c ft_isalnum.c				\
			ft_iswhitespace.c ft_isascii.c			\
			ft_isprint.c ft_toupper.c				\
			ft_tolower.c ft_putchar.c				\
			ft_putchar_fd.c ft_putstr.c				\
			ft_putstr_fd.c ft_putendl.c				\
			ft_putendl_fd.c ft_putnbr.c				\
			ft_putnbr_fd.c ft_itoa.c 				\
			ft_strclr.c ft_memalloc.c				\
			ft_memdel.c ft_striter.c 				\
			ft_strnew.c ft_strdel.c					\
			ft_strequ.c ft_strnequ.c				\
			ft_strmap.c ft_strmapi.c				\
			ft_strsub.c ft_strjoin.c				\
			ft_strtrim.c ft_strsplit.c				\
			ft_striteri.c ft_strtrimchr.c 			\
			ft_lstnew.c	ft_lstdelone.c				\
			ft_lstdel.c	ft_lstadd.c					\
			ft_lstiter.c ft_lstmap.c				\
			ft_realloc.c ft_lstsize.c				\
			ft_intpower.c ft_abs.c					\
			ft_strchr_safe.c ft_strdup_safe.c		\
			ft_strshift.c get_next_line.c			\
			ft_wordcount.c ft_lstclr.c				\
			ft_copyuntil.c ft_doublestrdel.c		\
			ft_swap.c ft_strnchr.c ft_isnumeric.c	\
			ft_strjoinch.c ft_doublematrixdel.c		\
			ft_stradd.c ft_chjoinstr.c				\
			ft_itoa_base.c ft_itoa_ubase.c 			\
			ft_nchjoinstr.c ft_putstr_until.c		\
			ft_strjoin_leak.c ft_ltoa_base.c		\
			ft_str_white_trim.c ft_countch.c		\
			ft_strnewncp.c ft_strjoinchar.c

OBJS	=	$(addprefix $(OBJ_DIR)/,$(SRC:%.c=%.o))

F = -Wall -Wextra -Werror

all: $(NAME)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(NAME): $(OBJ_DIR) $(OBJS) $(HEAD)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@gcc $F -c $< -I$(INC_DIR) -o$@

clean:
	@rm -Rf $(OBJ_DIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all

norm:
	@norminette $(SRC_DIR) $(INC_DIR)

.PHONY: all clean fclean re norm

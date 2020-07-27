# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cpollich <cpollich@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/12 17:36:44 by mriley            #+#    #+#              #
#    Updated: 2020/07/28 00:05:22 by cpollich         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = libft.a

SRC_DIR		= ./src
OBJ_DIR		= ./obj
INC_DIR		= ./inc
HEAD		= $(INC_DIR)/libft.h

CC = gcc -Wall -Wextra -Werror

SRC =	ft_atoi.c       ft_lstmap.c     ft_putendl.c    ft_strdup.c     ft_strnequ.c\
		ft_bzero.c      ft_lstnew.c     ft_putendl_fd.c ft_strequ.c     ft_strnew.c\
		ft_isalnum.c    ft_memalloc.c   ft_putnbr.c     ft_striter.c    ft_strnstr.c\
		ft_isalpha.c    ft_memccpy.c    ft_putnbr_fd.c  ft_striteri.c   ft_strrchr.c\
		ft_isascii.c    ft_memchr.c     ft_putstr.c     ft_strjoin.c    ft_strsplit.c\
		ft_isdigit.c    ft_memcmp.c     ft_putstr_fd.c  ft_strlcat.c    ft_strstr.c\
		ft_isprint.c    ft_memcpy.c     ft_strcat.c     ft_strlen.c     ft_strsub.c\
		ft_itoa.c       ft_memdel.c     ft_strchr.c     ft_strmap.c     ft_strtrim.c\
		ft_lstadd.c     ft_memmove.c    ft_strclr.c     ft_strmapi.c    ft_tolower.c\
		ft_lstdel.c     ft_memset.c     ft_strcmp.c     ft_strncat.c    ft_toupper.c\
		ft_lstdelone.c  ft_putchar.c    ft_strcpy.c     ft_strncmp.c    get_next_line.c\
		ft_lstiter.c    ft_putchar_fd.c ft_strdel.c     ft_strncpy.c

OBJ = $(SRC:%.c=%.o)
OBJS	=	$(addprefix $(OBJ_DIR)/,$(SRC:%.c=%.o))

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

re:		fclean all

norm:
	@norminette $(SRC_DIR) $(INC_DIR)

.PHONY: all clean fclean re norm

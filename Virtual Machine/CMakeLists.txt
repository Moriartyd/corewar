cmake_minimum_required(VERSION 3.16)
project(Virtual_Machine C)

set(CMAKE_C_STANDARD 11)

include_directories(ft_printf/inc)
include_directories(header)
include_directories(libft/inc)

add_executable(Virtual_Machine
        ft_printf/inc/ft_printf.h
        ft_printf/inc/ft_rainbow.h
        ft_printf/inc/libft.h
        ft_printf/src/bonus_part.c
        ft_printf/src/doublf.c
        ft_printf/src/doublf2.c
        ft_printf/src/doublf_part_2.c
        ft_printf/src/doublf_part_3.c
        ft_printf/src/doublf_part_4.c
        ft_printf/src/doublf_part_5.c
        ft_printf/src/f_cps.c
        ft_printf/src/ft_atoi.c
        ft_printf/src/ft_bzero.c
        ft_printf/src/ft_diouxx_up.c
        ft_printf/src/ft_fourth.c
        ft_printf/src/ft_isdigit.c
        ft_printf/src/ft_itoa.c
        ft_printf/src/ft_itoa_base_size_t.c
        ft_printf/src/ft_itoa_base_uintmax_t.c
        ft_printf/src/ft_itoa_base_ull.c
        ft_printf/src/ft_itoa_intmax_t.c
        ft_printf/src/ft_itoa_ll.c
        ft_printf/src/ft_itoa_ssize_t.c
        ft_printf/src/ft_memcpy.c
        ft_printf/src/ft_number_of_digits.c
        ft_printf/src/ft_printf.c
        ft_printf/src/ft_putchar.c
        ft_printf/src/ft_putendl.c
        ft_printf/src/ft_putnbr.c
        ft_printf/src/ft_putnbr_endl.c
        ft_printf/src/ft_putstr.c
        ft_printf/src/ft_rainbow.c
        ft_printf/src/ft_second.c
        ft_printf/src/ft_strchr.c
        ft_printf/src/ft_strcmp.c
        ft_printf/src/ft_strcpy.c
        ft_printf/src/ft_strdup.c
        ft_printf/src/ft_strjoin.c
        ft_printf/src/ft_strlen.c
        ft_printf/src/ft_strncpy.c
        ft_printf/src/ft_strnew.c
        ft_printf/src/ft_strstr.c
        ft_printf/src/ft_strsub.c
        ft_printf/src/ft_third.c
        ft_printf/src/ft_toupper.c
        ft_printf/src/ldoublf.c
        ft_printf/src/ldoublf_part_2.c
        ft_printf/src/ldoublf_part_3.c
        ft_printf/src/ldoublf_part_4.c
        ft_printf/src/ldoublf_part_5.c
        ft_printf/src/ldoublf_part_6.c
        ft_printf/src/ldoublf_part_7.c
        header/op.h
        header/virtual.h
      #  libft/inc/get_next_line.h
        libft/inc/libft.h
#        libft/src/ft_atoi.c
#        libft/src/ft_bzero.c
#        libft/src/ft_isalnum.c
#        libft/src/ft_isalpha.c
#        libft/src/ft_isascii.c
#        libft/src/ft_isdigit.c
#        libft/src/ft_isprint.c
#        libft/src/ft_itoa.c
#        libft/src/ft_lstadd.c
#        libft/src/ft_lstdel.c
#        libft/src/ft_lstdelone.c
#        libft/src/ft_lstiter.c
#        libft/src/ft_lstmap.c
#        libft/src/ft_lstnew.c
#        libft/src/ft_memalloc.c
#        libft/src/ft_memccpy.c
#        libft/src/ft_memchr.c
#        libft/src/ft_memcmp.c
#        libft/src/ft_memcpy.c
#        libft/src/ft_memdel.c
#        libft/src/ft_memmove.c
#        libft/src/ft_memset.c
#        libft/src/ft_putchar.c
#        libft/src/ft_putchar_fd.c
#        libft/src/ft_putendl.c
#        libft/src/ft_putendl_fd.c
#        libft/src/ft_putnbr.c
#        libft/src/ft_putnbr_fd.c
#        libft/src/ft_putstr.c
#        libft/src/ft_putstr_fd.c
#        libft/src/ft_strcat.c
#        libft/src/ft_strchr.c
#        libft/src/ft_strclr.c
#        libft/src/ft_strcmp.c
#        libft/src/ft_strcpy.c
#        libft/src/ft_strdel.c
#        libft/src/ft_strdup.c
#        libft/src/ft_strequ.c
#        libft/src/ft_striter.c
#        libft/src/ft_striteri.c
#        libft/src/ft_strjoin.c
#        libft/src/ft_strlcat.c
#        libft/src/ft_strlen.c
#        libft/src/ft_strmap.c
#        libft/src/ft_strmapi.c
#        libft/src/ft_strncat.c
#        libft/src/ft_strncmp.c
#        libft/src/ft_strncpy.c
#        libft/src/ft_strnequ.c
#        libft/src/ft_strnew.c
#        libft/src/ft_strnstr.c
#        libft/src/ft_strrchr.c
#        libft/src/ft_strsplit.c
#        libft/src/ft_strstr.c
#        libft/src/ft_strsub.c
#        libft/src/ft_strtrim.c
#        libft/src/ft_tolower.c
#        libft/src/ft_toupper.c
    #    libft/src/get_next_line.c
        src/arena.c
        src/help_func.c
        src/help_parse.c
        src/help_play.c
        src/main.c
        src/op.c
        src/operations.c
        src/operations_2.c
        src/operations_3.c
        src/operations_4.c
        src/operations_5.c
        src/parse.c
        src/play.c
        src/virtual.c)

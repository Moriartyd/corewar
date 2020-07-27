/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smanhack <smanhack@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 15:20:40 by smanhack          #+#    #+#             */
/*   Updated: 2019/08/02 18:52:44 by smanhack         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>

void				ft_bzero(void *s, size_t n);
void				ft_putchar(char c);
void				ft_putstr(char const *s);
size_t				ft_strlen(const char *s);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strchr(const char *s, int c);
char				*ft_strncpy(char *dst, const char *src, size_t len);
char				*ft_itoa(int n);
char				*ft_strnew(size_t size);
int					ft_isdigit(int c);
int					ft_toupper(int c);
int					ft_number_of_digits(int n);
char				*ft_itoa_base_ull(unsigned long long value, int base);
char				*ft_itoa_ll(long long n);
int					ft_atoi(const char *str);
char				*ft_strjoin(char const *s1, char const *s2);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				ft_putnbr(int n);
void				ft_putnbr_endl(int n);
char				*ft_itoa_base_uintmax_t(uintmax_t value, int base);
char				*ft_itoa_intmax_t(intmax_t n);
char				*ft_itoa_base_size_t(size_t value, int base);
char				*ft_itoa_ssize_t(ssize_t n);
char				*ft_strstr(const char *haystack, const char *needle);
void				ft_putendl(char const *s);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strdup(const char *src);
int					ft_strcmp(const char *s1, const char *s2);

#endif

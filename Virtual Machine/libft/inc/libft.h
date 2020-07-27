/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriley <mriley@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 18:54:08 by mriley            #+#    #+#             */
/*   Updated: 2020/02/04 17:19:25 by mriley           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include "get_next_line.h"

typedef	struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdelone(t_list **alst, void (*del)(void*, size_t));
void				ft_lstadd(t_list **alst, t_list *ne);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_bzero(void *s, size_t n);
void				ft_memdel(void **ap);
void				*ft_memchr (const void *arr, int c, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memmove (void *d, const void *s, size_t n);
void				*ft_memalloc(size_t size);
void				*ft_memccpy (void *d, const void *s, int c, size_t n);
void				*ft_memset(void *memptr, int val, size_t num);
char				*ft_strdup (const char *src);
char				*ft_strcpy(char *destptr, const char *srcptr);
size_t				ft_strlen(const char *str);
char				*ft_strcat(char *destptr, const char *srcptr);
char				*ft_strncat(char *destptr, char *srcptr, size_t num);
char				*ft_strncpy(char *destptr, char *srcptr, size_t num);
size_t				ft_strlcat (char *dst, const char *src, size_t size);
char				*ft_strrchr(const char *string, int symbol);
char				*ft_strchr(const char *string, int symbol);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
char				*ft_strstr(const char *s1, const char *s2);
char				*ft_strnstr(const char *s1, const char *s2, size_t length);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strdup (const char *src);
int					ft_strequ(char const *s1, char const *s2);
int					ft_isalpha(int character);
int					ft_isdigit(int character);
int					ft_isalnum(int character);
int					ft_isprint(int ch);
int					ft_isascii(int ch);
int					ft_isprint(int ch);
int					ft_toupper(int character);
int					ft_tolower (int c);
void				ft_memdel(void **ap);
int					ft_strequ(char const *s1, char const *s2);
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strnew(size_t size);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
void				ft_strdel(char **as);
void				ft_strclr(char *s);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strnequ(char const *s1, char const *s2, size_t n);
void				ft_putchar_fd(char c, int fd);
void				ft_putchar(char c);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putstr(char const *s);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putendl(char const *s);
void				ft_putnbr_fd(int n, int fd);
void				ft_putnbr(int n);
int					ft_memcmp(const void *m1, const void *m2, size_t num);
char				*ft_itoa(int n);
int					ft_atoi(const char *str);

#endif

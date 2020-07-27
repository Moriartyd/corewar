/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollich <cpollich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/18 18:03:23 by smanhack          #+#    #+#             */
/*   Updated: 2020/07/27 23:45:53 by cpollich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft.h"

# define K_S1 "0111111111110000000000000000000000000000000000000000000000000000"
# define K_S2 "1111111111110000000000000000000000000000000000000000000000000000"
# define K_S3 "0111111111110000000000000000000000000000000000000000000000000001"
# define K_S4 "0111111111111000000000000000000000000000000000000000000000000001"
# define K_S5 "0111111111111111111111111111111111111111111111111111111111111111"
# define K_S6 "0111111111111000000000000000000000000000000000000000000000000000"

typedef struct		s_format
{
	char			sym;
	char			flags;
	int				type;
	int				width;
	int				prec;
}					t_format;

typedef struct		s_conv
{
	char			conv;
	char			*(*f)(va_list ap, t_format);
}					t_conv;

typedef struct		s_count
{
	int				i;
	int				j;
}					t_count;

typedef struct		s_point
{
	char			*s;
	char			*zifra;
	char			*znak;
	char			*exp;
	char			*mantissa;
	int				*g;
	int				*posle;
	char			*toc;
}					t_point;

char				*f_c(va_list ap, t_format f);
char				*f_s(va_list ap, t_format f);
char				*f_p(va_list ap, t_format f);
char				*ft_di(va_list ap, t_format f);
char				*ft_o(va_list ap, t_format f);
char				*ft_u(va_list ap, t_format f);
char				*ft_x(va_list ap, t_format f);
char				*ft_x_up(va_list ap, t_format f);
int					ft_ox(t_format f, char *buff);
int					ft_fix(t_format *f, char c, const char *frmt, int j);
char				*ft_correct(char *buff, t_format *f, char c);
char				*ft_percent(va_list ap, t_format f);
void				ft_print_part_2(t_format *f, int *count, char *buff);
void				ft_print_part_3(t_format *f, int *count, char *buff);
int					ft_write(char *str);
void				ft_putprint(char *buff, char c);
char				*toretryd(va_list ap, t_format f);
int					*ft_rowhelp2(int *h, int *f, int k);
char				*toretry(va_list ap, t_format f);
char				*ft_delaem(int *g, char *znak, char *mantissa);
void				ft_format_part_2(t_format *f, const char *frmt, int *i);
int					*dlinayadrob(char *mantissa, t_format ff);
char				*delaem1(int *g, t_format ff,\
						char *mantissa, long double n);
char				*tocotrub(char *toc);
char				*ft_peredelzel(char *zifra, int j);
char				*todestoc(long double n, t_format f);
char				*ft_okruglyaem(char *h, long double n);
char				*ft_bitstrd(unsigned char *c, int var_size);
char				*ft_putbitd(void *ptr, size_t var_size);
unsigned long long	ft_rowd(int i, double g);
long long			chekbitd(long long n, int i);
long long			izdestodvad(char *s);
char				*ft_znakd(char *s);
char				*ft_expd(char *s);
char				*mantisdvig1(char *s, long long n);
char				*mantisdvig2(char *s, long long n);
char				*mantisdvig3(char *s, long long n);
char				*mantisdvig4(char *s, long long n);
char				*dvigaemd(long long n, char *s);
char				*ft_mantissad(char *s);
int					*ft_rowhelp1(int i, int *f, int k);
char				*todestocd(double n, t_format fа);
int					*ft_rowkuld(int i, int *h, int k);
int					*izdvatodesd(char *d);
char				*okruglyaem(char *h, double n);
int					*todesd(char *s);
char				*izdvatodestocd(double n, t_format f);
int					*ft_five(long long i, int *f, t_format ff, int l);
char				*ft_znak(char *s);
char				*ft_exp(char *s);
char				*ft_mantissa(char *s);
char				*ft_putbit(void *ptr, size_t var_size);
long long			izdestodva(char *s);
char				*dvigaem(long long n, char *s);
int					*todes(char *s);
char				*mantisdvig12(char *s, long long n);
char				*mantisdvig22(char *s, long long n);
char				*mantisdvig32(char *s, long long n);
int					*izdvatodes(char *d);
char				*ft_delaem_part_2(int *g, int *j, char **zifra);
char				*ft_peredel(char *zifra, int j);
void				ft_precision(t_format *f, const char *frmt,
					int *i, va_list ap);
t_format			ft_format(const char *frmt, int j, char sym, va_list ap);
void				toretry_part_2(t_point *p);
void				ft_zero(int *j);
void				ft_five_bonus(int *t, int *l, long long i);
int					*ft_five(long long i, int *f, t_format ff, int l);
int					*sumfive(int *f, int *g, t_format ff);
int					ft_printf(const char *frmt, ...);
char				*ft_u_up(va_list ap, t_format f);
char				*ft_b(va_list ap, t_format f);
char				*ft_rainbow(va_list ap, t_format f);
int					ft_print(char *buff, t_format f);
void				ft_toretry_bbonus(t_point *p, t_format *ff, char **d);
void				ft_toretryd_bonus(t_point *p, char **stroka, t_format *ff);
int					proverka(char *posle, char *zeloe);
void				ft_free(t_point p);
void				izdvatodestocd_norm(double *n, double *g);

#endif

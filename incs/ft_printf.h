/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasstou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 10:10:43 by mmasstou          #+#    #+#             */
/*   Updated: 2021/12/11 03:27:27 by mmasstou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_rep
{
	int	plus;
	int	perc;
	int	space;
	int	shrap;
	int	zero;
	int	dash;
	int	pnt;
	int	flags;
	int	width;
	int	lenwidth;
	int	precision;
	int	lenprecision;
}	t_rep;

typedef struct s_printf
{
	va_list	args;
	t_rep	*_rep;
	int		tl;
	int		plus;
	int		perc;
	int		space;
	int		shrap;
	int		zero;
	int		dash;
	int		pnt;
	int		is_flag;
	int		width;
	int		precision;
}	t_printf;

// libft
int			ft_atoi(const char *str);
int			ft_isdigit( int d);
int			ft_isspace(int s);
int			ft_putstr(char *str);
int			ft_putchar(int c);
int			ft_putnbr(long long n);
int			ft_Unbrlen(unsigned n);
int			ft_puthex(unsigned int num, int specifier);
int			ft_strlen(const char *str);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strdup(const char *s);
// srcs
int			ft_printf(const char *format, ...);
t_printf	*ft_initialise_tab(t_printf *tab);
t_printf	*ft_resize_flags(t_printf *tab);
int			is_integer_specifier(int c);
int			is_specifier(int c);
int			ft_eval_format(t_printf *tab, const char *format, int index);
void		ft_specifier(t_printf *tab, const char *format, int index);
void		ft_print_char(t_printf *tab);
void		ft_print_str(t_printf *tab, char *str);
void		ft_print_adress(t_printf *tab);
int			ft_putunsigned(unsigned int nbr);
int			ft_p_adress(unsigned long p);
void		ft_print_unsigned(t_printf *tab);
void		flags_check(t_printf *tab, const char *format, int index);
int			ft_putpercent(void);
int			update_index(t_printf *tab, int index);
int			ft_nbrlen(int n);
int			ft_hex_len(unsigned	int num);
// flags
void		space_flag(t_printf *tab, int spicefier);
void		plus_flag(t_printf *tab, int spicefier);
void		shrap_flag(t_printf *tab, int spicefier);
int			dash_flag(t_printf *tab, const char *format, int index, char *str);
int			point_flag(t_printf *tab, const char *format, int index, char *str);
int			ft_get_precision(const char *format, int index);
int			ft_zero_flag(t_printf *tab);
void		ft_dash_pnt(t_printf *tab);
void		no_dash_pnt(t_printf *tab);
// specifier
int			string_specifier(t_printf *tab);
int			hex_specifer(t_printf *tab, const char *format, int index);
int			p_flag(t_printf *tab);
int			d_zero_pnt(t_printf *tab);
int			u_flags(t_printf *tab);
// ** unsigned spicefier utils 
int			zero_pnt_precision_no_dashpw(t_printf *tab, unsigned int nbr,int len);
int			precision_no_width(t_printf *tab, unsigned int nbr, int len);
int			no_precision_a_w_a_no_w(t_printf *tab, unsigned int nbr, int len);
int			no_dash_precision_width(t_printf *tab, unsigned int nbr, int len);
int 		dash_precision(t_printf *tab, unsigned int nbr, int len);
int			hex_pre(t_printf *tab, const char *format, int index, unsigned int u);
int 		hex_dash_pnt(t_printf *t, const char *f, int x, unsigned int u);
int			zf_pnt_pre_p_l_w(t_printf *tab, int nbr, int len);
// int			p_flag(t_printf *tab, const char *format, int index);

#endif

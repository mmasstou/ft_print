#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>


typedef struct s_rep
{
      int   plus; // +
      int   perc; // %
      int   space;
	  int	shrap; // #
}    t_rep;

typedef struct s_printf
{
      va_list  args;    // arg to print out
	  t_rep	*_rep;		// test repetation
	  int   tl;        // total_length (return value)
	  int   plus; // +
      int   perc; // %
      int   space;
	  int	shrap; // #
	  int	is_flag; // #
}    t_printf;

// libft
int			ft_atoi(const char *str);
int			ft_isdigit( int d);
int			ft_isspace(int s);
int			ft_putstr(char *str);
// srcs
int			ft_printf(const char *format, ...);
t_printf	*ft_initialise_tab(t_printf *tab); 
int			is_specifier(int c);
int 		ft_eval_format(t_printf *tab,const char *format, int index);
void		ft_specifier(t_printf *tab,const char *format, int index);
void		ft_print_char(t_printf *tab);
void		ft_print_str(t_printf *tab);


#endif

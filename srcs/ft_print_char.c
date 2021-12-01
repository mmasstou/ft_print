#include "../incs/ft_printf.h"


void	ft_print_char(t_printf *tab)                       
{                        
    char a;   
             
    a = va_arg(tab->args, int);  //variadic function
	tab->tl += write(1, &a, 1);  //print char
}

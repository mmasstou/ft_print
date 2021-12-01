#include "../incs/ft_printf.h"

t_printf *ft_initialise_tab(t_printf *tab)                       
{  
	tab->tl = 0;       // total_length (return value)
	tab->plus = 0; // +
	tab->_rep->plus = 0; // +
	tab->perc = 0; // %
	tab->_rep->perc = 0; // %
	tab->space = 0;
	tab->_rep->space = 0;
	tab->shrap = 0; // #
	tab->_rep->shrap = 0; // #
	tab->is_flag = 0;
	return (tab);                       
}
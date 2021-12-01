#include "../incs/ft_printf.h"

// static	void	flag_part2(t_printf *tab, const char *format, int index)
// {
// 		if (format[index] == '+')
//         {
// 			tab->plus = 1;
// 			tab->_rep->plus++;
// 			index++;
// 		}
        
//         if (format[index] == ' ')
//         {
// 			tab->space = 1;
// 			tab->_rep->space++;
// 			index++;
// 		}
//         if (format[index] == '#')
//         {
// 			tab->shrap = 1;
// 			tab->_rep->shrap++;
// 			index++;
// 		}
// 		if (format[index] == '-')
//         {
// 			tab->dash = 1;
// 			tab->_rep->dash++;
// 			index++;
// 		}
// }

int ft_eval_format(t_printf *tab,const char *format, int index)
{
	int		strat;

	strat = (index) + 1;
    while (!is_specifier(format[index]))
	{
		if (format[index] == '+')
        {
			tab->plus = 1;
			tab->_rep->plus++;
			index++;
		}
        if (format[index] == ' ')
        {
			tab->space = 1;
			tab->_rep->space++;
			index++;
		}
        if (format[index] == '#')
        {
			tab->shrap = 1;
			tab->_rep->shrap++;
			index++;
		}
	}
	if (tab->plus || tab->shrap || tab->space)
		tab->is_flag = 1;
	ft_specifier(tab, format, index);
	return (index);
}
#include "../incs/ft_printf.h"

static int	ft_hex_len_a(unsigned long num)
{
	int	len;

	len = 0;
	if (num == 0)
		return (1);
	while (num != 0)
	{
		len++;
		num = num / 16;
	}
	return (len);
}
int	p_flag(t_printf *tab)
{
	unsigned long	p;
	int				len;
	int				m;

	p = va_arg(tab->args, unsigned long);
	len = ft_hex_len_a(p);
	if (!tab->dash)
	{
		if (tab->width)
		{
			if (tab->_rep->width > (len + 2))
			{
				m = tab->_rep->width - (len + 2);
				while (m--)
					tab->tl += write(1, " ", 1);
			}
			tab->tl += ft_p_Adress(p);
		}
	}
	else if (tab->dash)
	{
		if (tab->width)
		{
			if (tab->_rep->width > (len + 2))
			{
				m = tab->_rep->width - (len + 2);
				tab->tl += ft_p_Adress(p);
				while (m--)
					tab->tl += write(1, " ", 1);
			}
			else if (tab->_rep->width <= (len + 2))
				tab->tl += ft_p_Adress(p);
		}
		else if (!tab->width)
		{
			tab->tl += ft_p_Adress(p);
		}
	}
	ft_resize_flags(tab);
	return (1);
}
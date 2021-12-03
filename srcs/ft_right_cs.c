#include "../incs/ft_printf.h"

// int	ft_right_cs(t_printf *tab, const char *format, int index)
// {
// 	char *str;
// 	int		i;
// 	int		len;
// 	int		j;

// 	i = 0;
// 	str = (char *)malloc(tab->_rep->width + 1);
// 	if (!str)
// 		return (0);
// 	i = 0;
// 	while (format[index] >= '0' && format[index] <= '9')
// 	{
// 		str[i] = (char)format[index];
// 		index++;
// 		i++;
// 	}
// 	len = ft_atoi(str) - 1;
// 	j = len;
// 	while (j > 0)
// 	{
// 		write (1," ",1);
// 		j--;
// 	}
// 	free(str);
// 	return (len);
// }

int	ft_right_cs(t_printf *tab, const char *format, int index)
{
	char *str;
	int		i;
	int		n;
	int		len;
	int		j;

	i = 0;
	n  = tab->_rep->width;
	str = (char *)malloc(n + 1);
	if (!str)
		return (0);
	i = 0;
	n = index - tab->_rep->width;
	while (format[n] >= '0' && format[n] <= '9')
	{
		str[i] = (char)format[n];
		i++;
		n++;
	}
	len = ft_atoi(str) - 1;
	j = len;
	while (j > 0)
	{
		tab->tl += write (1," ",1);
		j--;
	}
	free(str);
	return (len);
}
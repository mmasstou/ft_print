int	is_specifier(int c)
{
	return (c == '%' || c == 'd' || c == 'i'||c == 'c' || c == 's' ||\
	 c == 'p' || c == 'X' || c == 'x' || c == 'u');
}
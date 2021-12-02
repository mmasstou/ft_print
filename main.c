#include "incs/ft_printf.h"

int main()
{
	int n;
	//int m;
	int d;

	n = 1337;
	//d = ft_printf("%u\n",n);
	// m = ft_printf("%-5.0d", 123);
	// printf("\n");
	// printf("%d\n",m);


	d = printf("%-+5.0d", 123);
	//printf("\nft_printf | %d ",n - 4);
	printf("\n");
	printf("%d\n",d);
	printf("\n");
	return (0);
}
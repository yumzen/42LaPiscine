int ft_recursive_factorial(int nb)
{
	if (nb == 0)
		return (0);
	while (nb > 1)
		return (nb * ft_recursive_factorial(nb - 1));
	return (1);
}

#include <stdio.h>
int main(void)
{
	int  i =  ft_recursive_factorial(12);
	printf("%d", i);
}

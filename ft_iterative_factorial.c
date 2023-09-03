int ft_iterative_factorial(int nb)
{
	int	i;
	int num;

	num = 1;
	if (nb == 0)
		return (0);
	i = nb;
	while (i >= 1)
	{
		num *= i;
		i--;
	}
	return (num);
}

#include <stdio.h>
int main(void)
{
	int num = ft_iterative_factorial(12);
	printf("%d", num);
}


int ft_iterative_power(int nb, int power)
{
	int	num;

	num = 1;
	if ((nb == 0) && (power == 0))
		return (1);
	if (nb == 0)
		return (0);
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	while (power >= 1)
	{
		num *= nb;
		power--;
	}
	return (num);
}

#include <stdio.h>
int	main(void)
{
	int i = ft_iterative_power(2, 3);
	printf("%d", i);
}

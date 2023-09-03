int ft_recursive_power(int nb, int power)
{
	if ((nb == 0) && (power == 0))
		return (1);
	if ((nb == 0) || (power < 0))
		return (0);
	if (power == 0)
		return (1);
	while (power > 1)
	{
		return (nb * ft_recursive_power(nb, power - 1));
	}
	return (nb);
}

#include <stdio.h>
int	main(void)
{
	int i = ft_recursive_power(2, 0);
	printf("%d", i);
}

int	check_prime(int n)
{
	int	i;
	
	i = 2;
	while (i < n)
	{
		if (n % i == 0)
			return (0);
		i++;
	}
	return (1);
}

int ft_find_next_prime(int nb)
{
	int	i;

	i = nb;
	if ((nb == 0) || (nb == 1))
		return (2);
	while (1)
	{
		if (check_prime(i) == 1)
			return (i);
		i++;
	}
	return (0);
}

#include <stdio.h>
int	main(void)
{
	int i = ft_find_next_prime(2);
	printf("%d", i);
}

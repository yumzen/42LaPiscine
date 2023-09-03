int ft_sqrt(int nb)
{
	int	i;

	i = 0;
	if (nb <= 0)
		return (0);
	while (1)
	{
		if (i * i == nb)
			return (i);
	
		if (i * i > nb)
			return (0);
		i++;
	}
	return (0);
}
#include <stdio.h>

int main(void)
{
	int i =	ft_sqrt(256);
	printf("%d", i);
}

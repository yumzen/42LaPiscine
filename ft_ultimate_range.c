#include <stdlib.h>
int ft_ultimate_range(int **range, int min, int max)
{
	int				i;
	unsigned int	index;
	int				*arr;

	i = min;
	index = 0;
	if (min >= max)
		return (0);
	arr = (int*)malloc(sizeof(int)*(max - min));
	while (i < max)
		arr[index++] = i++;
	*range = arr;
	return (index -1);
}

#include <stdio.h>

int main(void)
{
    int *arr;
    int **range = &arr;
    printf("%d\n", ft_ultimate_range (range, -100, 100));
    return (0);
}

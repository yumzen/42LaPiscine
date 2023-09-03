#include <stdlib.h>
int *ft_range(int min, int max)
{
	int				i;
	unsigned int	index;
	int 			*arr;

	i = min + 1;
	index = 0;
	if (min >= max)
		return (0);
	arr = (int*)malloc(sizeof(int)*(max - min));
	while (i < max)
		arr[index++] = i++;
	return (arr);
}


#include <stdio.h>

int main(void)
{
    int min = -33000000;
    int max = 23000000;
    int *arr = ft_range(min, max);
    if (arr == NULL)
        printf("NULL\n");
    else
    {
		for (int i = 0; i < (max - min) - 1; i++)
            printf("%d ", arr[i]);
        printf("\n");
    }
	free(arr);
}

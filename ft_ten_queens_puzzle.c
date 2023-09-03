#include <unistd.h>
#include <stdio.h>

void	print(int arr[])
{
	int x;
	char c;
	
	x = 0;
	while (x <= 9)
	{
		c = arr[x] + 48;
		write(1, &c, 1);
		x++;
	}
	write(1, "\n", 1);
}

int abs(int num)
{
	if (num < 0)
		return (num*(-1));
	return (num);
}

int check(int arr[10], int x, int n)
{	
	int	i;
	i = 0;
    while (i < 10)
	{
		if (arr[i] == n)
			return (0);
		i++;
	}
	i = 0;
	while (x - i >= 0)
	{
		if ((arr[x - i] == abs(n - i)) || (arr[x - i] == abs(n + i)))
			return (0);
		i++;
	}
	i = 0;
	while (x + i <= 9)
	{
		if ((arr[x + i] == abs(n + i)) || (arr[x + i] == abs(n - i)))
			return (0);
		i++;
	}
	return (1);
}

void	dfs(int arr[], int x, int *count)
{
	int n;

	if (x == 10)
	{
		count++;
		printf("count : %d \n", *count);
		print(arr);
		return ;
	}

	n = 0;
	while (n < 10)
	{
		if(check(arr, x, n) == 1)
		{
			arr[x] = n;
			dfs(arr, x + 1, count);
		}
		arr[x] = -1;
		n++;
	}
}

int ft_ten_queens_puzzle(void)
{
	int arr[10];
	int i;
	int count;

	i = 0;
	count = 0;
	while (i < 10)
		arr[i++] = -1;
	printf("first count : %d \n", count);
	dfs(arr, 0, &count);
	printf("last count : %d\n", count);
	return (count);
}
#include <stdio.h>
int main(void)
{
	printf("%d", ft_ten_queens_puzzle());
}
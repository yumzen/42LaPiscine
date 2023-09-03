#include <unistd.h>

void	ft_putchar(char ch)
{
	write(1, &ch, 1);
}

int	main(int argc, char	*argv[])
{
	int	i;
	int j;
	char *tmp;

	i = 1;
	while (i < argc - 1)
	{
		j = 0;
		while (argv[i][j] != 0)
		{
			if (argv[i][j] - argv[i + 1][j] > 0 )
			{
				tmp = argv[i];
				argv[i] = argv[i + 1];
				argv[i + 1] = tmp;
				break;
			}
			else if (argv[i][j] - argv[i+1][j] < 0)
				break;
			j++;
		}
		i++;
	}
	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j] != 0)
		{
			ft_putchar(argv[i][j]);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

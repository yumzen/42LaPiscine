/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyeom <jiyeom@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 17:26:47 by jiyeom            #+#    #+#             */
/*   Updated: 2023/02/21 14:09:18 by jiyeom           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int	put_max_num(int n)
{
	int	i;
	int	num;

	i = n - 1;
	num = 0;
	while (i >= 0)
	{
		num = num + (9 - i);
		if (i >= 1)
			num *= 10;
		i--;
	}
	return (num);
}

char	*check(char arr[10], int num, int n)
{
	int	i;

	i = n - 1;
	arr[n] = '\0';
	while (i >= 0)
	{
		arr[i] = (num % 10) + 48;
		num /= 10;
		i--;
	}
	return (&arr[0]);
}

void	ft_print_combn(int n)
{
	int		max;
	int		num;
	char	array[10];
	int		i;

	max = put_max_num(n);
	num = 0;
	while (num <= max)
	{
		*array = *check(array, num, n);
		i = -1;
		while (++i < n - 1)
		{
			if (array[i] >= array[i + 1])
				break ;
			if (i + 1 == n - 1)
			{
				write(1, &array, n);
				if (array[i - n + 2] == (9 - n + 1) + 48)
					break ;
				write(1, ", ", 2);
			}
		}
		num++;
	}
}

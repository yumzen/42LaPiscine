/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyeom <jiyeom@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 16:03:09 by jiyeom            #+#    #+#             */
/*   Updated: 2023/02/23 16:08:18 by jiyeom           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char ch)
{
	write(1, &ch, 1);
}

int	main(int argc, char	*argv[])
{
	int	i;
	int	j;

	if (argc >= 1)
	{
		i = argc - 1;
		while (i >= 1)
		{
			j = 0;
			while (argv[i][j] != 0)
			{
				ft_putchar(argv[i][j]);
				j++;
			}
			write(1, "\n", 1);
			i--;
		}
	}
}

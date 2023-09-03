/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyeom <jiyeom@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 15:34:57 by jiyeom            #+#    #+#             */
/*   Updated: 2023/02/28 14:38:41 by jiyeom           ###   ########.fr       */
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

	if (argc >= 1)
	{
		i = 0;
		while (argv[0][i] != 0)
		{
			ft_putchar(argv[0][i]);
			i++;
		}
		write(1, "\n", 1);
	}
}

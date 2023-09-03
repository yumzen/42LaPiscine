/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyeom <jiyeom@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 12:34:35 by jiyeom            #+#    #+#             */
/*   Updated: 2023/02/28 15:54:07 by jiyeom           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int	nbrcount(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i] != 0)
	{
		j = i + 1;
		while (base[j] != 0)
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	checkbase(char *base)
{
	int	i;

	i = 0;
	if ((base[0] == 0) || (base[1] == 0))
		return (0);
	while (base[i] != '\0')
	{
		if ((base[i] == '+') || (base[i] == '-'))
			return (0);
		i++;
	}
	return (1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int			len;
	long long	num;

	num = nbr;
	len = 0;
	while (base[len] != '\0')
		len++;
	if ((checkbase(base) == 1) && (nbrcount(base) == 1))
	{
		if (num < 0)
		{
			write(1, "-", 1);
			num *= -1;
		}
		if (num >= len)
		{
			ft_putnbr_base(num / len, base);
			ft_putnbr_base(num % len, base);
		}
		if (num < len)
			write(1, &base[num], 1);
	}
	else
		return ;
}

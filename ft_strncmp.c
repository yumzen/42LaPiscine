/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyeom <jiyeom@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 19:09:46 by jiyeom            #+#    #+#             */
/*   Updated: 2023/02/28 15:50:54 by jiyeom           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	if (n > 1)
	{
		while ((i + 1 < n) && (s1[i] && s2[i]))
		{
			if (s1[i] != s2[i])
				return (s1[i] - s2[i]);
			else
				i++;
		}
		return (s1[i] - s2[i]);
	}
	else if (n == 1)
		return (s1[0] - s2[0]);
	else
		return (0);
}

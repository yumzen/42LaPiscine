/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyeom <jiyeom@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 21:44:11 by jiyeom            #+#    #+#             */
/*   Updated: 2023/02/27 17:28:43 by jiyeom           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
char	*ft_strstr(char	*str, char	*to_find)
{
	int	i;
	int	j;

	if ((to_find[0]) == '\0')
		return (&str[0]);
	i = 0;
	while (str[i] != '\0')
	{
		j = 0;
		while (to_find[j] != '\0')
		{
			if ((str[i + j]) != (to_find[j]))
				break ;
			if (to_find[j + 1] == '\0')
				return (&str[i]);
			j++;
		}
		i++;
	}
	return (0);
}

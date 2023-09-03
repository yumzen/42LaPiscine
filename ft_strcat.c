/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyeom <jiyeom@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 19:48:23 by jiyeom            #+#    #+#             */
/*   Updated: 2023/02/22 15:02:46 by jiyeom           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
char	*ft_strcat(char	*dest, char	*src)
{
	int	i;
	int	destlen;
	int	len;

	i = 0;
	destlen = 0;
	while (dest[i] != 0)
	{
		i++;
		destlen++;
	}
	i = 0;
	len = destlen;
	while (src[i] != 0)
	{
		dest[destlen + i] = src[i];
		i++;
		len++;
	}
	dest[len] = '\0';
	return (dest);
}

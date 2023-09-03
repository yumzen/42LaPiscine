/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyeom <jiyeom@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 14:54:34 by jiyeom            #+#    #+#             */
/*   Updated: 2023/02/28 13:25:58 by jiyeom           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
unsigned int	arrlen(char *arr)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (arr[i] != 0)
	{
		len++;
		i++;
	}
	return (len);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	destlen;
	unsigned int	srclen;
	unsigned int	i;

	destlen = 0;
	srclen = 0;
	destlen = arrlen(dest);
	srclen = arrlen(src);
	if ((destlen < size) && (size != 0))
	{
		i = 0;
		while ((destlen + i + 1 < size) && (src[i] != 0))
		{
			dest[destlen + i] = src[i];
			i++;
		}
		dest[destlen + i] = '\0';
		return (srclen + destlen);
	}
	return (srclen + size);
}

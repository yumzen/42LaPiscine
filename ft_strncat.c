/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyeom <jiyeom@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 15:03:32 by jiyeom            #+#    #+#             */
/*   Updated: 2023/02/28 13:29:36 by jiyeom           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	i;
	int				destlen;
	int				len;

	if (nb != 0)
	{
		i = 0;
		destlen = 0;
		while (dest[i] != 0)
		{
			i++;
			destlen++;
		}
		i = 0;
		len = destlen;
		while ((src[i] != 0) && (i < nb))
		{
			dest[destlen + i] = src[i];
			i++;
			len++;
		}
		dest[len] = '\0';
	}
	return (dest);
}

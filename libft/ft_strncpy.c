/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviinika <mviinika>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 08:46:45 by mviinika          #+#    #+#             */
/*   Updated: 2021/12/20 14:15:08 by mviinika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "libft.h"

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	size_t	i;

	i = 0;
	while (src[i])
	{
		if (n == 0)
			return (dest);
		dest[i] = src[i];
		i++;
		n--;
	}
	while (n--)
		dest[i++] = '\0';
	return (dest);
}

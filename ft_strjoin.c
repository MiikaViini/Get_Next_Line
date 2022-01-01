/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviinika <mviinika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 14:47:26 by mviinika          #+#    #+#             */
/*   Updated: 2021/12/31 20:50:01 by mviinika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	char	*fresh;

	len = ft_strlen(s1) + ft_strlen(s2);
	fresh = ft_strnew(len);
	if (!fresh)
		return (0);
	while (s1 && *s1 != '\0')
		*fresh++ = *s1++;
	while (s2 && *s2 != '\0')
		*fresh++ = *s2++;
	*fresh = '\0';
	return (fresh - len);
}

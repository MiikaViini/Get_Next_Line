/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviinika <mviinika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 14:47:26 by mviinika          #+#    #+#             */
/*   Updated: 2022/01/02 14:11:47 by mviinika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "libft.h"
#include  <stdio.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len1;
	size_t	len2;
	char	*fresh;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	fresh = (char *)malloc(sizeof(*fresh) * (len1 + len2 +1));
	if (!fresh)
		return (NULL);
	ft_memmove(fresh, s1, len1);
	ft_memmove(fresh + len1, s2, len2);
	fresh[len1 + len2] = '\0';
	free((char *)s1);
	return (fresh);
}
// 	while (s1 && *s1 != '\0')
// 		*fresh++ = *s1++;
// 	while (s2 && *s2 != '\0')
// 		*fresh++ = *s2++;
// 	*fresh = '\0';	
// 	return (fresh - len);
// }

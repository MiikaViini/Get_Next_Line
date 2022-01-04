/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviinika <mviinika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 10:28:43 by mviinika          #+#    #+#             */
/*   Updated: 2022/01/04 14:16:50 by mviinika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/includes/libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*fresh;
	size_t	i;

	i = ft_strlen((char *)s);
	fresh = (char *)malloc(sizeof(char) * (i + 1));
	if (fresh == NULL)
		return (NULL);
	while (*s)
		*fresh++ = f(*s++);
	*fresh = '\0';
	return (fresh - i);
}

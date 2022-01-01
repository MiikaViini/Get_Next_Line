/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviinika <mviinika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 11:18:23 by mviinika          #+#    #+#             */
/*   Updated: 2021/12/31 17:17:25 by mviinika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*str;
	str = (char *)s;
	while (str && *str != '\0')
	{
		if (*str == c)
			return (str);
		str++;
	}
	return (NULL);
}

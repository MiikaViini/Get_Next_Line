/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviinika <mviinika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 10:42:33 by mviinika          #+#    #+#             */
/*   Updated: 2021/12/31 21:01:40 by mviinika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "libft.h"

char	*ft_strnew(size_t size)
{
	char	*fresh;
	int		i;

	i = 0;
	fresh = (char *)malloc(sizeof(*fresh) * size + 1);
	if (fresh == NULL)
		return (NULL);
	while (size--)
		fresh[i++] = '\0';
	fresh[i] = '\0';
	return (fresh);
}

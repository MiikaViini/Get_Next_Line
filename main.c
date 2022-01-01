/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviinika <mviinika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 15:06:38 by mviinika          #+#    #+#             */
/*   Updated: 2022/01/01 14:52:58 by mviinika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"
#include <fcntl.h>
#include <stdio.h>

void	test(int fd)
{
	char	*line;
	int		ret;
	int		i;

	line = NULL;
	i = 1;
	ret = 1;
	while (ret == 1)
	{
		ret = get_next_line(fd, &line);
		printf("%d %s\n", ret, line);
		free(line);
		line = NULL;
	}
	free(line);
	close(fd);
}

int	main(void)
{
	int	fd;

	fd = open("testfile.txt", O_RDONLY);
	test(fd);
}

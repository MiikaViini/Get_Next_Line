/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviinika <mviinika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 15:06:38 by mviinika          #+#    #+#             */
/*   Updated: 2022/01/04 00:28:53 by mviinika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

void	test(int fd)
{
	char	*line;
	int		ret;

	line = NULL;
	ret = 1;
	while (ret == 1)
	{
		ret = get_next_line(fd, &line);
		printf("%d %s\n", ret, line);
		free(line);
		line = NULL;
	}
	close(fd);
}

int	main(void)
{
	int	fd;

	fd = open("bible.txt", O_RDONLY);
	test(fd);
	return 0;
}

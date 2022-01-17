/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviinika <mviinika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 15:06:38 by mviinika          #+#    #+#             */
/*   Updated: 2022/01/17 12:21:13 by mviinika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

void	test(int fd)
{
	char	*line;
	int		ret;
	int		i;
	int		linecount;

	i = 0;
	line = NULL;
	linecount = 1;
	ret = 1;
	while (ret == 1)
	{
		ret = get_next_line(fd, &line);
		printf("reader :%d, line :%d %s\n",ret ,linecount, line);
		free(line);
		line = NULL;
		linecount++;
	}
	close(fd);
}

int	main(void)
{
	int	fd;

	fd = open("bible.txt", O_RDONLY);
	test(fd);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviinika <mviinika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/31 13:58:43 by mviinika          #+#    #+#             */
/*   Updated: 2022/01/14 14:45:57 by mviinika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_line_output(char *remain)
{
	size_t	index;
	char	*str;

	index = 0;
	if (!remain[index])
		return (NULL);
	while (remain[index] && remain[index] != '\n')
		index++;
	str = ft_strnew(index);
	if (!str)
		return (NULL);
	index = 0;
	while (remain[index] && remain[index] != '\n')
	{
		str[index] = remain[index];
		index++;
	}
	return (str);
}

static char	*ft_get_remain(char *remain)
{
	size_t		index;
	size_t		str_index;
	char		*str;

	index = 0;
	str_index = 0;
	while (remain[index] && remain[index] != '\n')
		index++;
	if (!remain[index])
	{
		ft_strdel(&remain);
		return (NULL);
	}
	str = ft_strnew(ft_strlen(remain) - index);
	if (!str)
		return (NULL);
	index++;
	while (remain[index])
		str[str_index++] = remain[index++];
	ft_strdel(&remain);
	return (str);
}

static char	*ft_read_and_join(int fd, char *remain)
{
	int			red_bytes;
	char		buff[BUFF_SIZE + 1];
	char		*temp;

	red_bytes = 1;
	temp = NULL;
	if (!remain)
		remain = ft_strnew(1);
	while (!ft_strchr(remain, '\n') && red_bytes != 0)
	{
		red_bytes = read(fd, buff, BUFF_SIZE);
		if (red_bytes == -1)
			return (NULL);
		buff[red_bytes] = '\0';
		temp = ft_strjoin(remain, buff);
		ft_strdel(&remain);
		remain = temp;
	}
	return (remain);
}

int	get_next_line(const int fd, char **line)
{
	static char	*remain[MAX_FD + 1];

	if (!line || fd < 0 || BUFF_SIZE <= 0)
		return (-1);
	remain[fd] = ft_read_and_join(fd, remain[fd]);
	if (remain[fd] == NULL)
		return (-1);
	*line = ft_line_output(remain[fd]);
	remain[fd] = ft_get_remain(remain[fd]);
	return (remain[fd] || *line);
}

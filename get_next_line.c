/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviinika <mviinika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/31 13:58:43 by mviinika          #+#    #+#             */
/*   Updated: 2022/01/17 12:01:15 by mviinika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_line_output(char **remain, const int fd)
{
	size_t	index;
	char	*str;

	index = 0;
	if (!remain[fd][index])
		return (NULL);
	while (remain[fd][index] && remain[fd][index] != '\n')
		index++;
	str = ft_strnew(index);
	if (!str)
		return (NULL);
	index = 0;
	while (remain[fd][index] && remain[fd][index] != '\n')
	{
		str[index] = remain[fd][index];
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

int	ft_read_and_join(int fd, char **remain)
{
	int			red_bytes;
	char		buff[BUFF_SIZE + 1];
	char		*temp;

	red_bytes = 1;
	temp = NULL;
	if (!remain[fd])
		remain[fd] = ft_strnew(1);
	while (!ft_strchr(remain[fd], '\n') && red_bytes != 0)
	{
		red_bytes = read(fd, buff, BUFF_SIZE);
		if (red_bytes == -1)
			return (red_bytes);
		buff[red_bytes] = '\0';
		temp = ft_strjoin(remain[fd], buff);
		ft_strdel(&remain[fd]);
		remain[fd] = temp;
	}
	return (red_bytes);
}

int	get_next_line(const int fd, char **line)
{
	static char	*remain[MAX_FD + 1];
	int			reader;

	if (!line || fd < 0 || BUFF_SIZE <= 0)
		return (-1);
	reader = ft_read_and_join(fd, remain);
	if (reader < 0)
		return (-1);
	*line = ft_line_output(remain, fd);
	if (!*line && reader > 0)
		return (-1);
	remain[fd] = ft_get_remain(remain[fd]);
	if (reader > 0 && remain[fd] == NULL)
		return (-1);
	return (*line != NULL);
}

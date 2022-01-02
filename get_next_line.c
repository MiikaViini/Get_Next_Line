/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviinika <mviinika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/31 13:58:43 by mviinika          #+#    #+#             */
/*   Updated: 2022/01/02 14:00:47 by mviinika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_save(char *save)
{
	int		i;
	int		k;
	char	*str;

	i = 0;
	k = 0;
	if (!save)
		return (0);
	while (save[i] && save[i] != '\n')
		i++;
	if (!save[i])
	{
		free(save);
		return (NULL);
	}
	str = ft_strnew(ft_strlen(save) - i);
	if (!str)
		return (0);
	i++;
	while (save[i])
		str[k++] = save[i++];
	str[k] = '\0';
	free(save);
	return (str);
}

char	*ft_new_line(char *save)
{
	size_t	i;
	char	*str;

	i = 0;
	if (!save[i])
	{
		return (NULL);
	}
	while (save[i] && save[i] != '\n')
		i++;
	str = ft_strnew(i);
	if (!str)
		return (NULL);
	i = 0;
	while (save[i] && save[i] != '\n')
	{
		str[i] = save[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

int	get_next_line(int fd, char **line)
{
	static char	*save;
	char		*buff;
	int			red_bytes;

	red_bytes = 1;
	if (!line || fd < 0 || BUFF_SIZE <= 0)
		return (-1);
	buff = malloc(sizeof(*buff) * (BUFF_SIZE +1));
	if (!buff)
		return (-1);
	while (!ft_strchr(save, '\n') && red_bytes != 0)
	{	
		red_bytes = read(fd, buff, BUFF_SIZE);
		if (red_bytes == -1)
		{
			free(buff);
			return (-1);
		}
		buff[red_bytes] = '\0';
		save = ft_strjoin(save, buff);
	}
	*line = ft_new_line(save);
	save = ft_save(save);
	ft_strdel(&buff);
	if (red_bytes == 0)
		return (0);
	return (1);
}
/*red_bytes = 1;
	if (!line || fd < 0 || BUFF_SIZE <= 0)
		return (-1);
	buff = ft_strnew(BUFF_SIZE);
	if (!buff)
		return (-1);
	while (!ft_strchr(save, '\n') && red_bytes != 0)
	{	
		red_bytes = read(fd, buff, BUFF_SIZE);
		if (red_bytes == -1)
		{
			free(buff);
			return (-1);
		}
		buff[red_bytes] = '\0';
		save = ft_strjoin(save, buff);
	}*/
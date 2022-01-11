/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviinika <mviinika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/31 13:58:43 by mviinika          #+#    #+#             */
/*   Updated: 2022/01/05 10:51:59 by mviinika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*ft_save(char *save)
{
	int		i;
	int		k;
	char	*str;

	i = 0;
	k = 0;
	if (!save)
		return (NULL);
	while (save[i] && save[i] != '\n')
		i++;
	if (!save[i])
	{
		ft_strdel(&save);
		return (NULL);
	}
	str = ft_strnew(ft_strlen(save) - i);
	if (!str)
		return (NULL);
	i++;
	while (save[i])
		str[k++] = save[i++];
	ft_strdel(&save);
	return (str);
}

char	*ft_new_line(char *save)
{
	size_t	i;
	char	*str;

	i = 0;
	if (!save)
		return (NULL);
	while (save[i]&& save[i] != '\n')
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
	return (str);
}

char	*ft_return_temp(int fd, char *save)
{
	char		*temp;
	int			red_bytes;
	char		*buff;

	red_bytes = 1;
	temp = NULL;
	buff = ft_strnew(BUFF_SIZE);
	if (!buff)
		return (NULL);
	if (!save)
		save = ft_strnew(1);
	while (!ft_strchr(save, '\n') && red_bytes != 0)
	{	
		red_bytes = read(fd, buff, BUFF_SIZE);
		if (red_bytes == -1)
		{
			ft_strdel(&buff);
			return (NULL);
		}
		buff[red_bytes] = '\0';
		temp = ft_strjoin(save, buff);
		ft_strdel(&save);
		save = temp;
	}
	ft_strdel(&buff);
	return (save);
}

int	get_next_line(const int fd, char **line)
{
	static char	*save;

	if (!line || fd < 0 || BUFF_SIZE <= 0)
		return (-1);
	save = ft_return_temp(fd, save);
	if (save == NULL)
		return (-1);
	//*line = ft_new_line(save);
	*line = ft_new_line(save);
	if (line == NULL)
		return (-1);
	
	save = ft_save(save);
	return (save != NULL || **line != '\0');
}

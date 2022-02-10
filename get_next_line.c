/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: dhoang <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/15 12:56:07 by dhoang        #+#    #+#                 */
/*   Updated: 2020/01/15 12:57:37 by dhoang        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_memcpy(char *dst, char *src, size_t n)
{
	int i;

	i = 0;
	if (dst == 0 && src == 0)
		return (0);
	while (n > 0)
	{
		dst[i] = src[i];
		i++;
		n--;
	}
	dst[i] = '\0';
	return (dst);
}

int		newline(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

int		buffervsline(char *temp)
{
	if (temp)
		if ((newline(temp)) >= 0)
			return (1);
	return (0);
}

int		get_next_line(int fd, char **line)
{
	int				ret;
	char			readbuf[BUFFER_SIZE + 1];
	static char		*temp[MAX_FD];

	if (fd < 0 || line == NULL)
		return (-1);
	if ((buffervsline(temp[fd])))
		return (makeline(line, &temp[fd], '\n'));
	else
		ret = read(fd, readbuf, BUFFER_SIZE);
	if (ret <= 0 && !temp[fd])
	{
		if (ret == 0)
			*line = ft_strndup("", 1);
		return (ret == 0 ? 0 : -1);
	}
	readbuf[ret] = '\0';
	if ((maketemp(&temp[fd], readbuf)) < 0)
		return (-1);
	if (ret == 0)
		return (makeline(line, &temp[fd], '\0'));
	else if ((newline(temp[fd])) >= 0)
		return (makeline(line, &temp[fd], '\n'));
	else
		return (get_next_line(fd, line));
}

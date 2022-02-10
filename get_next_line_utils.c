/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: dhoang <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/17 08:32:42 by dhoang        #+#    #+#                 */
/*   Updated: 2020/01/17 08:32:43 by dhoang        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t		ft_strlen(char *str, char c)
{
	size_t	i;

	i = 0;
	while (str[i] != c)
		i++;
	return (i);
}

char		*ft_strndup(char *s1, size_t len)
{
	size_t	i;
	char	*s2;

	i = 0;
	s2 = malloc(sizeof(*s1) * (len + 1));
	if (!s2)
		return (0);
	while (i < len)
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

char		*ft_strjoin(char *s1, char *s2)
{
	int		len;
	int		i;
	char	*str1;

	i = 0;
	if (!s1)
		return (0);
	len = (ft_strlen(s1, '\0') + ft_strlen(s2, '\0'));
	str1 = malloc(sizeof(char) * (len + 1));
	if (!str1)
		return (0);
	while (*s1)
	{
		str1[i] = *s1;
		i++;
		s1++;
	}
	while (*s2)
	{
		str1[i] = *s2;
		i++;
		s2++;
	}
	str1[i] = '\0';
	return (str1);
}

int			makeline(char **line, char **temp, char c)
{
	char	*str1;
	size_t	len;
	size_t	origlen;

	str1 = NULL;
	if (!*temp)
		return (-1);
	origlen = 0;
	len = ft_strlen(*temp, c);
	str1 = ft_strndup(*temp, len);
	if (!str1)
		return (-1);
	origlen = ft_strlen(*temp, '\0');
	if (len + 1 < origlen)
		ft_memcpy(*temp, (*temp + len + 1), (origlen - len));
	else
	{
		free(*temp);
		*temp = NULL;
	}
	*line = str1;
	return (c == '\n' ? 1 : 0);
}

int			maketemp(char **temp, char *readbuf)
{
	char	*newtemp;

	newtemp = NULL;
	if (!readbuf)
		return (-1);
	if (*temp)
		newtemp = ft_strjoin(*temp, readbuf);
	else
		newtemp = ft_strndup(readbuf, ft_strlen(readbuf, '\0'));
	free(*temp);
	if (!newtemp)
		return (-1);
	*temp = newtemp;
	return (0);
}

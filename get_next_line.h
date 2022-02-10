/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: dhoang <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/15 12:58:13 by dhoang        #+#    #+#                 */
/*   Updated: 2020/01/15 13:03:29 by dhoang        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# define MAX_FD 1023

int		get_next_line(int fd, char **line);
size_t	ft_strlen(char *s, char c);
char	*ft_strndup(char *s1, size_t len);
char	*ft_strjoin(char *s1, char *s2);
int		makeline(char **line, char **temp, char c);
int		maketemp(char **temp, char *readbuf);
void	*ft_memcpy(char *dst, char *src, size_t n);
int		newline(char *str);
int		buffervsline(char *temp);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekauppil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 18:22:06 by ekauppil          #+#    #+#             */
/*   Updated: 2019/12/13 12:22:07 by ekauppil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_empty_bufs(char **from, char **to, size_t len)
{
	char	*tmp;

	tmp = ft_strnew(len + BUFF_SIZE);
	if (*from)
	{
		ft_memcpy(tmp, *from, ft_strlen(*from));
		ft_strdel(from);
		return (1);
	}
	*from = tmp;
	ft_memcpy(*from + len, to, BUFF_SIZE);
	return (len);
}

static int	ft_allocate_line(char **line, size_t length, int i, char **buffers)
{
	char	*newline;
	char	*buffer;

	buffer = *line;
	newline = ft_memchr(buffer, '\n', i);
	if (!(*line = ft_strnew(length + (newline ? newline - buffer : i))))
		return (-1);
	if (*buffers)
	{
		ft_memcpy(*line, *buffers, ft_strlen(*buffers));
		ft_strdel(buffers);
	}
	if (newline && !(*buffers = ft_strsub(newline, 1, i - (newline + 1 - buffer))))
		return (-1);
	ft_memcpy(*line + length, buffer, (newline ? newline - buffer : i));
	return (1);
}

static int	ft_assemble_bufs(size_t retlen, char *buffer, int *i, char **buffers, size_t length, char **line)
{
	if (retlen % (BUFF_SIZE * MAXRC) != 0 || retlen == 0)
	{
		*i = 0;
		if (length == 0 ||length % (BUFF_SIZE * MAXRC) != 0)
			ft_memcpy(*line + length, buffer, BUFF_SIZE);
		return (!!(retlen));
	}
	else if (retlen % (BUFF_SIZE * MAXRC) == 0)
	{
		if (length == 0 || length % (BUFF_SIZE * MAXRC) != 0)
			ft_memcpy(*(buffers) + length, buffer, *i);
		if (length % (BUFF_SIZE * MAXRC) != 0)
		{
			*i = 0;
			return (retlen);
		}
		length = retlen;
	}
	return (retlen);
}

static int	ft_read_next_line(const int fd, char **line,
    size_t length, char **buffers)
{
	char	buffer[BUFF_SIZE];
	int		return_int;
	int		retlen;

	if ((return_int = read(fd, buffer, BUFF_SIZE)) == -1)
		return (-1);
	if (ft_memchr((*line = buffer), '\n', return_int) || return_int < BUFF_SIZE)
	{
		if (ft_allocate_line(line, length, return_int, buffers + fd) < 0)
			return (-1);
	}
	else if (return_int > 0)
	{
		if (length != 0 && length % (BUFF_SIZE * MAXRC) == 0)
			return (ft_empty_bufs(buffers + fd, (char**)&(buffer), length));
		while (return_int)
		{
			if (0 > (retlen = ft_read_next_line(fd, line, length + return_int, buffers)))
				return (-1);
			if (ft_assemble_bufs(retlen, buffer, &return_int, buffers + fd, length, line) && !return_int)
				return (retlen);
		}
	}
	if (return_int > 0)
		return_int = 1;
	return (return_int);
}

int			get_next_line(const int fd, char **line)
{
	static char	*buffers[MAX_FD];
	char		*newline;
	int			i;
	char		*tmpptr;

	if (fd < 0 || fd >= MAX_FD)
		return (-1);
	if (buffers[fd] && (newline = ft_strchr(buffers[fd], '\n')))
	{
		if (!(*line = ft_strsub(buffers[fd], 0, newline - buffers[fd])))
			return (-1);
		tmpptr = buffers[fd];
		if (!(buffers[fd] = ft_strdup(newline + 1)))
			return (-1);
		free(tmpptr);
		i = !!(newline - buffers[fd]);
	}
	else
	{
		i = ft_read_next_line(fd, line, (buffers[fd] ? ft_strlen(buffers[fd]) : 0), buffers);
		if (i == 0 && *line && **line)
			i = 1;
	}
	return ((i < 0 ? -1 : i));
}

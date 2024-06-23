/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnovak <dnovak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 18:08:05 by dnovak            #+#    #+#             */
/*   Updated: 2024/06/22 00:56:59 by dnovak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	free_mem(char *buf, char *line)
{
	free(buf);
	if (line != NULL)
		free(line);
}

static char	*save_buf(char *buf, char **line, size_t size)
{
	char	*temp;
	size_t	len;

	len = ft_strlen(*line);
	if (len == 0 && size == 0)
		return (NULL);
	temp = malloc((len + size + 1) * sizeof(char));
	if (temp == NULL)
		return (NULL);
	ft_strncpy(temp, *line, len + 1);
	if (*line != NULL)
		free(*line);
	ft_strncpy(temp + len, buf, size);
	*line = temp;
	len += size;
	*(*line + len) = '\0';
	return (buf);
}

char	*read_buf(char *buf, char **line, char *last, int fd)
{
	ssize_t	i;
	size_t	size;

	i = 1;
	size = 0;
	while (size < BUFFER_SIZE && *last != '\n')
	{
		i = read(fd, buf + size, 1);
		if (i == -1)
			return (NULL);
		if (i == 0)
			*last = '\n';
		else
			*last = *(buf + size++);
	}
	return (save_buf(buf, line, size));
}

// Returns a line read from a file descriptor (fd). Returns NULL if there is
// nothing else to read, or an error occurred.
char	*get_next_line(int fd)
{
	char	*buf;
	char	*line;
	char	last;

	line = NULL;
	buf = (char *)malloc(BUFFER_SIZE * sizeof(char));
	if (buf == NULL)
		return (free_mem(buf, line), NULL);
	last = 0;
	while (last != '\n')
	{
		if (read_buf(buf, &line, &last, fd) == NULL)
			return (free_mem(buf, line), NULL);
	}
	free(buf);
	return (line);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnovak <dnovak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 18:08:05 by dnovak            #+#    #+#             */
/*   Updated: 2024/06/24 00:43:56 by dnovak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	free_all(t_buf **list, char **line)
{
	t_buf	*curr_node;
	t_buf	*next_node;

	if (*list != NULL)
	{
		curr_node = *list;
		while (curr_node != NULL)
		{
			if (curr_node->buf != NULL)
				free(curr_node->buf);
			next_node = curr_node->next;
			free(curr_node);
			curr_node = next_node;
		}
		*list = NULL;
	}
	if (*line != NULL)
	{
		free(*line);
		*line = NULL;
	}
}

static t_buf	*check_fd(int fd, t_buf **list)
{
	t_buf	*curr_node;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	curr_node = *list;
	while (curr_node != NULL && curr_node->fd != fd && curr_node->next != NULL)
		curr_node = curr_node->next;
	if (curr_node == NULL || curr_node->fd != fd)
	{
		curr_node = ft_bufnew(fd);
		if (curr_node == NULL)
			return (NULL);
		curr_node->next = *list;
		*list = curr_node;
	}
	curr_node->size = 0;
	return (curr_node);
}

static int	save_buf(t_buf *curr_node, char **end_char, char **line,
		size_t *len)
{
	char	*temp;

	*end_char = (char *)ft_memchr(curr_node->buf, '\n', curr_node->size);
	if (*end_char != NULL)
		curr_node->size = *end_char + 1 - curr_node->buf;
	temp = (char *)malloc((*len + curr_node->size + 1) * sizeof(char));
	if (temp == NULL)
		return (-1);
	ft_memmove(temp, *line, *len);
	ft_memmove(temp + *len, curr_node->buf, curr_node->size);
	if (*line != NULL)
		free(*line);
	*line = temp;
	ft_bzero(curr_node->buf, curr_node->size);
	*len += curr_node->size;
	*(*line + *len) = '\0';
	return (1);
}

static char	*read_line(int fd, t_buf *node, char **line)
{
	char	*end_char;
	size_t	len;

	len = 0;
	while (1)
	{
		if (node->size != 0)
		{
			end_char = NULL;
			if (save_buf(node, &end_char, line, &len) == -1)
				return (NULL);
			if (end_char != NULL)
			{
				ft_memmove(node->buf, end_char + 1, BUFFER_SIZE - node->size);
				ft_bzero(node->buf + BUFFER_SIZE - node->size, node->size);
				break ;
			}
		}
		node->size = read(fd, node->buf, BUFFER_SIZE);
		if (node->size == -1)
			return (NULL);
		if (node->size == 0)
			break ;
	}
	return (*line);
}

// Returns a line read from a file descriptor (fd). Returns NULL if there is
// nothing else to read, or an error occurred.
char	*get_next_line(int fd)
{
	static t_buf	*list;
	t_buf			*fd_node;
	char			*line;

	line = NULL;
	fd_node = check_fd(fd, &list);
	if (fd_node == NULL)
		return (free_all(&list, &line), NULL);
	if (fd_node->buf == NULL)
	{
		fd_node->buf = (char *)malloc(BUFFER_SIZE * sizeof(char));
		if (fd_node->buf == NULL)
			return (free_all(&list, &line), NULL);
		ft_bzero(fd_node->buf, BUFFER_SIZE);
	}
	else
	{
		while (fd_node->size < BUFFER_SIZE && *(fd_node->buf + fd_node->size))
			fd_node->size++;
	}
	if (read_line(fd, fd_node, &line) == NULL)
		return (free_all(&list, &line), NULL);
	if (*(fd_node->buf) == '\0')
		ft_bufdel(&list, fd);
	return (line);
}

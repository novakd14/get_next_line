/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnovak <dnovak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 18:08:14 by dnovak            #+#    #+#             */
/*   Updated: 2024/06/23 22:56:33 by dnovak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)s;
	while (n > 0)
		*(ptr + --n) = '\0';
}

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ptr;
	size_t			i;

	ptr = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (*(ptr + i) == (unsigned char)c)
			return ((void *)(ptr + i));
		i++;
	}
	return (NULL);
}

// Need to correct this function in libft for dest || src == NULL
void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*dptr;
	unsigned char	*sptr;
	size_t			i;

	if (dest == NULL || src == NULL)
		return (dest);
	dptr = (unsigned char *)dest;
	sptr = (unsigned char *)src;
	if (src >= dest)
	{
		i = 0;
		while (i < n)
		{
			*(dptr + i) = *(sptr + i);
			i++;
		}
	}
	else
		while (n-- > 0)
			*(dptr + n) = *(sptr + n);
	return (dest);
}

t_buf	*ft_bufnew(int fd)
{
	t_buf	*new_node;

	new_node = (t_buf *)malloc(sizeof(t_buf));
	if (new_node == NULL)
		return (NULL);
	new_node->fd = fd;
	new_node->buf = NULL;
	new_node->size = 0;
	new_node->next = NULL;
	return (new_node);
}

void	ft_bufdel(t_buf **list, int fd)
{
	t_buf	*del_node;
	t_buf	*prev_node;

	del_node = *list;
	while (del_node != NULL && del_node->fd != fd)
	{
		prev_node = del_node;
		del_node = del_node->next;
	}
	if (del_node == *list)
		*list = del_node->next;
	else
		prev_node->next = del_node->next;
	if (del_node->buf != NULL)
		free(del_node->buf);
	free(del_node);
}

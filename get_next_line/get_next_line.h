/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnovak <dnovak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 14:14:54 by dnovak            #+#    #+#             */
/*   Updated: 2024/06/23 22:59:18 by dnovak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h> // malloc, free
# include <unistd.h> // read
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_buf
{
	int				fd;
	char			*buf;
	ssize_t			size;
	struct s_buf	*next;
}					t_buf;

char				*get_next_line(int fd);

// Utility functions
void				ft_bzero(void *s, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
void				*ft_memmove(void *dest, const void *src, size_t n);
t_buf				*ft_bufnew(int fd);
void				ft_bufdel(t_buf **list, int fd);

#endif // GET_NEXT_LINE_H

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnovak <dnovak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 14:14:54 by dnovak            #+#    #+#             */
/*   Updated: 2024/06/22 00:44:35 by dnovak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h> // malloc, free
# include <unistd.h> // read
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);

// Utility functions
char	*ft_strncpy(char *dest, const char *src, size_t n);
size_t	ft_strlen(char *s);

// Unity functions (make static after testing)
char	*read_buf(char *buf, char **line, char *last, int fd);

#endif // GET_NEXT_LINE_H

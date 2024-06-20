/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnovak <dnovak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 14:14:54 by dnovak            #+#    #+#             */
/*   Updated: 2024/06/20 19:30:55 by dnovak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h> // malloc, free
# include <unistd.h> // read
# define BUFFER_SIZE 42

char	*get_next_line(int fd);

#endif // GET_NEXT_LINE_H

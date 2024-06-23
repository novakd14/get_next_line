/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnovak <dnovak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 18:08:14 by dnovak            #+#    #+#             */
/*   Updated: 2024/06/21 17:31:26 by dnovak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	size_t	len;

	if (dest == NULL || src == NULL)
		return (dest);
	len = 0;
	while (len < n && *(src + len))
	{
		*(dest + len) = *(src + len);
		len++;
	}
	while (len < n)
		*(dest + len++) = '\0';
	return (dest);
}

// When implementing to libft, change ft_strlen to consider NULL string
size_t	ft_strlen(char *s)
{
	size_t	len;

	if (s == NULL)
		return (0);
	len = 0;
	while (*(s + len))
		len++;
	return (len);
}

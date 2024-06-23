/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_get_next_line.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnovak <dnovak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 16:44:22 by dnovak            #+#    #+#             */
/*   Updated: 2024/06/21 23:45:42 by dnovak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_TEST_H
# define LIBFTPRINTF_TEST_H
# include "../get_next_line/get_next_line.h"
# include "unity.h"
# include <fcntl.h>   // open
# include <strings.h> // bzero
# include <unistd.h>  // close

# define MAX_INT (int)2147483647
# define MIN_INT (int)-2147483648
# define MAX_UINT (unsigned)4294967295
# define MIN_UINT (unsigned)0

#endif // LIBFTPRINTF_TEST_H

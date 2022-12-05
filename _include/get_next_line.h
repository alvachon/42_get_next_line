/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvachon <alvachon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 18:29:53 by alvachon          #+#    #+#             */
/*   Updated: 2022/07/27 00:24:00 by alvachon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include <stdint.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE BUFSIZ
# endif

# if BUFFER_SIZE > 9223372036854775806
#  undef BUFFER_SIZE
#  define BUFFER_SIZE 0
# endif

char	*get_next_line(int fd);
void	*ft_memset(void *b, int c, size_t len);
void	*ft_calloc(size_t count, size_t size);
size_t	ft_strlen(const char *s);
char	*ft_strjoin(char *s1, char *s2);

#endif

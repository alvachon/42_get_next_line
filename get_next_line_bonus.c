/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvachon <alvachon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 15:15:26 by alvachon          #+#    #+#             */
/*   Updated: 2022/07/27 00:20:11 by alvachon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include   "get_next_line_bonus.h"

static void	ft_copy_next(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s2[i])
	{
		s1[i] = s2[i];
		i++;
	}
	s1[i] = '\0';
}

static int	ft_get_line(char *container, char **line)
{
	int		len;
	int		i;
	int		nl;
	char	*str;

	len = 0;
	i = 0;
	while (container[len] && container[len] != '\n')
		len++;
	nl = 0;
	if (container[len] == '\n')
		nl = 1;
	str = ft_calloc(len + nl + 1, sizeof(char));
	if (str == NULL)
		return (-1);
	while (i < (len + nl))
	{
		str[i] = container[i];
		i++;
	}
	*line = ft_strjoin(*line, str);
	if (line == NULL)
		return (-1);
	ft_copy_next(container, &container[len + nl]);
	return (nl);
}

static char	*ft_free(char **line)
{
	if (*line != NULL)
		free(*line);
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	container[FOPEN_MAX][BUFFER_SIZE + 1];
	char		*line;
	int			ret;
	int			readed;

	line = NULL;
	ret = 0;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &container, 0) < 0)
		return (0);
	while (ret == 0)
	{
		ret = ft_get_line(container[fd], &line);
		if (ret == -1)
			return (ft_free(&line));
		if (ret == 0)
		{
			readed = read(fd, container[fd], BUFFER_SIZE);
			if (readed == 0 && *line)
				ret = 1;
			else if (readed <= 0)
				return (ft_free(&line));
			container[fd][readed] = '\0';
		}
	}
	return (line);
}

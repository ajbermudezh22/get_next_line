/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albermud <albermud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 17:56:06 by albermud          #+#    #+#             */
/*   Updated: 2023/05/26 10:11:56 by albermud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line_bonus.h"

static char	*free_buffers(char **buffer, char *next_line, int free_result)
{
	free(*buffer);
	*buffer = NULL;
	if (free_result)
		free(next_line);
	return (NULL);
}

static char	*read_line(int fd, char **buffer, char *next_line, int *chars_read)
{
	while ((!ft_strchr(*buffer, '\n') && **buffer != *"") || **buffer == '\0')
	{
		next_line = ft_strjoin(next_line, *buffer, ft_strlen(*buffer) + 1);
		*chars_read = read(fd, *buffer, BUFFER_SIZE);
		(*buffer)[*chars_read] = 0;
		if (*chars_read < 0)
			return (free_buffers(buffer, next_line, 1));
		if (*chars_read == 0)
		{
			if (*next_line == *"")
				return (free_buffers(buffer, next_line, 1));
			return (next_line);
		}
	}
	if (ft_strchr(*buffer, '\n'))
	{
		next_line = ft_strjoin(next_line, *buffer, ft_strchr(*buffer, '\n')
				- *buffer + 2);
		ft_strlcpy(*buffer, ft_strchr(*buffer, '\n') + 1,
			ft_strlen(ft_strchr(*buffer, '\n')));
	}
	if (next_line == 0)
		return (free_buffers(buffer, next_line, 1));
	return (next_line);
}

char	*get_next_line(int fd)
{
	char		*next_line;
	static char	*buffer[FOPEN_MAX];
	int			chars_read;

	next_line = 0;
	chars_read = 0;
	if (fd < 0 || fd > FOPEN_MAX)
		return (NULL);
	if (!buffer[fd])
	{
		buffer[fd] = malloc((BUFFER_SIZE + 1) * sizeof(char));
		if (!buffer[fd])
			return (NULL);
		chars_read = read(fd, buffer[fd], BUFFER_SIZE);
		if (chars_read < 0)
			return (free_buffers(&(buffer[fd]), next_line, 0));
		buffer[fd][chars_read] = 0;
	}
	return (read_line(fd, &(buffer[fd]), next_line, &chars_read));
}

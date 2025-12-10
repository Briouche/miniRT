/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brcoppie <brcoppie@student.42belgium.be    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 14:38:21 by fkrakow           #+#    #+#             */
/*   Updated: 2025/12/10 13:27:50 by brcoppie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <fcntl.h>

static void	clean_buffer(char	*buffer, int new_line)
{
	int	n;

	n = 0;
	while (buffer[new_line])
		buffer[n++] = buffer[new_line++];
	buffer[n] = '\0';
}

static char	*append_to_line(char *line, char *to_append, int should_free)
{
	char	*tmp;

	if (line)
	{
		tmp = line;
		line = ft_strjoin(line, to_append);
		free(tmp);
		if (should_free)
			free(to_append);
	}
	else if (should_free)
		line = to_append;
	else
		line = ft_strdup(to_append);
	return (line);
}

static char	*process_new_line(char *line, char *buffer, char *new_line)
{
	char	*first_half;

	first_half = ft_strndup(buffer, new_line - buffer + 1);
	line = append_to_line(line, first_half, 1);
	clean_buffer(buffer, new_line - buffer + 1);
	return (line);
}

static char	*find_new_line(int fd, char *buffer, char *line, char *new_line)
{
	int		bytes_read;

	while (1)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(line);
			return (NULL);
		}
		if (bytes_read == 0)
			return (line);
		buffer[bytes_read] = '\0';
		new_line = ft_strchr(buffer, '\n');
		if (new_line)
			return (process_new_line(line, buffer, new_line));
		line = append_to_line(line, buffer, 0);
		buffer[0] = '\0';
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;
	char		*new_line_ptr;
	int			len;

	new_line_ptr = ft_strchr(buffer, '\n');
	if (new_line_ptr)
	{
		len = new_line_ptr - buffer + 1;
		line = ft_strndup(buffer, len);
		clean_buffer(buffer, len);
		return (line);
	}
	line = NULL;
	if (buffer[0] != '\0')
	{
		line = ft_strdup(buffer);
		if (!line)
			return (NULL);
		buffer[0] = '\0';
	}
	return (find_new_line(fd, buffer, line, new_line_ptr));
}

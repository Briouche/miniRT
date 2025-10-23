/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brcoppie <brcoppie@student.42belgium.be    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 12:52:56 by brcoppie          #+#    #+#             */
/*   Updated: 2025/10/23 19:16:30 by brcoppie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

int	check_filename(char *filename)
{
	int	len;

	len = ft_strlen(filename);
	if (len < 4)
		return (0);
	if (filename[len - 3] == '.' && filename[len - 2] == 'r' && \
				filename[len - 1] == 't')
		return (1);
	else
		return (0);
}

int	check_openread(char *filename)
{
	int		fd;
	char	buffer;
	int		bytes_read;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		perror("Error opening file");
		return (0);
	}
	bytes_read = read(fd, &buffer, 1);
	if (bytes_read == 0)
	{
		ft_putstr_fd("Error: empty file\n", 2);
		close(fd);
		return (0);
	}
	else if (bytes_read < 0)
	{
		perror("Error reading file");
		close(fd);
		return (0);
	}
	close(fd);
	return (1);
}

int	parsing(int ac, char **av)
{
	if (ac != 2)
	{
		ft_putstr_fd("Error: Usage: minirt <scene.rt>\n", 2);
		return (1);
	}
	else if (!check_filename(av[1]))
	{
		ft_putstr_fd("Error: expecting '.rt' file\n", 2);
		return (1);
	}
	else if (!check_openread(av[1]))
		return (1);
	return (0);
}

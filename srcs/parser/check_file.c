/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brcoppie <brcoppie@student.42belgium.be    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 16:52:57 by fkrakow           #+#    #+#             */
/*   Updated: 2025/12/03 13:52:38 by brcoppie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>

int	check_filename(const char *filename)
{
	int	len;

	len = ft_strlen(filename);
	if (len < 4)
		return (1);
	if (filename[len - 3] == '.' && filename[len - 2] == 'r'
		&& filename[len - 1] == 't')
		return (0);
	return (1);
}

int	check_openread(const char *filename)
{
	int		fd;
	int		read_status;
	char	buffer;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		perror("Error opening file");
		return (1);
	}
	read_status = read(fd, &buffer, 1);
	close(fd);
	if (!read_status)
		ft_putstr_fd("Error file is emtpy\n", 2);
	else if (read_status < 1)
		perror("Error reading file");
	else
		return (0);
	return (1);
}

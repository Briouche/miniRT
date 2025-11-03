/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrakow <fkrakow@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 12:52:56 by brcoppie          #+#    #+#             */
/*   Updated: 2025/11/03 15:50:22 by fkrakow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

int	check_filename(char *filename)
{
	int	len;

	len = ft_strlen(filename);
	if (len > 3 && filename[len - 3] == '.' && filename[len - 2] == 'r'
		&& filename[len - 1] == 't')
		return (1);
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

int	parse_scene(t_scene **scene, char *filename)
{
	int			fd;
	char		**line;
	t_obj_list	*objects;

	objects = NULL;
	fd = open(filename, O_RDONLY); //open 2
	if (fd < 0)
	{
		perror("Error opening file");
		return (0);
	}
	line = tokenize_line(fd);
	while (line != NULL)
	{
		if (line[0] && (line[0][0] != '\0'))
		{
			if (!parse_line(scene, &objects, line))
			{
				ft_free_tab(&line);
				close(fd);
				return (0);
			}
		}
		ft_free_tab(&line);
		line = tokenize_line(fd);
	}
	close(fd); // close 2
	return (1);
}

int	parsing(int ac, char *filename)
{
	t_scene	*scene;

	if (ac != 2)
	{
		ft_putstr_fd("Error: Usage: minirt <scene.rt>\n", 2);
		return (1);
	}
	else if (!check_filename(filename))
	{
		ft_putstr_fd("Error: expecting '.rt' file\n", 2);
		return (1);
	}
	else if (!check_openread(filename))
		return (1);
	scene = ft_calloc(1, sizeof(t_scene)); //malloc 1
	if (!scene)
		return (1);
	if (parse_scene(&scene, filename) == 0)
		//exit_free
		free(scene); //free 1
	free(scene);
	return (0);
}

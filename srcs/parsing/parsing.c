/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrakow <fkrakow@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 12:52:56 by brcoppie          #+#    #+#             */
/*   Updated: 2025/11/06 14:26:04 by fkrakow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

int	list_to_array(t_scene *scene, t_obj_list *objects)
{
	int			count;
	int			i;
	t_obj_list	*tmp;
	t_obj_list	*tmp2;

	i = 0;
	count = 0;
	tmp = objects;
	while (tmp && ++count)
		tmp = tmp->next;
	scene->objects = malloc(sizeof(t_object) * count);
	if (!scene->objects)
		return (print_error("Malloc failed\n"), 0);
	tmp = objects;
	while (tmp)
	{
		scene->objects[i++] = *(tmp->object);
		free(tmp->object);
		tmp2 = tmp->next;
		free(tmp);
		tmp = tmp2;
	}
	scene->count.obj_count = count;
	return (1);
}

static void	init_scene(t_scene *scene)
{
	scene->count.ambient_count = 0;
	scene->count.camera_count = 0;
	scene->count.light_count = 0;
	scene->count.obj_count = 0;
	scene->objects = NULL;
}

int	parse_scene(t_scene **scene, char *filename)
{
	int			fd;
	char		**line;
	t_obj_list	*objects;

	objects = NULL;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (perror("Error opening file"), 0);
	line = tokenize_line(fd);
	while (line != NULL)
	{
		if (line[0] && (line[0][0] != '\0'))
		{
			if (!parse_line(scene, &objects, line))
			{
				free_object_list(objects);
				ft_free_tab(&line);
				close(fd);
				return (0);
			}
		}
		ft_free_tab(&line);
		line = tokenize_line(fd);
	}
	if (!list_to_array(*scene, objects))
	{
		free_object_list(objects);
		ft_free_tab(&line);
		close(fd);
		return (0);
	}
	ft_free_tab(&line);
	close(fd);
	return (1);
}

int	parsing(int ac, char *filename, t_scene **scene)
{
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
	init_scene(*scene);
	if (!parse_scene(scene, filename))
		return (1);
	return (0);
}

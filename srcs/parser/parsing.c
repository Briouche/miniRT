/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrakow <fkrakow@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 12:52:56 by brcoppie          #+#    #+#             */
/*   Updated: 2025/11/12 15:46:30 by fkrakow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

static void	free_next(t_obj_list **tmp)
{
	t_obj_list	*next;

	free((*tmp)->object);
	next = (*tmp)->next;
	free(*tmp);
	*tmp = next;
}

int	list_to_array(t_obj_list *list, int size, t_object **objects)
{
	t_object	*array;
	t_obj_list	*tmp;
	int			n;

	tmp = list;
	array = malloc(sizeof(t_object) * size);
	if (!array)
	{
		while (tmp != NULL)
			free_next(&tmp);
		return (1);
	}
	n = -1;
	while (++n < size)
	{
		array[n] = *(tmp->object);
		free_next(&tmp);
	}
	*objects = array;
	return (0);
}

static int	check_filename(const char *filename)
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

static int	check_openread(const char *filename)
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

int	parsing(const char *filename, t_scene *scene)
{
	if (check_filename(filename))
	{
		ft_putstr_fd("Error: expecting '.rt' file\n", 2);
		return (1);
	}
	if (check_openread(filename))
		return (1);
	ft_memset(scene, 0, sizeof(t_scene));
	if (parse_scene(scene, filename))
		return (1);
	if (list_to_array(scene->objs_list, scene->size, &scene->objects))
	{
		ft_putstr_fd("Error: malloc failed while building objs", 2);
		return (1);
	}
	return (0);
}

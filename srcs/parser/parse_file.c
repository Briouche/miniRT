/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrakow <fkrakow@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 12:52:56 by brcoppie          #+#    #+#             */
/*   Updated: 2025/12/02 16:53:26 by fkrakow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structures.h"
#include <parser.h>

static void	free_next(t_obj_list **tmp)
{
	t_obj_list	*next;

	free((*tmp)->object);
	next = (*tmp)->next;
	free(*tmp);
	*tmp = next;
}

static void	free_obj_list(t_obj_list **tmp)
{
	while (*tmp != NULL)
		free_next(tmp);
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

int	parse_file(const char *filename, t_scene *scene)
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
	{
		free_obj_list(&scene->objs_list);
		return (1);
	}
	if (list_to_array(scene->objs_list, scene->size, &scene->objects))
	{
		ft_putstr_fd("Error: malloc failed while building objs", 2);
		return (1);
	}
	precompute_transforms(scene->objects, scene);
	return (0);
}

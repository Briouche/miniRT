/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_functions_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrakow <fkrakow@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 10:50:13 by fkrakow           #+#    #+#             */
/*   Updated: 2025/11/09 15:30:37 by fkrakow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

int	parse_ambient(t_scene **scene, char **line)
{
	if ((*scene)->count.ambient_count > 0)
		return (print_error("More than 1 ambient light\n"), 0);
	(*scene)->count.ambient_count++;
	if (!line[1] || !line[2] || line[3])
		return (print_error("Bad Ambient line\n"), 0);
	if (line[0][0] != 'A' || line[0][1])
		return (print_error("Bad Ambient line\n"), 0);
	(*scene)->ambient_light.ratio = ft_atod(line[1]);
	if ((*scene)->ambient_light.ratio > 1.0
		|| (*scene)->ambient_light.ratio < 0.0)
		return (print_error("Bad Ambient light ratio\n"), 0);
	if (!parse_color(line[2], &(*scene)->ambient_light.color))
		return (print_error("Bad Ambient light color\n"), 0);
	return (1);
}

int	parse_light(t_scene **scene, char **line)
{
	if ((*scene)->count.light_count > 0)
		return (print_error("More than 1 light\n"), 0);
	(*scene)->count.light_count++;
	if (!line[1] || !line[2] || !line[3] || line[4])
		return (print_error("Bad light line\n"), 0);
	if (line[0][0] != 'L' || line[0][1])
		return (print_error("Bad light line\n"), 0);
	if (!parse_point(line[1], &(*scene)->light.coord))
		return (print_error("Bad light coordinates\n"), 0);
	(*scene)->light.ratio = ft_atod(line[2]);
	if ((*scene)->light.ratio > 1.0 || (*scene)->light.ratio < 0.0)
		return (print_error("Bad light ratio\n"), 0);
	if (!parse_color(line[3], &(*scene)->light.color))
		return (print_error("Bad light color\n"), 0);
	return (1);
}

int	add_to_list(t_object *new_object, t_obj_list **objects)
{
	t_obj_list	*new_node;
	t_obj_list	*tmp;

	if (!objects || !new_object)
		return (0);
	new_node = malloc(sizeof(t_obj_list));
	if (!new_node)
		return (print_error("Malloc failed\n"), 0);
	new_node->object = new_object;
	new_node->next = NULL;
	if (!(*objects))
		*objects = new_node;
	else
	{
		tmp = *objects;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new_node;
	}
	return (1);
}

int	parse_sphere(t_obj_list **objects, char **line)
{
	t_object	*new_obj;

	new_obj = malloc(sizeof(t_object));
	if (!new_obj)
		return (print_error("Malloc failed\n"), 0);
	new_obj->type = SPHERE;
	if (!line[1] || !line[2] || !line[3] || line[4])
		return (print_error("Bad sphere\n"), free(new_obj), 0);
	if (!parse_point(line[1], &new_obj->obj.sp.c))
		return (print_error("Bad sphere\n"), free(new_obj), 0);
	new_obj->obj.sp.r = ft_atod(line[2]) / 2;
	if (new_obj->obj.sp.r == -DBL_MAX || new_obj->obj.sp.r <= 0.0)
		return (print_error("Bad sphere\n"), free(new_obj), 0);
	if (!parse_color(line[3], &new_obj->obj.sp.color))
		return (print_error("Bad sphere\n"), free(new_obj), 0);
	if (!add_to_list(new_obj, objects))
		return (print_error("Bad sphere\n"), free(new_obj), 0);
	return (1);
}

int	parse_plane(t_obj_list **objects, char **line)
{
	t_object	*new_obj;

	new_obj = malloc(sizeof(t_object));
	if (!new_obj)
		return (print_error("Malloc failed\n"), 0);
	new_obj->type = PLANE;
	if (!line[1] || !line[2] || !line[3] || line[4])
		return (print_error("Bad plane\n"), free(new_obj), 0);
	if (!parse_point(line[1], &new_obj->obj.pl.p))
		return (print_error("Bad plane\n"), free(new_obj), 0);
	if (!parse_vector(line[2], &new_obj->obj.pl.v) || \
		!is_normed_v(&new_obj->obj.pl.v))
		return (print_error("Bad plane\n"), free(new_obj), 0);
	if (!parse_color(line[3], &new_obj->obj.pl.color))
		return (print_error("Bad plane\n"), free(new_obj), 0);
	if (!add_to_list(new_obj, objects))
		return (print_error("Bad plane\n"), free(new_obj), 0);
	return (1);
}

int	parse_cylinder(t_obj_list **objects, char **line)
{
	t_object	*new_obj;

	new_obj = malloc(sizeof(t_object));
	if (!new_obj)
		return (print_error("Malloc failed\n"), 0);
	new_obj->type = CYLINDER;
	if (!line[1] || !line[2] || !line[3] || !line[4] || !line[5] || line[6])
		return (print_error("Bad cylinder\n"), free(new_obj), 0);
	if (!parse_point(line[1], &new_obj->obj.cy.c))
		return (print_error("Bad cylinder\n"), free(new_obj), 0);
	if (!parse_vector(line[2], &new_obj->obj.cy.v) || \
		!is_normed_v(&new_obj->obj.cy.v))
		return (print_error("Bad cylinder\n"), free(new_obj), 0);
	new_obj->obj.cy.diameter = ft_atod(line[3]);
	new_obj->obj.cy.height = ft_atod(line[4]);
	if (new_obj->obj.cy.diameter == -DBL_MAX || \
		new_obj->obj.cy.height == -DBL_MAX || \
		new_obj->obj.cy.diameter <= 0.0 || new_obj->obj.cy.height <= 0.0)
		return (print_error("Bad cylinder\n"), free(new_obj), 0);
	if (!parse_color(line[5], &new_obj->obj.cy.color))
		return (print_error("Bad cylinder\n"), free(new_obj), 0);
	if (!add_to_list(new_obj, objects))
		return (print_error("Bad cylinder\n"), free(new_obj), 0);
	return (1);
}

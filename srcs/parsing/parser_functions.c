/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brcoppie <brcoppie@student.42belgium.be    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 11:44:39 by brcoppie          #+#    #+#             */
/*   Updated: 2025/11/05 16:30:42 by brcoppie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

int	parse_point(char *str, t_point *p)
{
	char	**tokens;

	tokens = ft_split(str, ',');
	if (!tokens)
		return (0);
	if (!tokens[0] || !tokens[1] || !tokens[2] || tokens[3] || \
		!tokens[0][0] || !tokens[1][0] || !tokens[2][0])
		return (ft_free_tab(&tokens), 0);
	p->x = ft_atod(tokens[0]);
	p->y = ft_atod(tokens[1]);
	p->z = ft_atod(tokens[2]);
	if (p->x == -DBL_MAX || p->y == -DBL_MAX || p->z == -DBL_MAX)
		return (ft_free_tab(&tokens), 0);
	ft_free_tab(&tokens);
	return (1);
}

int	parse_vector(char *str, t_vec *v)
{
	char	**tokens;

	tokens = ft_split(str, ',');
	if (!tokens)
		return (0);
	if (!tokens[0] || !tokens[1] || !tokens[2] || tokens[3] || \
		!tokens[0][0] || !tokens[1][0] || !tokens[2][0])
		return (ft_free_tab(&tokens), 0);
	v->x = ft_atod(tokens[0]);
	v->y = ft_atod(tokens[1]);
	v->z = ft_atod(tokens[2]);
	if (v->x == -DBL_MAX || v->y == -DBL_MAX || v->z == -DBL_MAX)
		return (ft_free_tab(&tokens), 0);
	ft_free_tab(&tokens);
	return (1);
}

int	parse_color(char *str, t_colors *colors)
{
	char	**tokens;

	tokens = ft_split(str, ',');
	if (!tokens)
		return (0);
	if (!tokens[0] || !tokens[1] || !tokens[2] || tokens[3] || \
		!tokens[0][0] || !tokens[1][0] || !tokens[2][0])
		return (ft_free_tab(&tokens), 0);
	colors->R = ft_atoi(tokens[0]);
	colors->G = ft_atoi(tokens[1]);
	colors->B = ft_atoi(tokens[2]);
	ft_free_tab(&tokens);
	if (colors->R < 0 || colors->R > 255 \
		|| colors->G < 0 || colors->G > 255 \
		||colors->B < 0 || colors->B > 255)
		return (0);
	return (1);
}

int	is_normed_v(t_vec *vec)
{
	//!!!also check if magnitude == 1!!! sqrt(x² + y² + z²)
	if (vec->x > 1 || vec->x < -1 || vec->y > 1 || \
		vec->y < -1 || vec->z > 1 || vec->z < -1)
		return (0);
	else
		return (1);
}

int	parse_camera(t_scene **scene, char **line)
{
	if ((*scene)->count.camera_count > 0)
		return (print_error("More than 1 Camera\n"), 0);
	(*scene)->count.camera_count++;
	if (!line[1] || !line[2] || !line[3] || line[4])
		return (print_error("Bad Camera line\n"), 0);
	if (line[0][0] != 'C' || line[0][1])
		return (print_error("Bad Camera line\n"), 0);
	if (!parse_point(line[1], &(*scene)->cam.viewpoint))
		return (print_error("Bad Camera viewpoint\n"), 0);
	if (!parse_vector(line[2], &(*scene)->cam.orientation) || !is_normed_v(&(*scene)->cam.orientation))
		return (print_error("Bad Camera orientation\n"), 0);
	(*scene)->cam.fov = ft_atod(line[3]);
	if ((*scene)->cam.fov > 180 || (*scene)->cam.fov < 0)
		return (print_error("Bad Camera FOV\n"), 0);
	return (1);
}

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
	if ((*scene)->ambient_light.ratio > 1.0 || (*scene)->ambient_light.ratio < 0.0)
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
	if (!parse_point(line[1], &new_obj->obj.sp.center))
		return (print_error("Bad sphere\n"), free(new_obj), 0);
	new_obj->obj.sp.diameter = ft_atod(line[2]);
	if (new_obj->obj.sp.diameter == -DBL_MAX || new_obj->obj.sp.diameter <= 0.0)
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
	if (!parse_point(line[1], &new_obj->obj.cy.center))
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_shapes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrakow <fkrakow@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 10:50:13 by fkrakow           #+#    #+#             */
/*   Updated: 2025/11/12 15:13:12 by fkrakow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

static int	add_to_list(t_object *new_obj, t_obj_list **obj_list)
{
	t_obj_list	*tmp;

	tmp = malloc(sizeof(t_obj_list));
	if (!tmp)
		return (input_error("malloc failed", NULL));
	tmp->object = new_obj;
	tmp->next = *obj_list;
	*obj_list = tmp;
	return (0);
}

int	parse_sphere(t_obj_list **obj_list, int *size, char *const token[])
{
	t_object	*new_obj;

	new_obj = NULL;
	if (!token[1] || !token[2] || !token[3] || token[4])
		return (input_error("a sphere needs three arguments\n", new_obj));
	new_obj = malloc(sizeof(t_object));
	if (!new_obj)
		return (input_error("malloc failed\n", new_obj));
	new_obj->type = SPHERE;
	if (parse_point(token[1], &new_obj->obj.sp.c))
		return (input_error("invalid sphere center point\n", new_obj));
	new_obj->obj.sp.r = ft_atod(token[2]) / 2;
	if (new_obj->obj.sp.r == -DBL_MAX || new_obj->obj.sp.r <= 0.0)
		return (input_error("invalid sphere diameter, not > 0\n", new_obj));
	if (parse_color(token[3], &new_obj->obj.sp.color))
		return (input_error("invalid sphere color\n", new_obj));
	if (add_to_list(new_obj, obj_list))
		return (input_error("malloc failed\n", new_obj));
	*size += 1;
	return (0);
}

int	parse_plane(t_obj_list **obj_list, int *size, char *const *token)
{
	t_object	*new_obj;

	new_obj = NULL;
	if (!token[1] || !token[2] || !token[3] || token[4])
		return (input_error("a plane needs three arguments\n", new_obj));
	new_obj = malloc(sizeof(t_object));
	if (!new_obj)
		return (input_error("malloc failed\n", new_obj));
	new_obj->type = PLANE;
	if (parse_point(token[1], &new_obj->obj.pl.p))
		return (input_error("invalid plane point\n", new_obj));
	if (parse_vector(token[2], &new_obj->obj.pl.v)
		|| op_magnitude(&new_obj->obj.pl.v) > 1)
		return (input_error("invalid normal vector, needs to be normalised\n",
				new_obj));
	if (parse_color(token[3], &new_obj->obj.pl.color))
		return (input_error("invalid place color\n", new_obj));
	if (add_to_list(new_obj, obj_list))
		return (input_error("malloc failed\n", new_obj));
	*size += 1;
	return (0);
}

static int	parse_cylinder_bis(char *const token[],
t_object **new_obj)
{
	if (!token[1] || !token[2] || !token[3]
		|| !token[4] || !token[5] || token[6])
		return (input_error("cylinder needs five arguments\n", *new_obj));
	*new_obj = malloc(sizeof(t_object));
	if (!*new_obj)
		return (input_error("malloc failed\n", *new_obj));
	(*new_obj)->type = CYLINDER;
	if (parse_point(token[1], &(*new_obj)->obj.cy.c))
		return (input_error("invalid cylinder center point\n", *new_obj));
	if (parse_vector(token[2], &(*new_obj)->obj.cy.v)
		|| op_magnitude(&(*new_obj)->obj.cy.v) > 1)
		return (input_error("invalid cylinder axis vector, needs \
			to be normalised\n", *new_obj));
	return (0);
}

int	parse_cylinder(t_obj_list **obj_list, int *size, char *const token[])
{
	t_object	*new_obj;

	new_obj = NULL;
	if (parse_cylinder_bis(token, &new_obj))
		return (1);
	new_obj->obj.cy.diameter = ft_atod(token[3]);
	new_obj->obj.cy.height = ft_atod(token[4]);
	if (new_obj->obj.cy.diameter == -DBL_MAX
		|| new_obj->obj.cy.height == -DBL_MAX
		|| new_obj->obj.cy.diameter <= 0.0
		|| new_obj->obj.cy.height <= 0.0)
		return (input_error("invalid cylinder's diameter or height, \
			not > 0\n", new_obj));
	if (parse_color(token[5], &new_obj->obj.cy.color))
		return (input_error("invalid cylinder color\n", new_obj));
	if (add_to_list(new_obj, obj_list))
		return (input_error("malloc failed\n", new_obj));
	*size += 1;
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal_at.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brcoppie <brcoppie@student.42belgium.be    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 15:46:38 by brcoppie          #+#    #+#             */
/*   Updated: 2025/12/02 17:46:09 by brcoppie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

//using world space coordinates from parsing --> world space normal
//TRC (book) used object space and matrice transformations

static t_vector	normal_on_cylinder(t_object *obj, t_vector *p, t_ray *ray)
{
	t_vector	normal;
	t_vector	c_to_p;
	t_vector	axis_component;
	double		proj_on_axis;

	c_to_p = op_minus(p, &obj->obj.cy.c);
	proj_on_axis = op_dot(&c_to_p, &obj->obj.cy.v);
	axis_component = op_multi_scalar(&obj->obj.cy.v, proj_on_axis);
	normal = op_minus(&c_to_p, &axis_component);
	normal = op_normalise(&normal);
	if (op_dot(&normal, &ray->direction) > 0)
		normal = op_multi_scalar(&normal, -1);
	return (normal);
}

static t_vector	normal_on_plane(t_object *obj, t_ray *ray)
{
	if (op_dot(&ray->direction, &obj->obj.pl.v) > 0)
		return (op_multi_scalar(&obj->obj.pl.v, -1));
	return (obj->obj.pl.v);
}

static t_vector	normal_on_sphere(t_object *obj, t_vector *p, t_ray *ray)
{
	t_vector	normal;
	//t_vector	p_trnsf;
	//t_matrix	m;

	//p_trnsf = matrix_vector_multi(&obj->inv_tr, p);
	//normal = op_minus(&p_trnsf, &(t_vector){0, 0, 0, 1});
	//m = matrix_transpose(&obj->inv_tr);
	//normal = matrix_vector_multi(&m, &normal);
	normal = op_minus(p, &obj->obj.sp.c);
	normal = op_normalise(&normal);
	normal.w = 0;
	if (op_dot(&normal, &ray->direction) > 0)
		normal = op_multi_scalar(&normal, -1);
	return (normal);
}

t_vector	normal_at(t_object *obj, t_vector *p, t_ray *ray)
{
	if (obj->type == SPHERE)
		return (normal_on_sphere(obj, p, ray));
	else if (obj->type == PLANE)
		return (normal_on_plane(obj, ray));
	else if (obj->type == CYLINDER)
		return (normal_on_cylinder(obj, p, ray));
	else
		return ((t_vector){0, 0, 0, 0});
}

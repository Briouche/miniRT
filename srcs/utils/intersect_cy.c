/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_cy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brcoppie <brcoppie@student.42belgium.be    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 19:11:03 by brcoppie          #+#    #+#             */
/*   Updated: 2025/12/10 13:34:16 by brcoppie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <utils.h>

// find intersections of a cylinder and a ray
//	with
//		rv_comp = r.v⊥ ​= r.v - (r.v * cy.v) * cy.v
//		ro_comp = r.o⊥ ​= (r.o - cy.c) - ((r.o - cy.c) * cy.v) * cy.v
//		use op_perpendicular_comp()
//			a = ∥r.v⊥​∥²
//			b = 2(r.v⊥​ * r.o⊥​)
//			c = ∥r.o⊥​∥² - r²
//		discr = b² - 4ac
//use unit_cylinder with cy.c (0,0,0,1), cy.v (0,1,0,0), radius 1 and height 1
static double	discriminant_cy(t_ray *r, double *a)
{
	double		c;
	t_vector	rv_comp;
	t_vector	ro_comp;
	t_vector	d;

	d = op_minus(&r->origin, &(t_vector){0, 0, 0, 1});
	rv_comp = op_perpendicular_comp(&r->direction, &(t_vector){0, 1, 0, 0});
	ro_comp = op_perpendicular_comp(&d, &(t_vector){0, 1, 0, 0});
	(a[0]) = op_dot(&rv_comp, &rv_comp);
	(a[1]) = 2 * op_dot(&rv_comp, &ro_comp);
	c = op_dot(&ro_comp, &ro_comp) - 1;
	return (a[1] * a[1] - 4 * a[0] * c);
}

// Check if t_val is a valid intersection with the cylinder body bounds
// and updates the closest intersections in obj_inter.
static void	update_body_intersections(t_ray *r, t_inter_values *obj_inter,
double *a, double discr)
{
	double	t1;
	double	t2;
	double	y1;
	double	y2;

	t1 = (-a[1] - discr) / (2 * a[0]);
	t2 = (-a[1] + discr) / (2 * a[0]);
	y1 = r->origin.y + t1 * r->direction.y;
	y2 = r->origin.y + t2 * r->direction.y;
	if (y1 >= -0.5 && y1 <= 0.5)
		obj_inter->t1 = t1;
	if (y2 >= -0.5 && y2 <= 0.5)
	{
		if (obj_inter->t1 == INFINITY || t2 < obj_inter->t1)
		{
			obj_inter->t2 = obj_inter->t1;
			obj_inter->t1 = t2;
		}
		else
			obj_inter->t2 = t2;
	}
}

// Find intersections with the cylindrical body (excluding caps)
static void	intersect_body(t_ray *r, t_inter_values *obj_inter)
{
	double	a[2];
	double	discr;

	discr = discriminant_cy(r, a);
	if (discr >= 0)
		update_body_intersections(r, obj_inter, a, sqrt(discr));
}

// Main intersection function
// for intersections add: 	intersect_caps(&r, obj_inter);
int	intersect_cy(t_object *cy, t_ray *ray, t_inter_values *obj_inter)
{
	t_ray	r;

	r = transform_ray(ray, &cy->inv_tr);
	obj_inter->t1 = INFINITY;
	obj_inter->t2 = INFINITY;
	intersect_body(&r, obj_inter);
	return (obj_inter->t1 != INFINITY || obj_inter->t2 != INFINITY);
}

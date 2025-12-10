/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_cy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brcoppie <brcoppie@student.42belgium.be    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 19:11:03 by brcoppie          #+#    #+#             */
/*   Updated: 2025/12/09 15:44:25 by brcoppie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <utils.h>

static int	check_cap(t_ray *r, double t)
{
	double	x;
	double	z;

	x = r->origin.x + t * r->direction.x;
	z = r->origin.z + t * r->direction.z;
	return ((x * x + z * z) <= 1.0);
}

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
static double	discriminant_cy(t_ray *r, double *a, double *b)
{
	double		c;
	t_vector	rv_comp;
	t_vector	ro_comp;
	t_vector	d;

	d = op_minus(&r->origin, &(t_vector){0, 0, 0, 1});
	rv_comp = op_perpendicular_comp(&r->direction, &(t_vector){0, 1, 0, 0});
	ro_comp = op_perpendicular_comp(&d, &(t_vector){0, 1, 0, 0});
	(*a) = op_dot(&rv_comp, &rv_comp);
	(*b) = 2 * op_dot(&rv_comp, &ro_comp);
	c = op_dot(&ro_comp, &ro_comp) - 1;
	return ((*b) * (*b) - 4 * (*a) * c);
}

// Check if t_val is a valid intersection with the cylinder body bounds
// and updates the closest intersections in obj_inter.
static void	update_body_intersections(t_ray *r, t_inter_values *obj_inter,
		double a_val, double b_val, double discr)
{
	double	t1;
	double	t2;
	double	y1;
	double	y2;

	t1 = (-b_val - discr) / (2 * a_val);
	t2 = (-b_val + discr) / (2 * a_val);
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
	double	a;
	double	b;
	double	discr;

	discr = discriminant_cy(r, &a, &b);
	if (discr >= 0)
		update_body_intersections(r, obj_inter, a, b, sqrt(discr));
}

// Updates the closest intersection in obj_inter
// if t_cap is closer than t1 or t2
static void	set_cap_intersection(t_inter_values *obj_inter, double t_cap)
{
	if (t_cap < obj_inter->t1)
	{
		obj_inter->t2 = obj_inter->t1;
		obj_inter->t1 = t_cap;
	}
	else if (t_cap < obj_inter->t2)
		obj_inter->t2 = t_cap;
}

// Find intersections with the cylinder caps (y = 0.5 and y = -0.5 planes)
static void	intersect_caps(t_ray *r, t_inter_values *obj_inter)
{
	double	t_cap;

	if (fabs(r->direction.y) < 1e-6)
		return ;
	t_cap = (0.5 - r->origin.y) / r->direction.y;
	if (check_cap(r, t_cap))
		set_cap_intersection(obj_inter, t_cap);
	t_cap = (-0.5 - r->origin.y) / r->direction.y;
	if (check_cap(r, t_cap))
		set_cap_intersection(obj_inter, t_cap);
}

// Main intersection function
int	intersect_cy(t_object *cy, t_ray *ray, t_inter_values *obj_inter)
{
	t_ray	r;

	r = transform_ray(ray, &cy->inv_tr);
	obj_inter->t1 = INFINITY;
	obj_inter->t2 = INFINITY;
	intersect_body(&r, obj_inter);
	intersect_caps(&r, obj_inter);
	return (obj_inter->t1 != INFINITY || obj_inter->t2 != INFINITY);
}

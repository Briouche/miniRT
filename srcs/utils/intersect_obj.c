/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_obj.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brcoppie <brcoppie@student.42belgium.be    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 19:11:03 by brcoppie          #+#    #+#             */
/*   Updated: 2025/11/17 19:18:11 by brcoppie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <utils.h>

//find intersections of a sphere and a ray:
//	with 	l = ray.origin - sp.center
//			D = ray.direction
//			r = sp.radius
//		(D⋅D)t²+2(D⋅l)t+(l⋅l−r²)=0
//		at² + bt + c = 0
//		t = (−b +/- sqrt(Δ)) / 2

int	intersect_sp(t_sphere *sp, t_ray *r, t_intersec *obj_inter)
{
	double		a;
	double		b;
	double		c;
	t_vector	l;
	double		discr;

	l = op_minus(&r->origin, &sp->c);
	a = op_dot(&(r->direction), &(r->direction));
	b = 2 * op_dot(&(r->direction), &l);
	c = op_dot(&l, &l) - sp->r * sp->r;
	discr = b * b - 4 * a * c;
	if (discr < 0)
		return (0);
	obj_inter->t1 = (-b - sqrt(discr)) / (2 * a);
	obj_inter->t2 = (-b + sqrt(discr)) / (2 * a);
	return (1);
}

// find intersections of a plane and a ray
//				with pl = plane and r = ray:
//			t = (pl.v * (pl.p - r.o)) / (pl.v * r.v)

int	intersect_pl(t_plane *pl, t_ray *r, t_intersec *obj_inter)
{
	double	a;
	double	b;
	double	t;

	a = op_dot(&pl->v, &op_minus(&pl->p, &r->origin));
	b = op_dot(&pl->v, &r->direction);
	if (b == 0)
		return (0);
	t = a / b;
	obj_inter->t1 = t;
	obj_inter->t2 = t;
	return (1);
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
static double	discriminant_cy(t_cylinder *cy, t_ray *r, double *a, double *b)
{
	double		c;
	t_vector	rv_comp;
	t_vector	ro_comp;

	rv_comp = op_perpendicular_comp(r->direction, cy->v);
	ro_comp = op_perpendicular_comp(&op_minus(r->origin, cy->c), cy->v);
	(*a) = op_dot(&rv_comp, &rv_comp);
	(*b) = 2 * op_dot(&rv_comp, &ro_comp);
	c = op_dot(&ro_comp, &ro_comp) - cy->radius * cy->radius;
	return ((*b) * (*b) - 4 * (*a) * c);
}

int	intersect_cy(t_cylinder *cy, t_ray *r, t_intersec *obj_inter)
{
	double	discr;
	double	a;
	double	b;
	double	sqrt_discr;

	discr = discriminant_cy(cy, r, &a, &b);
	if (discr < 0)
		return (0);
	sqrt_discr = sqrt(discr);
	obj_inter->t1 = (-b - sqrt_discr) / (2 * a);
	obj_inter->t2 = (-b + sqrt_discr) / (2 * a);
	return (1);
}

int	obj_intersections(t_object *obj, t_ray *ray, t_intersec_info *inters)
{
	t_intersec	obj_inter;

	if (obj->type == SPHERE)
	{
		if (!intersect_sp(&obj->obj.sp, ray, &obj_inter))
			return (0);
	}
	else if (obj->type == PLANE)
	{
		if (!intersect_pl(&obj->obj.pl, ray, &obj_inter))
			return (0);
	}
	else if (obj->type == CYLINDER)
	{
		if (!intersect_cy(&obj->obj.cy, ray, &obj_inter))
			return (0);
	}
	inters[0].obj = obj;
	inters[0].t = obj_inter.t1;
	inters[1].obj = obj;
	inters[1].t = obj_inter.t2;
	return (2);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_obj.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brcoppie <brcoppie@student.42belgium.be    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 19:11:03 by brcoppie          #+#    #+#             */
/*   Updated: 2025/11/21 15:04:21 by brcoppie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <utils.h>

//find intersections of a sphere and a ray:
//	with 	l = ray.origin - sp.center
//			D = ray.direction
//			r = sp.radius
//		(D * D)t² + 2(D * l)t + (l * l - r²) = 0
//		at² + bt + c = 0
//		t = (-b +/- sqrt(Δ)) / 2
//use unit_sphere with vector {0, 0, 0} and r = 1 and transform ray
int	intersect_sp(t_object *sp, t_ray *ray, t_intersec *obj_inter)
{
	double		a;
	double		b;
	double		c;
	double		discr;
	t_ray		r;
	t_vector	d;

	r = transform_ray(ray, &sp->inv_tr);
	r.direction = op_normalise(&r.direction);
	d = op_minus(&r.origin, &(t_vector){0, 0, 0, 1});
	a = op_dot(&(r.direction), &(r.direction));
	b = 2 * op_dot(&(r.direction), &d);
	c = op_dot(&d, &d) - 1;
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
//use unit plane with pl.p (0,0,0,1) and pl.v (0,1,0,0)
int	intersect_pl(t_object *pl, t_ray *ray, t_intersec *obj_inter)
{
	double	a;
	double	b;
	double	t;
	t_vector	d;
	t_ray		r;

	r = transform_ray(ray, &pl->inv_tr);
	d = op_minus(&(t_vector){0, 0, 0, 1}, &r.origin);
	a = op_dot(&(t_vector){0, 1, 0, 0}, &d);
	b = op_dot(&(t_vector){0, 1, 0, 0}, &r.direction);
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

int	intersect_cy(t_object *cy, t_ray *ray, t_intersec *obj_inter)
{
	double	discr;
	double	a;
	double	b;
	double	sqrt_discr;
	t_ray	r;

	r = transform_ray(ray, &cy->inv_tr);
	discr = discriminant_cy(&r, &a, &b);
	if (discr < 0)
		return (0);
	sqrt_discr = sqrt(discr);
	obj_inter->t1 = (-b - sqrt_discr) / (2 * a);
	obj_inter->t2 = (-b + sqrt_discr) / (2 * a);

	a = r.origin.y + obj_inter->t1 * r.direction.y;
	b = r.origin.y + obj_inter->t2 * r.direction.y;
	if ((a > 0.5 || a < -0.5) && (b > 0.5 || b < -0.5))
		return (0);
	else if ((a > 0.5 || a < -0.5) && !(b > 0.5 || b < -0.5))
		obj_inter->t1 = obj_inter->t2;
	else if (!(a > 0.5 || a < -0.5) && (b > 0.5 || b < -0.5))
		obj_inter->t2 = obj_inter->t1;
	return (1);
}

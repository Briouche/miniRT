/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_obj.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brcoppie <brcoppie@student.42belgium.be    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 19:11:03 by brcoppie          #+#    #+#             */
/*   Updated: 2025/11/20 21:07:24 by brcoppie         ###   ########.fr       */
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
int	intersect_sp(t_sphere *sp, t_ray *ray, t_intersec *obj_inter)
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

int	intersect_pl(t_plane *pl, t_ray *r, t_intersec *obj_inter)
{
	double	a;
	double	b;
	double	t;
	t_vector	d;

	d = op_minus(&pl->p, &r->origin);
	a = op_dot(&pl->v, &d);
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
	t_vector	d;

	d = op_minus(&r->origin, &cy->c);
	rv_comp = op_perpendicular_comp(&r->direction, &cy->v);
	ro_comp = op_perpendicular_comp(&d, &cy->v);
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
	//add check for finite cylinder!!
	sqrt_discr = sqrt(discr);
	obj_inter->t1 = (-b - sqrt_discr) / (2 * a);
	obj_inter->t2 = (-b + sqrt_discr) / (2 * a);
	return (1);
}

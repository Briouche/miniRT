/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_sp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrakow <fkrakow@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 10:21:45 by fkrakow           #+#    #+#             */
/*   Updated: 2025/12/05 10:21:51 by fkrakow          ###   ########.fr       */
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
int	intersect_sp(t_object *sp, t_ray *ray, t_inter_values *obj_inter)
{
	double		a;
	double		b;
	double		c;
	t_ray		r;
	t_vector	d;

	r = transform_ray(ray, &sp->inv_tr);
	d = op_minus(&r.origin, &(t_vector){0, 0, 0, 1});
	a = op_dot(&(r.direction), &(r.direction));
	b = 2 * op_dot(&(r.direction), &d);
	c = op_dot(&d, &d) - 1;
	c = b * b - 4 * a * c;
	if (c < 0)
		return (0);
	c = sqrt(c);
	a *= 2;
	obj_inter->t1 = (-b - c) / a;
	obj_inter->t2 = (-b + c) / a;
	return (1);
}

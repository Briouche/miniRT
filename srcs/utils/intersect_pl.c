/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_pl.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrakow <fkrakow@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 10:22:00 by fkrakow           #+#    #+#             */
/*   Updated: 2025/12/05 10:22:01 by fkrakow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <utils.h>

// find intersections of a plane and a ray
//				with pl = plane and r = ray:
//			t = (pl.v * (pl.p - r.o)) / (pl.v * r.v)
//use unit plane with pl.p (0,0,0,1) and pl.v (0,1,0,0)
int	intersect_pl(t_object *pl, t_ray *ray, t_inter_values *obj_inter)
{
	double		a;
	double		b;
	double		t;
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

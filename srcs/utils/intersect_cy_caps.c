/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_cy_caps.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brcoppie <brcoppie@student.42belgium.be    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 13:16:27 by brcoppie          #+#    #+#             */
/*   Updated: 2025/12/10 13:34:22 by brcoppie         ###   ########.fr       */
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
void	intersect_caps(t_ray *r, t_inter_values *obj_inter)
{
	double	t_cap;

	if (fabs(r->direction.y) < EPSILON)
		return ;
	t_cap = (0.5 - r->origin.y) / r->direction.y;
	if (check_cap(r, t_cap))
		set_cap_intersection(obj_inter, t_cap);
	t_cap = (-0.5 - r->origin.y) / r->direction.y;
	if (check_cap(r, t_cap))
		set_cap_intersection(obj_inter, t_cap);
}

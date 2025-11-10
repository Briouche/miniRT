/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrakow <fkrakow@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 16:40:10 by fkrakow           #+#    #+#             */
/*   Updated: 2025/11/09 15:46:41 by fkrakow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <utils.h>

static void	find_points(double points[2], double a, double b)
{
	double	sqrt_discrim;

	sqrt_discrim = sqrt(a);
	points[0] = -b - sqrt_discrim;
	points[1] = -b + sqrt_discrim;
}

int	intersect(double points[2], t_sphere *sp, t_ray *r)
{
	double		a;
	double		b;
	double		c;
	t_vector	sp_origin;
	t_vector	r_dir;

	r_dir = r->direction;
	a = op_dot(&r_dir, &r_dir);
	sp_origin = (t_vector){sp->c.x, sp->c.y, sp->c.z, 0};
	b = 2 * op_dot(&r_dir, &sp_origin);
	c = op_dot(&sp_origin, &sp_origin) - 1;
	a = sqrt(b) - 4 * a * c;
	if (a < 0)
		return (0);
	find_points(points, a, b);
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadows.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brcoppie <brcoppie@student.42belgium.be    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 16:40:14 by brcoppie          #+#    #+#             */
/*   Updated: 2025/12/10 13:23:48 by brcoppie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

int	is_shadowed(t_inter *hit, t_scene *scene)
{
	t_ray		shadow_ray;
	t_vector	d;
	t_inter		shadow_hit;
	t_vector	c;
	double		distance;

	d = op_minus(&scene->light.coord, &hit->pos);
	distance = op_magnitude(&d);
	shadow_ray.direction = op_normalise(&d);
	c = op_multi_scalar(&shadow_ray.direction, EPSILON);
	shadow_ray.origin = op_plus(&hit->pos, &c);
	shadow_hit = find_hit(scene, &shadow_ray);
	if (shadow_hit.t == -1 || shadow_hit.t == INFINITY)
		return (0);
	else if (shadow_hit.t < distance)
		return (1);
	return (0);
}

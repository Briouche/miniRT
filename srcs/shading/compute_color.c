/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brcoppie <brcoppie@student.42belgium.be    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 17:03:12 by brcoppie          #+#    #+#             */
/*   Updated: 2025/12/02 17:43:53 by brcoppie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

t_vector	compute_final_color(t_scene *scene, t_intersec_info *hit, t_ray *r)
{
	t_vector	pos;
	t_vector	normalv;
	t_vector	color;

	hit->obj->mat.ambient = scene->ambient.ratio;
	hit->obj->mat.diffuse = scene->light.ratio;
	hit->obj->mat.specular = 0.9;
	hit->obj->mat.shininess = 100.0;
	if (hit->obj->type == SPHERE)
		hit->obj->mat.color = hit->obj->obj.sp.color;
	else if (hit->obj->type == PLANE)
		hit->obj->mat.color = hit->obj->obj.pl.color;
	else if (hit->obj->type == CYLINDER)
		hit->obj->mat.color = hit->obj->obj.cy.color;
	pos = op_multi_scalar(&r->direction, hit->t);
	pos = op_plus(&r->origin, &pos);
	normalv = normal_at(hit->obj, &pos, r);
	color = lighting(scene, &hit->obj->mat, &pos, &normalv);
	return (color);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brcoppie <brcoppie@student.42belgium.be    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 17:03:12 by brcoppie          #+#    #+#             */
/*   Updated: 2025/12/09 18:31:45 by brcoppie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

t_vector	compute_color(t_scene *scene, t_inter *hit, t_ray *ray)
{
	t_vector	normalv;
	t_vector	color;

	hit->obj->mat.ambient = scene->ambient.ratio;
	hit->obj->mat.diffuse = scene->light.ratio;
	hit->obj->mat.specular = 0.8;
	hit->obj->mat.shininess = 200.0;
	hit->obj->mat.color = hit->obj->color;
	hit->pos = position(ray, hit->t);
	hit->in_shadow = is_shadowed(hit, scene);
	normalv = normal_at(hit->obj, &hit->pos, ray);
	color = lighting(scene, hit, &normalv);
	return (color);
}

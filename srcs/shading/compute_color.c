/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brcoppie <brcoppie@student.42belgium.be    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 17:03:12 by brcoppie          #+#    #+#             */
/*   Updated: 2025/12/03 13:47:50 by brcoppie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

t_vector	compute_color(t_scene *scene, t_inter *hit, t_ray *r)
{
	t_vector	pos;
	t_vector	normalv;
	t_vector	color;

	hit->obj->mat.ambient = scene->ambient.ratio;
	hit->obj->mat.diffuse = scene->light.ratio;
	hit->obj->mat.specular = 0.9;
	hit->obj->mat.shininess = 100.0;
	hit->obj->mat.color = hit->obj->color;
	pos = position(r, hit->t);
	normalv = normal_at(hit->obj, &pos, r);
	color = lighting(scene, &hit->obj->mat, &pos, &normalv);
	return (color);
}

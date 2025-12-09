/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brcoppie <brcoppie@student.42belgium.be    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 12:28:49 by brcoppie          #+#    #+#             */
/*   Updated: 2025/12/09 18:34:13 by brcoppie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

static t_vector	reflect(t_vector *in, t_vector *normal)
{
	t_vector	tmp;

	tmp = op_multi_scalar(normal, 2 * op_dot(in, normal));
	return (op_minus(in, &tmp));
}

static t_vector	get_specular(t_scene *scene, t_light_info *light_info, \
						t_material *mat, t_vector *normalv)
{
	t_vector	specular;
	t_vector	reflectv;
	t_vector	inverse_lightv;
	double		fac_shininess;

	ft_memset(&specular, 0, sizeof(t_vector));
	inverse_lightv = op_multi_scalar(&light_info->lightv, -1);
	reflectv = reflect(&inverse_lightv, normalv);
	reflectv = op_normalise(&reflectv);
	light_info->reflect_dot_eye = op_dot(&reflectv, &light_info->eyev);
	if (light_info->reflect_dot_eye > 0 && light_info->light_dot_normal >= 0)
	{
		fac_shininess = pow(light_info->reflect_dot_eye, mat->shininess);
		specular = multi_scalar_colors(&scene->light.color, mat->specular);
		specular = multi_scalar_colors(&specular, fac_shininess);
	}
	return (specular);
}

static t_vector	get_diffuse(t_light_info *light_info,
		t_vector *normalv, t_scene *scene)
{
	t_vector	diffuse;

	ft_memset(&diffuse, 0, sizeof(t_vector));
	light_info->light_dot_normal = op_dot(&light_info->lightv, normalv);
	if (light_info->light_dot_normal >= 0)
	{
		diffuse = multi_scalar_colors(&light_info->effective_color,
				light_info->light_dot_normal * scene->light.ratio);
	}
	return (diffuse);
}

t_vector	compute_final_color(t_vector *diffuse,
		t_vector *ambient, t_vector *specular)
{
	t_vector	final_color;

	final_color = add_colors(ambient, diffuse);
	final_color = add_colors(&final_color, specular);
	final_color.x = fmin(fmax(final_color.x, 0), 255);
	final_color.y = fmin(fmax(final_color.y, 0), 255);
	final_color.z = fmin(fmax(final_color.z, 0), 255);
	return (final_color);
}

t_vector	lighting(t_scene *scene, t_inter *hit, t_vector *normalv)
{
	t_vector		ambient;
	t_vector		diffuse;
	t_vector		specular;
	t_light_info	light_info;

	light_info.effective_color = multi_colors(&hit->obj->mat.color,
			&scene->light.color);
	light_info.lightv = op_minus(&scene->light.coord, &hit->pos);
	light_info.lightv = op_normalise(&light_info.lightv);
	light_info.eyev = op_minus(&scene->cam.viewpoint, &hit->pos);
	light_info.eyev = op_normalise(&light_info.eyev);
	ambient = multi_colors(&hit->obj->mat.color, &scene->ambient.color);
	ambient = multi_scalar_colors(&ambient, hit->obj->mat.ambient);
	ft_memset(&diffuse, 0, sizeof(t_vector));
	ft_memset(&specular, 0, sizeof(t_vector));
	if (!hit->in_shadow)
	{
		diffuse = get_diffuse(&light_info, normalv, scene);
		specular = get_specular(scene, &light_info, &hit->obj->mat, normalv);
	}
	return (compute_final_color(&diffuse, &ambient, &specular));
}

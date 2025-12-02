/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brcoppie <brcoppie@student.42belgium.be    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 12:28:49 by brcoppie          #+#    #+#             */
/*   Updated: 2025/12/02 17:17:34 by brcoppie         ###   ########.fr       */
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
	light_info->reflect_dot_eye = op_dot(&reflectv, &light_info->eyev);
	if (light_info->reflect_dot_eye > 0 && light_info->light_dot_normal >= 0)
	{
		fac_shininess = pow(light_info->reflect_dot_eye, mat->shininess);
		specular = multi_scalar_colors(&scene->light.color, mat->specular);
		specular = multi_scalar_colors(&specular, fac_shininess);
	}
	return (specular);
}

static t_vector	get_diffuse(t_light_info *light_info, t_material *mat, \
						t_vector *normalv)
{
	t_vector	diffuse;

	ft_memset(&diffuse, 0, sizeof(t_vector));
	light_info->light_dot_normal = op_dot(&light_info->lightv, normalv);
	if (light_info->light_dot_normal >= 0)
	{
		diffuse = multi_scalar_colors(&light_info->effective_color, \
										mat->diffuse);
		diffuse = multi_scalar_colors(&diffuse, light_info->light_dot_normal);
	}
	return (diffuse);
}

t_vector	lighting(t_scene *scene, t_material *mat, \
					t_vector *pos, t_vector *normalv)
{
	t_vector		ambient;
	t_vector		diffuse;
	t_vector		specular;
	t_light_info	light_info;

	light_info.effective_color = multi_colors(&mat->color, &scene->light.color);
	light_info.lightv = op_minus(&scene->light.coord, pos);
	light_info.lightv = op_normalise(&light_info.lightv);
	light_info.eyev = op_minus(&scene->cam.viewpoint, pos);
	light_info.eyev = op_normalise(&light_info.eyev);

	ambient = multi_scalar_colors(&light_info.effective_color, mat->ambient);
	diffuse = get_diffuse(&light_info, mat, normalv);
	specular = get_specular(scene, &light_info, mat, normalv);

	light_info.final_color = add_colors(&ambient, &diffuse);
	light_info.final_color = add_colors(&light_info.final_color, &specular);
	return (light_info.final_color);
}

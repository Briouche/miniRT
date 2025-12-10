/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_lightning.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brcoppie <brcoppie@student.42belgium.be    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 18:10:11 by fkrakow           #+#    #+#             */
/*   Updated: 2025/12/10 13:32:57 by brcoppie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>

int	parse_ambient(t_scene *scene, char *const token[])
{
	if (scene->count.ambient_count)
		return (input_error("more than 1 ambient light\n", NULL));
	scene->count.ambient_count++;
	if (!token[1] || !token[2] || token[3])
		return (input_error("ambient light needs three arguments\n", NULL));
	scene->ambient.ratio = ft_atod(token[1]);
	if (scene->ambient.ratio < 0.0 || scene->ambient.ratio > 1.0)
		return (input_error("invalid ambient ration, not in [0.0; 0.1]\n",
				NULL));
	if (parse_color(token[2], &scene->ambient.color))
		return (input_error("invalid ambient light color\n", NULL));
	return (0);
}

int	parse_camera(t_scene *scene, char *const token[])
{
	if (scene->count.camera_count > 0)
		return (input_error("more than 1 camera\n", NULL));
	scene->count.camera_count++;
	if (!token[1] || !token[2] || !token[3] || token[4])
		return (input_error("camera needs four arguments\n", NULL));
	if (parse_point(token[1], &scene->cam.viewpoint))
		return (input_error("invalid viewpoint\n", NULL));
	if (parse_vector(token[2], &scene->cam.orientation)
		|| fabs(op_magnitude(&scene->cam.orientation) - 1) > EPSILON)
		return (input_error("invalid camera orientation, \
not a normalised vector\n", NULL));
	scene->cam.fov = ft_atod(token[3]);
	if (scene->cam.fov > 180 || scene->cam.fov < 0)
		return (input_error("invalid camera field of view, \
not in [0.0; 180]\n", NULL));
	return (0);
}

int	parse_light(t_scene *scene, char *const token[])
{
	if (scene->count.light_count > 0)
		return (input_error("more than 1 light\n", NULL));
	scene->count.light_count++;
	if (!token[1] || !token[2] || !token[3] || token[4])
		return (input_error("light needs four arguments\n", NULL));
	if (parse_point(token[1], &scene->light.coord))
		return (input_error("invalid light coordinates\n", NULL));
	scene->light.ratio = ft_atod(token[2]);
	if (scene->light.ratio > 1.0 || scene->light.ratio < 0.0)
		return (input_error("invalid light brightness, not in [0.0; 1.0]\n",
				NULL));
	if (parse_color(token[3], &scene->light.color))
		return (input_error("invalid light color\n", NULL));
	return (0);
}

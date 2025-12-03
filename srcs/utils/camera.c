/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brcoppie <brcoppie@student.42belgium.be    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 15:57:55 by brcoppie          #+#    #+#             */
/*   Updated: 2025/12/03 13:51:33 by brcoppie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <utils.h>
#include <display.h>

//	"normalized coordinates" --> from [800, 500] to [-1, 1] * aspect ratio
//		then apply fov
static double	calc_fx(int x, t_camera *cam)
{
	double	fx;

	fx = (2 * ((x + 0.5) / WIDTH) - 1);
	fx = fx * (tan((cam->fov * PI / 180) / 2));
	return (fx);
}

static double	calc_fy(int y, t_camera *cam)
{
	double	fy;
	double	aspect_ratio;

	aspect_ratio = (WIDTH / HEIGHT);
	fy = 2 * ((y + 0.5) / HEIGHT) - 1;
	fy = fy * (tan((cam->fov * PI / 180) / 2)) / aspect_ratio;
	return (fy);
}

//construct orthonormal basis for camera
//turn {x, y} (2D) into 3D

t_ray	generate_camera_ray(int x, int y, t_camera *cam)
{
	t_vector	right;
	t_vector	up;
	t_ray		ray;
	double		fx;
	double		fy;

	right = op_cross(&cam->orientation, &(t_vector){0, 1, 0, 0});
	right = op_normalise(&right);
	up = op_cross(&right, &cam->orientation);
	up = op_normalise(&up);
	fx = calc_fx(x, cam);
	fy = calc_fy(y, cam);
	right = op_multi_scalar(&right, fx);
	up = op_multi_scalar(&up, fy);
	ray.direction = op_plus(&cam->orientation, &right);
	ray.direction = op_plus(&ray.direction, &up);
	ray.direction = op_normalise(&ray.direction);
	ray.origin = cam->viewpoint;
	return (ray);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_cam_ray.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brcoppie <brcoppie@student.42belgium.be    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 15:57:55 by brcoppie          #+#    #+#             */
/*   Updated: 2025/12/10 16:49:34 by brcoppie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <utils.h>
#include <display.h>

//construct orthonormal basis for camera
//turn {x, y} (2D) into 3D
t_ray	generate_cam_ray(int x, int y, t_camera *cam)
{
	t_vector	right;
	t_vector	up;
	t_ray		ray;
	double		fx;
	double		fy;

	right = cam->right;
	up = cam->up;
	fx = (2 * ((x + 0.5) / WIDTH) - 1);
	fx *= cam->tan_fov;
	fy = (2 * ((y + 0.5) / HEIGHT) - 1);
	fy *= cam->tan2_fov;
	right = op_multi_scalar(&right, fx);
	up = op_multi_scalar(&up, fy);
	ray.direction = op_plus(&cam->orientation, &right);
	ray.direction = op_plus(&ray.direction, &up);
	ray.direction = op_normalise(&ray.direction);
	ray.origin = cam->viewpoint;
	return (ray);
}

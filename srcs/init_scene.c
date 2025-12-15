/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brcoppie <brcoppie@student.42belgium.be    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 10:28:20 by fkrakow           #+#    #+#             */
/*   Updated: 2025/12/10 16:57:25 by brcoppie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

static void	init_cam(t_camera *cam)
{
	t_vector	right;
	t_vector	up;
	double		aspect_ratio;

	if (fabs(cam->orientation.y) > 1 - EPSILON)
		right = (t_vector){.x = 0, .y = 0, .z = 1, .w = 0};
	else
		right = (t_vector){.x = 0, .y = 1, .z = 0, .w = 0};
	right = op_cross(&cam->orientation, &right);
	right = op_normalise(&right);
	cam->right = right;
	up = op_cross(&right, &cam->orientation);
	up = op_normalise(&up);
	cam->up = up;
	cam->tan2_fov = tan((cam->fov * PI / 180) * 0.5);
	aspect_ratio = (double)WIDTH / (double)HEIGHT;
	cam->tan_fov = cam->tan2_fov * aspect_ratio;
}

static int	init_intersections(t_inter **intersections, int size)
{
	*intersections = ft_calloc(size * 2, sizeof(t_inter));
	if (!*intersections)
		return (1);
	return (0);
}

int	init_scene(t_scene *scene)
{
	init_cam(&scene->cam);
	if (init_intersections((t_inter **)&scene->inters, scene->size))
		return (1);
	return (0);
}

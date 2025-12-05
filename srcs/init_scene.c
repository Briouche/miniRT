/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrakow <fkrakow@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 10:28:20 by fkrakow           #+#    #+#             */
/*   Updated: 2025/12/05 10:28:21 by fkrakow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

static void	init_cam(t_camera *cam)
{
	t_vector	right;
	t_vector	up;
	double		aspect_ratio;

	right = op_cross(&cam->orientation, &(t_vector){0, 1, 0, 0});
	right = op_normalise(&right);
	cam->right = right;
	up = op_cross(&right, &cam->orientation);
	up = op_normalise(&up);
	cam->up = up;
	cam->tan_fov = tan((cam->fov * PI / 180) / 2);
	aspect_ratio = WIDTH / HEIGHT;
	cam->tan2_fov = cam->tan_fov / aspect_ratio;
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

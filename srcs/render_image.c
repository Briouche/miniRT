/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brcoppie <brcoppie@student.42belgium.be    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 13:31:03 by fkrakow           #+#    #+#             */
/*   Updated: 2025/12/05 17:22:45 by brcoppie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

static int	ft_vtoi(t_vector *color)
{
	return (((int)(color->x) << 16) | ((int)(color->y) << 8) | (int)(color->z));
}

static int	cast_ray(int *coord, t_scene *scene)
{
	t_ray		ray;
	t_inter		hit;
	t_vector	color;

	ray = generate_cam_ray(coord[0], coord[1], &scene->cam);
	hit = find_hit(scene, &ray);
	if (hit.t == -1 || hit.t == INFINITY)
		color = (t_vector){0, 0, 0, 0};
	else
		color = compute_color(scene, &hit, &ray);
	if (coord[0] == 100 || coord[1] == 100)
		color = (t_vector){255,0,0,0};
	return (ft_vtoi(&color));
}

int	render_image(t_display *img, t_scene *scene)
{
	int		coord[2];
	int		img_n[2];
	char	*row;
	char	*pxl;

	if (init_scene(scene))
		return (1);
	img_n[0] = img->bits_per_pixel / 8;
	img_n[1] = img->size_line;
	coord[0] = -1;
	row = img->addr + (int)(HEIGHT - 1) *img_n[1];
	while (++coord[0] < HEIGHT)
	{
		pxl = row;
		coord[1] = -1;
		while (++coord[1] < WIDTH)
		{
			*(unsigned int *)pxl = cast_ray(coord, scene);
			pxl += img_n[0];
		}
		row -= img_n[1];
	}
	free(scene->inters);
	return (0);
}

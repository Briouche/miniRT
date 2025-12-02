/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3.chapter5.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrakow <fkrakow@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 14:15:40 by brcoppie          #+#    #+#             */
/*   Updated: 2025/12/02 17:03:33 by fkrakow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

t_inter	find_hit(t_scene *scene, t_ray *ray)
{
	t_inter	*inters;
	t_inter	res;
	int		i;
	int		hits;

	inters = ft_calloc(scene->size * 2, sizeof(t_inter));
	hits = ray_all_intersections(scene, ray, inters);
	i = the_hit(inters, scene);
	if (hits == 0 || i == -1)
	{
		inters[0].t = -1;
		res = inters[0];
		free(inters);
		return (res);
	}
	res = inters[i];
	free(inters);
	return (res);
}

static int	ft_vtoi(t_vector *color)
{
	return (((int)(color->x) << 16) | ((int)(color->y) << 8) | (int)(color->z));
}

void	put_pixel_to_image(t_display *display, int x, int y, t_vector *color)
{
	char	*pixel_address;

	pixel_address = display->addr + \
		(y * display->size_line + x * (display->bits_per_pixel / 8));
	*(unsigned int *)pixel_address = ft_vtoi(color);
}

void	sphere_silhouette(t_scene *scene, t_display *img)
{
	int				x;
	int				y;
	t_ray			ray;
	t_inter	hit;

	x = 0;
	y = 0;
	while (x < WIDTH)
	{
		while (y < HEIGHT)
		{
			ray = generate_camera_ray(x, y, &scene->cam);
			hit = find_hit(scene, &ray);
			if (hit.t != -1)
			{
				put_pixel_to_image(img, x, HEIGHT - y, &hit.obj->color);
			}
			y++;
		}
		y = 0;
		x++;
	}
}



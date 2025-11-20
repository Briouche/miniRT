/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chapter5.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brcoppie <brcoppie@student.42belgium.be    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 14:15:40 by brcoppie          #+#    #+#             */
/*   Updated: 2025/11/20 20:57:32 by brcoppie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

t_intersec_info	find_hit(t_scene *scene, t_ray *ray)
{
	t_intersec_info	inters[scene->size * 2];
	int				i;
	int				hits;

	hits = ray_all_intersections(scene, ray, inters);
	i = the_hit(inters, scene);
	if (hits == 0)
	{
		inters[0].t = 2147483647;
		return (inters[0]);
	}
	return (inters[i]);
}

void	sphere_silhouette(t_scene *scene, t_display *img, t_vector *color)
{
	int				x;
	int				y;
	t_ray			ray;
	t_intersec_info	hit;

	x = 0;
	y = 0;
	while (x < WIDTH)
	{
		while (y < HEIGHT)
		{
			ray = generate_camera_ray(x, y, &scene->cam);
			hit = find_hit(scene, &ray);
			if (hit.t < 2147483646)
			{
				put_pixel_to_image(img, x, HEIGHT - y, color);
			}
			y++;
		}
		y = 0;
		x++;
	}
}



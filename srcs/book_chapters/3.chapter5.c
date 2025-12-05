/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3.chapter5.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brcoppie <brcoppie@student.42belgium.be    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 14:15:40 by brcoppie          #+#    #+#             */
/*   Updated: 2025/12/03 14:01:17 by brcoppie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

// static t_inter	find_hit(t_scene *scene, t_ray *ray)
// {
// 	t_inter	*inters;
// 	t_inter	res;
// 	int		i;
// 	int		hits;

// 	inters = ft_calloc(scene->size * 2, sizeof(t_inter));
// 	hits = ray_intersect_objs(scene, ray, inters);
// 	i = the_hit(inters, scene);
// 	if (hits == 0 || i == -1)
// 	{
// 		inters[0].t = -1;
// 		res = inters[0];
// 		free(inters);
// 		return (res);
// 	}
// 	res = inters[i];
// 	free(inters);
// 	return (res);
// }

// static int	ft_vtoi(t_vector *color)
// {
// 	return (((int)(color->x) << 16) | ((int)(color->y) << 8) | (int)(color->z));
// }

// void	put_pixel_to_image(t_display *display, int x, int y, t_vector *color)
// {
// 	char	*pixel_address;

// 	pixel_address = display->addr + \
// 		(y * display->size_line + x * (display->bits_per_pixel / 8));
// 	*(unsigned int *)pixel_address = ft_vtoi(color);
// }

// void	sphere_silhouette(t_scene *scene, t_display *img)
// {
// 	int			x;
// 	int			y;
// 	t_ray		ray;
// 	t_inter		hit;
// 	t_vector	color;

// 	x = 0;
// 	y = 0;
// 	while (x < WIDTH)
// 	{
// 		while (y < HEIGHT)
// 		{
// 			ray = generate_camera_ray(x, y, &scene->cam);
// 			hit = find_hit(scene, &ray);
// 			if (hit.t != -1)
// 			{
// 				color = compute_color(scene, &hit, &ray);
// 				put_pixel_to_image(img, x, HEIGHT - y, &color);
// 			}
// 			y++;
// 		}
// 		y = 0;
// 		x++;
// 	}
// }

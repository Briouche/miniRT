/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brcoppie <brcoppie@student.42belgium.be    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 13:31:03 by fkrakow           #+#    #+#             */
/*   Updated: 2025/11/20 19:11:02 by brcoppie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

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

int	render_image(t_display *img, t_scene *scene)
{
	t_vector	color;
	double		r;
	double		g;
	double		b;

	r = 155;
	g = 195;
	b = 200;
	color = vec_color(r, g, b);
	sphere_silhouette(scene, img, &color);
	return (0);
}

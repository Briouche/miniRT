/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrakow <fkrakow@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 13:31:03 by fkrakow           #+#    #+#             */
/*   Updated: 2025/11/10 11:37:31 by fkrakow          ###   ########.fr       */
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

int	render_image(t_display *img)
{
	t_vector	color;
	double		r;
	double		g;
	double		b;

	r = 255;
	g = 0;
	b = 0;
	// color = vec_color(&r, &g, &b);
	// cannon_ball(img, &color);
	color = vec_color(r, g, b);
	draw_clock(img, &color);
	return (0);
}

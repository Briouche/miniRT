/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrakow <fkrakow@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 13:31:03 by fkrakow           #+#    #+#             */
/*   Updated: 2025/10/31 15:16:19 by fkrakow          ###   ########.fr       */
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

	pixel_address = display->addr + (y * display->size_line + x * (display->bits_per_pixel / 8));
	*(unsigned int *)pixel_address = ft_vtoi(color);
}

int	render_image(t_display *img)
{
	t_vector	red;

	double	r = 255;
	double	g = 0;
	double	b = 0;
	red = vec_color(&r, &g, &b);

	cannon_ball(img, &red);	
	return (0);
}
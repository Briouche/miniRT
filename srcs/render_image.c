/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrakow <fkrakow@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 13:31:03 by fkrakow           #+#    #+#             */
/*   Updated: 2025/10/29 13:50:15 by fkrakow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

static void	put_pixel_to_image(t_display *display, int x, int y, int color)
{
	char	*pixel_address;

	pixel_address = display->addr + (y * display->size_line + x * (display->bits_per_pixel / 8));
	*(unsigned int *)pixel_address = color;
}

int	render_image(t_display *img)
{
	int	x;
	int	y;
	int	color;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			int r = (x * 255) / WIDTH;
			int g = (y * 255) / HEIGHT;
			int b = 0;
			color = (r << 16) | (g << 8) | b;
			put_pixel_to_image(img, x, y, color);
			x++;
		}
		y++;
	}
	return (0);
}
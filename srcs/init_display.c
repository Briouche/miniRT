/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_display.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrakow <fkrakow@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 13:22:23 by fkrakow           #+#    #+#             */
/*   Updated: 2025/10/29 13:39:46 by fkrakow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

int	init_display(t_display *display)
{
	display->mlx_ptr = mlx_init();
	if (!display->mlx_ptr)
		return (1);
	display->mlx_win = mlx_new_window(display->mlx_ptr, WIDTH, HEIGHT, "miniRT");
	if (!display->mlx_win)
	{
		return (1);
	}
	display->mlx_img = mlx_new_image(display->mlx_ptr, WIDTH, HEIGHT);
	if (!display->mlx_img)
	{
		return (1);
	}
	display->addr = mlx_get_data_addr(display->mlx_img, &display->bits_per_pixel,
		&display->size_line, &display->endian);
	return (0);
}

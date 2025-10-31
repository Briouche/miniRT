/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_loop.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrakow <fkrakow@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 11:20:46 by fkrakow           #+#    #+#             */
/*   Updated: 2025/10/31 14:32:21 by fkrakow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

#include <X11/X.h>
#include <X11/keysym.h>

static int	exit_program(t_display *display)
{
	mlx_destroy_image(display->mlx_ptr, display->mlx_img);
	mlx_destroy_window(display->mlx_ptr, display->mlx_win);
	// mlx_destroy_display(display->mlx_ptr); // only for linux, necessary for Valgrind but no in the man
	free(display->mlx_ptr); // here too, necessary for Valgrind but not in the man
	exit(0);
}

static int	handle_key(int key, t_display *display)
{
	if (key == XK_Escape || key == 53)
		exit_program(display);
	return (0);
}

void	display_loop(t_display *display)
{
	mlx_put_image_to_window(display->mlx_ptr, display->mlx_win, display->mlx_img, 0, 0);
	mlx_key_hook(display->mlx_win, handle_key, display);
	mlx_hook(display->mlx_win, DestroyNotify, StructureNotifyMask, exit_program, display);
	mlx_loop(display->mlx_ptr);
}
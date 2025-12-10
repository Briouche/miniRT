/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brcoppie <brcoppie@student.42belgium.be    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 13:01:26 by fkrakow           #+#    #+#             */
/*   Updated: 2025/12/10 13:18:39 by brcoppie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISPLAY_H
# define DISPLAY_H

# include <mlx.h>
# include "structures.h"

# define WIDTH 800.0
# define HEIGHT 800.0

typedef struct s_display
{
	void	*mlx_ptr;
	void	*mlx_win;
	void	*mlx_img;
	char	*addr;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
}	t_display;

int		init_display(t_display *display);
int		render_image(t_display *img, t_scene *scene);
void	display_loop(t_display *display);

int		exit_program(t_display *display);

#endif

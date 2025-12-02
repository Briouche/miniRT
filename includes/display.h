/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrakow <fkrakow@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 13:01:26 by fkrakow           #+#    #+#             */
/*   Updated: 2025/12/02 17:54:36 by fkrakow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISPLAY_H
# define DISPLAY_H

# include <mlx.h>
# include "../vectors/vectors.h"

# define WIDTH 800
# define HEIGHT 800

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

void	put_pixel_to_image(t_display *display, int x, int y, t_vector *color);

int		init_display(t_display *display);
int		render_image(t_display *img, t_scene *scene);
void	display_loop(t_display *display);

#endif

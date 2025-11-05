/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_clock.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrakow <fkrakow@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 17:17:24 by fkrakow           #+#    #+#             */
/*   Updated: 2025/11/05 17:48:15 by fkrakow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

int	draw_clock(t_display *img, t_vector *white)
{
	t_matrix	trans;
	t_vector	vec;
	t_vector	new_vec;
	double		angle;
	int			n;
	t_matrix	rotation;
	t_matrix	scale;
	t_matrix	translate;
	
	vec = point(&(double){0}, &(double){1}, &(double){0});
	scale = trsfrm_scale(&(double){3.0 / 8.0 * HEIGHT},
		&(double){3.0 / 8.0 * HEIGHT}, &(double){1});
	translate = trsfrm_translate(&(double){HEIGHT / 2.0}, &(double){HEIGHT / 2.0}, &(double){0});
	n = -1;
	while (++n < 3600)
	{
		angle = n * (M_PI / 1800);
		rotation = trsfrm_rotate_z(&angle);
		trans = matrices_multiply(&scale, &rotation);
		trans = matrices_multiply(&translate, &trans);
		new_vec = matrix_vector_multi(&trans, &vec);
		put_pixel_to_image(img, (int)new_vec.x + (WIDTH / 5), (int)new_vec.y, white);
	}
	return (0);
}
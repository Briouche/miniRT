/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_clock.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrakow <fkrakow@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 17:17:24 by fkrakow           #+#    #+#             */
/*   Updated: 2025/11/06 14:08:04 by fkrakow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

// trans[0] = total
// trans[1] = rotation
// trans[2] = scale
// trans[3] = translate

int	draw_clock(t_display *img, t_vector *white)
{
	t_matrix	trans[4];
	t_vector	vec;
	t_vector	new_vec;
	double		angle;
	int			n;

	vec = point(&(double){0}, &(double){1}, &(double){0});
	trans[2] = trsfrm_scale(&(double){3.0 / 8.0 * HEIGHT},
			&(double){3.0 / 8.0 * HEIGHT}, &(double){1});
	trans[3] = trsfrm_translate(&(double){HEIGHT / 2.0},
			&(double){HEIGHT / 2.0}, &(double){0});
	n = -1;
	while (++n < 3600)
	{
		angle = n * (M_PI / 1800);
		trans[1] = trsfrm_rotate_z(&angle);
		trans[0] = matrices_multiply(&trans[2], &trans[1]);
		trans[0] = matrices_multiply(&trans[3], &trans[0]);
		new_vec = matrix_vector_multi(&trans[0], &vec);
		put_pixel_to_image(img,
			(int)new_vec.x + (WIDTH / 5), (int)new_vec.y, white);
	}
	return (0);
}

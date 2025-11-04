/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_minor.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrakow <fkrakow@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 10:19:54 by fkrakow           #+#    #+#             */
/*   Updated: 2025/11/04 12:41:17 by fkrakow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vectors.h"

double	matrix_minor(t_matrix *m, int r, int c, int d)
{
	t_matrix	sub;
	int			sub_size;
	t_vector	sub_vec;

	sub = matrix_reduce(m, r, c);
	sub_size = d - 1;
	if (sub_size == 2)
	{
		sub_vec = (t_vector){sub.c1.x, sub.c2.x, sub.c1.y, sub.c2.y};
		return (matrix_det_d2(&sub_vec));
	}
	else
		return (matrix_determinant(&sub, sub_size));
}

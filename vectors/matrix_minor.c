/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_minor.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrakow <fkrakow@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 10:19:54 by fkrakow           #+#    #+#             */
/*   Updated: 2025/11/10 11:32:44 by fkrakow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vectors.h"

double	matrix_minor(const t_matrix *m, const int r, const int c, const int d)
{
	const t_matrix	sub = matrix_reduce(m, r, c);
	const int		sub_size = d - 1;
	t_vector		sub_vec;

	if (sub_size == 2)
	{
		sub_vec = (t_vector){sub.c1.x, sub.c2.x, sub.c1.y, sub.c2.y};
		return (matrix_det_d2(&sub_vec));
	}
	else
		return (matrix_determinant(&sub, sub_size));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_inverse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrakow <fkrakow@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 14:15:23 by fkrakow           #+#    #+#             */
/*   Updated: 2025/11/05 13:03:21 by fkrakow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vectors.h"

t_matrix	matrix_inverse(t_matrix *m)
{
	t_matrix	inversed;
	double		det;

	det = matrix_determinant(m, 4);
	if (!det)
		return ((t_matrix){(t_vector){0, 0, 0, 0}, (t_vector){0, 0, 0, 0},
		(t_vector){0, 0, 0, 0}, (t_vector){0, 0, 0, 0}});
	inversed.c1.x = matrix_cofactor(m, 0, 0, 4) / det;
	inversed.c1.y = matrix_cofactor(m, 0, 1, 4) / det;
	inversed.c1.z = matrix_cofactor(m, 0, 2, 4) / det;
	inversed.c1.w = matrix_cofactor(m, 0, 3, 4) / det;
	inversed.c2.x = matrix_cofactor(m, 1, 0, 4) / det;
	inversed.c2.y = matrix_cofactor(m, 1, 1, 4) / det;
	inversed.c2.z = matrix_cofactor(m, 1, 2, 4) / det;
	inversed.c2.w = matrix_cofactor(m, 1, 3, 4) / det;
	inversed.c3.x = matrix_cofactor(m, 2, 0, 4) / det;
	inversed.c3.y = matrix_cofactor(m, 2, 1, 4) / det;
	inversed.c3.z = matrix_cofactor(m, 2, 2, 4) / det;
	inversed.c3.w = matrix_cofactor(m, 2, 3, 4) / det;
	inversed.c4.x = matrix_cofactor(m, 3, 0, 4) / det;
	inversed.c4.y = matrix_cofactor(m, 3, 1, 4) / det;
	inversed.c4.z = matrix_cofactor(m, 3, 2, 4) / det;
	inversed.c4.w = matrix_cofactor(m, 3, 3, 4) / det;
	return (inversed);
}
